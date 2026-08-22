public class Persona  {
    private String nombre;
    private int DNI;
    private int edad;
    private int partidos;
    private int goles;
    
    public Persona(String unNombre, int unDNI, int unaEdad, int unosPartidos, int unosGoles){
        nombre = unNombre;
        DNI = unDNI;
        edad = unaEdad;
        partidos=unosPartidos;
        goles=unosGoles;
    }
    
    public Persona(){
     
    }

    public int getDNI() {
        return DNI;
        
    }

        public int getPartidos() {
        return partidos;
        
    }
        public int getGoles() {
        return goles;
        
    }
    
    public int getEdad() {
        return edad;
    }

    public String getNombre() {
        return nombre;
    }

    public void setDNI(int unDNI) {
        DNI = unDNI;
    }

    public void setGoles(int unGol) {
        goles = unGol;
    }
    
    public void setPartidos(int unParti) {
        partidos = unParti;
    }
    
    public void setEdad(int unaEdad) {
        edad = unaEdad;
    }

    public void setNombre(String unNombre) {
        nombre = unNombre;
    }
    
    public String toString(){
        String aux; 
        aux = "Mi nombre es " + nombre + ", mi DNI es " + DNI + " y tengo " + edad + " años, jugue " + partidos + " partidos e hice  " + goles + " goles.";
        return aux;
    }
    
    
    
    
}

