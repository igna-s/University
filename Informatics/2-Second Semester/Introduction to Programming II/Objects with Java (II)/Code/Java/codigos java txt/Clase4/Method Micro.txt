/*3-A- Definir una clase para representar micros. Un micro se caracteriza por su patente,
 * destino, hora salida, una cantidad de asientos fija (20) para los que debe registrar su estado (es decir si está o no ocupado)
 * y cantidad de asientos ocupados.  El micro puede ocuparse total o parcialmente.
a)	Defina métodos getters/setters para patente, destino y hora de salida.
b)	Implemente un constructor que permita inicializar el micro creado con una patente,  un destino y una hora de salida (recibidas como parámetro) y sin pasajeros. 
c)	Implemente métodos para: 
i.	devolver la cantidad de asientos ocupados
ii.	devolver si el micro está lleno
iii.	validar un número de asiento recibido como parámetro
iv.	devolver el estado de un nro. de asiento válido recibido como parámetro
v.	ocupar un nro. de asiento válido recibido como parámetro
vi.	liberar un nro. de asiento válido recibido como parámetro
vii.	devolver el nro. del primer asiento libre

*/

public class Micro


  {
    private String Destino;
    private String Patente;
    private String Hora;
    private int ocupado, cantidad; 
    private boolean [] v ;
    
    
    public Micro(String Patente, String Destino, String Hora ){
    this.Destino=Destino;
    this.Hora=Hora;
    this.Patente=Patente;
    this.ocupado=0;
    this.cantidad=20;
    this.v=new boolean [cantidad];
    this.iniciar(v);    
    }
    
    public void iniciar(boolean[]v){
    int i=0;
    for (i=0;i<cantidad;i++) v[i]=false;
 
    }
        
    public Micro(){
     
    }

    public String getHora() {
        return Hora;
    }


     public String getDestino() {
        return Destino;
    }

    public String getPatente() {
        return Patente;
    }

    public void setPatente(String unapat) {
        Patente=unapat;
    }
    
    public void setHora(String unHora) {
        Hora=unHora;
    }


    public void setDestino(String unDestino) {
        Destino = unDestino;
    }
    
    public int Ocupados(){
    int i,s=0;
    
    for(i=0;i<20;i++){
         if (v[i]= true )s++;    
    }
    return s;
    }
    
    public boolean MicroLleno(){
    int i,s=0;
    boolean t=false;
    for(i=0;i<20;i++){
         if (v[i]= true )s++;    
    }
    if (s==cantidad)t=true;
    
    return t;
    }
    
    public boolean Existe(int num){
    boolean t=false;
     if (num>=0 && num<cantidad) t=true;
    return t;
    }
    
    public boolean Ocupado(int num){
    boolean t=false;
     if (this.Existe(num)) return v[num];
     else return t;
     

    }
    
    
    
    public  boolean Ocupar(int num){
    boolean t=false;
     if (this.Existe(num)&& v[num]==false)  {v[num]=true; return true;}
     else return t;
     
    }        
     public  boolean Vaciar(int num){
     boolean t=false;
     if (this.Existe(num)&& v[num]==true)  {v[num]=false; return true;}
     else return t;

    }
    
    
               
     public  int Disponible(){
     boolean t=false;
     int i;
     i=0;
     while(t==false && i<cantidad){
         if (v[i]==false) t=true;
         else i=i+1;
        }
     if(t==true) {
         this.Ocupar(i);
         return i;
     }
     else return -1;
    }
    
}