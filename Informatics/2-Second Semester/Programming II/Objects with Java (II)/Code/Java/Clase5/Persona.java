public class Persona extends Empleados  {
    private int partidos;
    private int goles;
    
    public Persona(int dni, String nombre, int edad, double sueldo , int Partidos, int Goles){
        super(dni,nombre, edad,sueldo );
        this.partidos=Partidos;
        this.goles=Goles;
    }
    
    public Persona(){
     
    }


        public int getPartidos() {
        return partidos;
        
    }
        public int getGoles() {
        return goles;
        
    }
    

    public void setGoles(int unGol) {
        goles = unGol;
    }
    
    public void setPartidos(int unParti) {
        partidos = unParti;
    }
    
    public double calcularSueldoACobrar(){
        
        if ((goles/partidos)>=0.5 )
               return getSb()*2;
        else
               return getSb();
    }    
  
        public String toString(){
        return super.toString();
    }
    
    
    
    
}

