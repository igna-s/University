#include <WiFi.h>
#include <WebSocketsServer.h>
#include <time.h>
#include <sys/time.h>


#include "esp_camera.h"
#include "esp_http_server.h"

const char* SSID = "Pupi";
const char* PASS = "44487105az";

static const uint32_t EDU_BAUD = 115200; 


WebSocketsServer ws(81);              


static const int UART_LINE_MAX = 128;
char lineBuf[UART_LINE_MAX];
int lineLen = 0;

static bool timeOk = false;

void syncTimeNtp() {
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");

  time_t now = 0;
  for (int i = 0; i < 30; i++) {
    time(&now);
    if (now > 1700000000) {
      timeOk = true;
      Serial.println("DBG NTP_OK");
      return;
    }
    delay(200);
  }
  Serial.println("DBG NTP_FAIL");
}

uint64_t nowMs() {
  struct timeval tv;
  gettimeofday(&tv, nullptr);
  return (uint64_t)tv.tv_sec * 1000ULL + (uint64_t)(tv.tv_usec / 1000ULL);
}


enum HistTipo : uint8_t { H_NONE = 0, H_ARMADA = 1, H_DESARMADA = 2, H_DISPARO = 3 };

struct HistEntry {
  uint64_t t;
  uint8_t tipo;
  uint8_t zona; 
};

static const int HIST_MAX = 120;
HistEntry hist[HIST_MAX];
int histCount = 0;
int histHead = 0; 

uint8_t lastTipo = H_NONE;

void pushHistory(uint8_t tipo, uint8_t zona) {
  if (tipo == H_NONE) return;
  if (tipo == lastTipo) return; 

  HistEntry e;
  e.t = nowMs();
  e.tipo = tipo;
  e.zona = zona;

  hist[histHead] = e;
  histHead = (histHead + 1) % HIST_MAX;
  if (histCount < HIST_MAX) histCount++;

  lastTipo = tipo;
}

const char* tipoToStr(uint8_t tipo) {
  if (tipo == H_ARMADA) return "ARMADA";
  if (tipo == H_DESARMADA) return "DESARMADA";
  if (tipo == H_DISPARO) return "DISPARO";
  return "UNK";
}

void sendHistoryToClient(uint8_t client) {
  String out = "{\"type\":\"HIST\",\"items\":[";
  for (int i = 0; i < histCount; i++) {
    // newest first
    int idx = (histHead - 1 - i);
    while (idx < 0) idx += HIST_MAX;
    idx %= HIST_MAX;

    const HistEntry &e = hist[idx];
    out += "{\"tipo\":\"";
    out += tipoToStr(e.tipo);
    out += "\"";

    if (e.tipo == H_DISPARO) {
      out += ",\"zona\":";
      out += String((int)e.zona);
    }

    out += ",\"t\":";
    out += String((unsigned long long)e.t);
    out += "}";

    if (i != histCount - 1) out += ",";
  }
  out += "]}";

  ws.sendTXT(client, out);
}


// UART
void initUart() {
  Serial.begin(EDU_BAUD);
  lineLen = 0;
  lineBuf[0] = '\0';
  Serial.println("DBG BOOT");
}


// WiFi
void connectWifi() {
  Serial.println("DBG WIFI_CONNECTING");

  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);
  WiFi.begin(SSID, PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.println("DBG WIFI_WAIT");
  }

  Serial.println("DBG WIFI_OK");
  Serial.print("DBG IP ");
  Serial.println(WiFi.localIP());

  syncTimeNtp();
}


// WebSocket
void forwardAppToEduciaa(const uint8_t* payload, size_t len) {
  if (!payload || len == 0) return;

  Serial.write(payload, len);
  if (((char)payload[len - 1]) != '\n') Serial.write('\n');
}

void onWsEvent(uint8_t client, WStype_t type, uint8_t* payload, size_t len) {
  if (type == WStype_CONNECTED) {
    Serial.print("DBG WS_CONNECTED ");
    Serial.println(ws.remoteIP(client));
    return;
  }
  if (type == WStype_DISCONNECTED) {
    Serial.println("DBG WS_DISCONNECTED");
    return;
  }
  if (type == WStype_TEXT) {
    String cmd;
    cmd.reserve(len + 1);
    for (size_t i = 0; i < len; i++) cmd += (char)payload[i];
    cmd.trim();


    if (cmd.equalsIgnoreCase("HIST")) {
      Serial.println("DBG HIST_REQ");
      sendHistoryToClient(client);
      return;
    }


    forwardAppToEduciaa(payload, len);
  }
}

