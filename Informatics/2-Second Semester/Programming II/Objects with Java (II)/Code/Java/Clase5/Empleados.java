
public abstract class Empleados
{
    private String nombre;
    private int DNI;
    private int edad;
    private double sb;
    
    public Empleados(){}
    
    public Empleados(int dni, String nombre, int edad, double sueldo ){
      this.DNI=dni;
      this.nombre=nombre;
      this.edad=edad;
      this.sb=sueldo;
    }
    
    public int getDNI() {
        return DNI;
        
    }
    
    public int getEdad() {
        return edad;
    }

    public String getNombre() {
        return nombre;
    }

    public void setDNI(int DNI) {
        this.DNI = DNI;
    }

    public void setEdad(int Edad) {
        this.edad = Edad;
    }

    public void setNombre(String Nombre) {
        this.nombre = Nombre;
    }

    public double getSb() {
        return sb;
    }

    public void setSb(double sb) {
        this.sb = sb;
    }
    
    abstract double calcularSueldoACobrar();
    
    public String toString(){
      String aux; 
        aux = "Mi nombre es " + nombre + "y mi sueldo es " + calcularSueldoACobrar()+ " ";
        return aux;
    
    
    };
    
}