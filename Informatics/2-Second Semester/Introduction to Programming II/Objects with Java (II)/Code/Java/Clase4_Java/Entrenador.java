public class Entrenador


  {
    private String nombre;
    private double sueldo;
    private int campeon; 
    
    public Entrenador(String unNombre, double unSueldo, int unCampeon){
         this(unCampeon, unNombre, unSueldo );
        
    }
    public Entrenador(int campeon, String nombre, double sueldo ){
    this.nombre=nombre;
    this.sueldo=sueldo;
    this.campeon=campeon;
        
    }
        
        
    public Entrenador(){
     
    }

    public double getSueldo() {
        return sueldo;
    }

    public int getCampeon() {
        return campeon;
    }

    public String getNombre() {
        return nombre;
    }

    public void setSueldo(double unSueldo) {
        sueldo=unSueldo;
    }

    public void setCampeon(int unCampeon) {
        campeon = unCampeon;
    }

    public void setNombre(String unNombre) {
        nombre = unNombre;
    }
    
    public double calcularSueldoACobrar(){
    double s=0, c=campeon;
    double sb= sueldo;
    s=s+sb;
    if (c!=0)
       {
        if(0<c && c<5)s=s+5000;
          else if(c<11)s=s+30000;
             else s=s+50000;
            
        }
    return s;
    }    
    public String toString(){
        String aux; 
        aux = "Mi nombre es " + nombre + ", mi sueldo es " + this.calcularSueldoACobrar() + " y tengo " + campeon + " copas FelYPF.";
        return aux;
    }
}
    
    