void startWebSocket() {
  ws.begin();
  ws.onEvent(onWsEvent);
  Serial.println("DBG WS_READY 81");
}

void wsLoop() { ws.loop(); }


bool parseStatusLine(const char* line, char* estadoOut, int* maskEnOut, int* maskActOut, int* zonaOut) {
  if (!line || !estadoOut || !maskEnOut || !maskActOut || !zonaOut) return false;
  return (sscanf(line, "%31s %d %d %d", estadoOut, maskEnOut, maskActOut, zonaOut) == 4);
}

void sendStatusJsonToApp(const char* estado, int maskEn, int maskAct, int zona) {
  char json[160];
  snprintf(json, sizeof(json),
           "{\"estado\":\"%s\",\"mask_enable\":%d,\"mask_active\":%d,\"disparo_zona\":%d}",
           estado, maskEn, maskAct, zona);
  ws.broadcastTXT(json);
}

uint8_t estadoToHistTipo(const char* estado) {
  if (!estado) return H_NONE;
  String s = String(estado);
  s.trim();
  s.toUpperCase();

  if (s.startsWith("ARMAD")) return H_ARMADA;
  if (s.startsWith("DESARM")) return H_DESARMADA;
  if (s.startsWith("DISPAR")) return H_DISPARO;

  return H_NONE;
}

void handleEduciaaLine(const char* line) {
  char estado[32];
  int maskEn = 0, maskAct = 0, zona = 0;

  if (parseStatusLine(line, estado, &maskEn, &maskAct, &zona)) {
    sendStatusJsonToApp(estado, maskEn, maskAct, zona);

    uint8_t tipo = estadoToHistTipo(estado);
    if (tipo == H_ARMADA) pushHistory(H_ARMADA, 0);
    else if (tipo == H_DESARMADA) pushHistory(H_DESARMADA, 0);
    else if (tipo == H_DISPARO) {
      uint8_t z = (zona < 0) ? 0 : (zona > 255 ? 255 : (uint8_t)zona);
      pushHistory(H_DISPARO, z);
    }
  }
}

void uartLoop() {
  while (Serial.available()) {
    char c = (char)Serial.read();
    if (c == '\r') continue;

    if (c == '\n') {
      if (lineLen > 0) {
        lineBuf[lineLen] = '\0';
        handleEduciaaLine(lineBuf);
      }
      lineLen = 0;
      continue;
    }

    if (lineLen < UART_LINE_MAX - 1) {
      lineBuf[lineLen++] = c;
    } else {
      lineLen = 0;
    }
  }
}


//CAMARA

#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

static httpd_handle_t cam_httpd = NULL;

static esp_err_t capture_handler(httpd_req_t *req) {
  camera_fb_t * fb = esp_camera_fb_get();
  if (!fb) {
    httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "CAMERA_FB_FAIL");
    return ESP_FAIL;
  }

  httpd_resp_set_type(req, "image/jpeg");
  httpd_resp_set_hdr(req, "Cache-Control", "no-store");
  httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");

  esp_err_t res = httpd_resp_send(req, (const char *)fb->buf, fb->len);
  esp_camera_fb_return(fb);
  return res;
}

static const char* STREAM_CONTENT_TYPE = "multipart/x-mixed-replace;boundary=frame";
static const char* STREAM_BOUNDARY = "\r\n--frame\r\n";
static const char* STREAM_PART = "Content-Type: image/jpeg\r\nContent-Length: %u\r\n\r\n";

