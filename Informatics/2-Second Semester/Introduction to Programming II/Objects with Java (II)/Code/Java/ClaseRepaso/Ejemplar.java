
/**
 Ejemplar posee un código identificatorio, cantidad de páginas, un resumen,
 año de publicación (si aún no fue publicado este valor es cero) 
 */
public abstract class Ejemplar{
    //1er constructor
    private String Ident;
    private int Paginas;
    private String Resumen;
    private int Año;
    private Responsable Resp;

    //constructor numero 2
    public Ejemplar(String I, int P,String R, int A, Responsable Resp){
      this.Ident=I;
      this.Paginas=P;
      this.Resumen=R;
      this.Año=A;
      this.Resp=Resp;
    }
    //constructor numero 3 "vacio"
    public Ejemplar(){}
    
    //set y getters
    
    public void setIdent(String Ident){
        this.Ident=Ident;
    }
    public String getIdent(){
        return Ident;       
    }
    
     public void setPaginas(int Paginas){
        this.Paginas=Paginas;
    }
    public int getPaginas(){
        return Paginas;       
    }
    
     public void setREsumen(String Resumen){
        this.Resumen=Resumen;
    }
    public String getResumen(){
        return Resumen;       
    }
    
    public void setAño(int Año){
    this.Año=Año;
    }
    public int getAño(){
        return Año;              
    }
    
      public void setResp(Responsable Resp){
        this.Resp=Resp;
    }
    public Responsable getResp(){
        return Resp;       
    }
    // fin de set y getters

    abstract String Imprimir();
    
    
    
}