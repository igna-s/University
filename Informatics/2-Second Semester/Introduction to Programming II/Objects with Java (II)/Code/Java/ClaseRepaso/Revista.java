
/** Revista que también tiene asociado un título,
 la cantidad de capítulos del mismo y si es o no una edición de bolsillo 
 */
public class Revista extends Ejemplar{

   //primer constructor
    private String Nombre;
    private int Volumen;
    private int Articulos;
    private Responsable Resp;
    private Generador g;
    //segundo constructor
    
    public Revista(String Nombre,int Volumen,int Articulos,String Identificacion, int Paginas, String Resumen, int Año, Responsable Resp){
        super(Identificacion,Paginas,Resumen,Año,Resp);
        this.Nombre= Nombre;
        this.Volumen= VolumenRandom();
        this.Articulos=Articulos;
    } 
    
    //tercer constructor
    public Revista(){}
    
    
    //seters y getters
    
    public void setNombre(String Nombre){
        this.Nombre=Nombre;
    }
    public String getNombre(){
        return Nombre;       
    }
    
     public void setVolumen(int  Volumen){
        this.Volumen= Volumen;
    }
    public int getVolumen(){
        return  Volumen; 
    } 
    public void setArticulos(int  Articulos){
        this.Articulos= Articulos;
    }
    public int getArticulos(){
        return  Articulos;
    }    
    public String Imprimir(){
        String Aux;
        Aux="Nombre = '"+Nombre+ "' y su Numero de Volumen es= '" +Volumen+
        "'."; 
        return Aux;
    }
    
   public int VolumenRandom(){
       int x;
       x=g.getNroVolumen();
       return x;
    }   
}