static esp_err_t stream_handler(httpd_req_t *req) {
  esp_err_t res = httpd_resp_set_type(req, STREAM_CONTENT_TYPE);
  if (res != ESP_OK) return res;

  httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");
  httpd_resp_set_hdr(req, "Cache-Control", "no-store");

  while (true) {
    camera_fb_t * fb = esp_camera_fb_get();
    if (!fb) {
      res = ESP_FAIL;
      break;
    }


    res = httpd_resp_send_chunk(req, STREAM_BOUNDARY, strlen(STREAM_BOUNDARY));
    if (res != ESP_OK) {
      esp_camera_fb_return(fb);
      break;
    }


    char part[64];
    int hlen = snprintf(part, sizeof(part), STREAM_PART, fb->len);
    res = httpd_resp_send_chunk(req, part, hlen);
    if (res != ESP_OK) {
      esp_camera_fb_return(fb);
      break;
    }


    res = httpd_resp_send_chunk(req, (const char *)fb->buf, fb->len);
    esp_camera_fb_return(fb);
    if (res != ESP_OK) break;


    vTaskDelay(60 / portTICK_PERIOD_MS);
  }

  return res;
}

static esp_err_t health_handler(httpd_req_t *req) {
  // JSON
  char out[128];
  String ip = WiFi.localIP().toString();
  snprintf(out, sizeof(out),
           "{\"ok\":true,\"ip\":\"%s\",\"ws\":\"ws://%s:81\",\"stream\":\"http://%s/cam/stream\",\"capture\":\"http://%s/cam/capture\"}",
           ip.c_str(), ip.c_str(), ip.c_str(), ip.c_str());

  httpd_resp_set_type(req, "application/json");
  httpd_resp_set_hdr(req, "Access-Control-Allow-Origin", "*");
  httpd_resp_send(req, out, HTTPD_RESP_USE_STRLEN);
  return ESP_OK;
}

void startCameraHttpServer() {
  httpd_config_t config = HTTPD_DEFAULT_CONFIG();
  config.server_port = 80;
  config.max_uri_handlers = 8;
  config.lru_purge_enable = true;

  if (httpd_start(&cam_httpd, &config) == ESP_OK) {
    httpd_uri_t uri_cap = { .uri = "/cam/capture", .method = HTTP_GET, .handler = capture_handler, .user_ctx = NULL };
    httpd_uri_t uri_stream = { .uri = "/cam/stream", .method = HTTP_GET, .handler = stream_handler, .user_ctx = NULL };
    httpd_uri_t uri_health = { .uri = "/cam/health", .method = HTTP_GET, .handler = health_handler, .user_ctx = NULL };

    httpd_register_uri_handler(cam_httpd, &uri_cap);
    httpd_register_uri_handler(cam_httpd, &uri_stream);
    httpd_register_uri_handler(cam_httpd, &uri_health);

    Serial.println("DBG CAM_HTTP_READY 80");
    Serial.println("DBG CAM_URL /cam/stream");
    Serial.println("DBG CAM_URL /cam/capture");
  } else {
    Serial.println("DBG CAM_HTTP_FAIL");
  }
}

void initCamera() {
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer   = LEDC_TIMER_0;
  config.pin_d0       = Y2_GPIO_NUM;
  config.pin_d1       = Y3_GPIO_NUM;
  config.pin_d2       = Y4_GPIO_NUM;
  config.pin_d3       = Y5_GPIO_NUM;
  config.pin_d4       = Y6_GPIO_NUM;
  config.pin_d5       = Y7_GPIO_NUM;
  config.pin_d6       = Y8_GPIO_NUM;
  config.pin_d7       = Y9_GPIO_NUM;
  config.pin_xclk     = XCLK_GPIO_NUM;
  config.pin_pclk     = PCLK_GPIO_NUM;
  config.pin_vsync    = VSYNC_GPIO_NUM;
  config.pin_href     = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn     = PWDN_GPIO_NUM;
  config.pin_reset    = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

 
    config.frame_size   = FRAMESIZE_QVGA;   // 640x480 
    config.jpeg_quality = 20;              
    config.fb_count     = 1;

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("DBG CAM_INIT_FAIL 0x%x\n", err);
    return;
  }

  sensor_t * s = esp_camera_sensor_get();
  if (s) {

    s->set_vflip(s, 1);  
    s->set_hmirror(s, 1);
  }

  Serial.println("DBG CAM_OK");
}


void setup() {
  initUart();
  connectWifi();       // espera hasta conectar
  initCamera();        // init cam
  startCameraHttpServer();
  startWebSocket();    // WS en port 81
}

void loop() {
  wsLoop();    // App <-> ESP
  uartLoop();  // EDUCIAA <-> ESP
}
