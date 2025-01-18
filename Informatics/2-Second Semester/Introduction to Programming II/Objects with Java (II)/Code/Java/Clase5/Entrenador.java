public class Entrenador extends Empleados


  {
    private int campeon; 
    
    public Entrenador(int campeon, int dni, String nombre, int edad, double sueldo ){
        super(dni, nombre,  edad, sueldo);
        this.campeon=campeon;
        
    }
        
        
    public Entrenador(){
     
    }
    public int getCampeon() {
        return campeon;
    }

    public void setCampeon(int Campeon) {
        this.campeon = Campeon;
    }

    public double calcularSueldoACobrar(){
    double s=0, c=campeon;
    double sb= getSb();
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
        return super.toString();
    }
}
   
