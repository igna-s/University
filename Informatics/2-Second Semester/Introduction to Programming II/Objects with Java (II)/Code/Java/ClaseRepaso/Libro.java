
/** libro que también tiene asociado un título,
 la cantidad de capítulos del mismo y si es o no una edición de bolsillo 
 */
public class Libro extends Ejemplar
{   //primer constructor
    private String Titulo;
    private int Capitulos;
    private boolean Portable;
    
    //segundo constructor
    public Libro(String Titulo,int Capitulos,boolean Portable,String Identificacion, int Paginas, String Resumen, int Año, Responsable Resp){
        super(Identificacion,Paginas,Resumen,Año,Resp);
        this.Titulo= Titulo;
        this.Capitulos= Capitulos;
        this.Portable= Portable;
    } 
    
    //tercer constructor
    public Libro(){}
    
    //seters y getters
    
    public void setTitulo(String Titulo){
        this.Titulo=Titulo;
    }
    public String getTitulo(){
        return Titulo;       
    }
    
     public void setCapitulos(int Capitulos){
        this.Capitulos=Capitulos;
    }
    public int getCapitulos(){
        return Capitulos;       
    }
    
     public void setPortable(boolean Resumen){
        this.Portable= Portable;
    }
    public boolean getPortable(){
        return Portable;       
    }
    
    public void deBolsillo(){
      if (Portable) Titulo= Titulo +" - De Bolsillo";
    
    }
    
    
    
    
    
    
    public String Imprimir(){
        String Aux;
        if (Portable) deBolsillo();
        Aux="Codigo Identificatorio= '"+getIdent()+ "' Titulo= '" +Titulo+
        " y el responsable de la editoral es= '"+getResp().getNombre()+"'. "; 
        return Aux;
    }
    
    
}
