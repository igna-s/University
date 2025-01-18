                                          
from IPython.display import HTML, Image, display
from google.colab.output import eval_js
from base64 import b64decode
import tempfile

from IPython.display import Javascript, display

# def run_js(js_code):
#     display(Javascript(js_code))
    
canvas_html = """
<style>
  canvas {
    border:2px dashed black;
  }
  button {
    display: inline-block;
    margin: 10px;
    padding:10px;
    background-color: #1fa3ec;
    border: 0;
    border-radius:0.317rem;
    color:white;
    height:40px;
    font-size:1rem;
  }
  button:hover:enabled {
    opacity: 0.75;
  }

  button:disabled{
    background-color: gray;
  }

</style>
<div style='display:inline-grid'>
  <canvas width=%d height=%d></canvas>
  <button>Finalizar Dibujo</button>
</div>
<script>
var canvas = document.querySelector('canvas')
var ctx = canvas.getContext('2d')
ctx.lineWidth = %d
var button = document.querySelector('button')
var mouse = {x: 0, y: 0}
var Touch = {x: 0, y: 0}
canvas.addEventListener('mousemove', function(e) {
  mouse.x = e.pageX - this.offsetLeft
  mouse.y = e.pageY - this.offsetTop
})
canvas.addEventListener('touchmove', function(e) {
  Touch.x = e.pageX - this.offsetLeft
  Touch.y = e.pageY - this.offsetTop
})
canvas.onmousedown = ()=>{
  ctx.beginPath()
  ctx.moveTo(mouse.x, mouse.y)
  canvas.addEventListener('mousemove', onPaint)
}
canvas.ontouchstart = ()=>{
  ctx.beginPath()
  ctx.moveTo(Touch.x, Touch.y)
  canvas.addEventListener('touchmove', onPaint2)
}
canvas.onmouseup = ()=>{
  canvas.removeEventListener('mousemove', onPaint)
}
canvas.ontouchend = ()=>{
  canvas.removeEventListener('touchmove', onPaint2)
}
var onPaint = ()=>{
  ctx.lineTo(mouse.x, mouse.y)
  ctx.stroke()
}
var onPaint2 = ()=>{
  ctx.lineTo(Touch.x, Touch.y)
  ctx.stroke()
}
var data = new Promise(resolve=>{
  button.onclick = ()=>{
    resolve(canvas.toDataURL('image/png'))
    canvas.onmousedown = ()=>{}
    var button = document.querySelector('button')
    button.style.visibility = 'hidden'

  }
})
</script>
"""

from PIL import Image, ImageOps


class DrawPanel(object):

  def draw(self, size=(100,100), line_width=3, scale=1.0):
    w, h = size[0], size[1]
    line_width = line_width * scale
    display(HTML(canvas_html % (w * scale, h * scale, line_width)))
    data = eval_js("data")
    #data = run_js("data")
    binary = b64decode(data.split(',')[1])
    #filename = tempfile.mkdtemp() +'/DrawPanel_picture.png' 

    from io import BytesIO
    buffer = BytesIO() 
    buffer.write(binary)

    image = Image.open(buffer)
    image = image.resize((w, h))
    gray_image = ImageOps.grayscale(image)
    image.show()
    gray_image.show()
    return image
    #with open(filename, 'wb') as f:
    #  f.write(binary)
    
    #Image.open(filename)
    #return filename

  def draw_to_file(self, filename='drawing.png', w=200, h=200, line_width=3):
    display(HTML(canvas_html % (w, h, line_width)))
    data = eval_js("data")
    #data = run_js("data")
    binary = b64decode(data.split(',')[1])
    filename = tempfile.mkdtemp() +'/' + filename
    with open(filename, 'wb') as f:
      f.write(binary)
    return filename
