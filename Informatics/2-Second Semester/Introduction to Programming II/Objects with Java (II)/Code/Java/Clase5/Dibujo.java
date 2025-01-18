
public class Dibujo{ 
    private String Name;
    private String titulo;
    private Figura[] f;
    private int dim;
    private int act;
    
    public Dibujo(String nombre, String titulo, int dim){
    f= new Figura[dim];
    this.Name=nombre;
    this.titulo=titulo;
    this.dim=dim;
    this.act=0;
    }

public Dibujo(){}

     public void setName(String n){
        this.Name=n;
    }
    public String getName(){
        return Name;
    }

     public void setTitulo(String p){
        this.titulo=p;
    }
    public String getTitulo(){
        return titulo;
    }

    
    public boolean estaCompleta(){
        if (act>=dim) return true;
            else return false;
    }
    
    @Override
    public String toString(){
        return (Name +" "+ titulo);
        
        } 
        
        
        public void mostrar(){
        int i;
        
        for(i=0;i<dim;i++){
            f[i].dibujar();
        }
    }
    public void agregarFigura(Figura M){
        if (!this.estaCompleta()){
            f[act]= M;
             act++;
            }
     }
}