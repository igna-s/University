
/**Para el responsable se registra su DNI, nombre y apellido.  
 */
public class Responsable{
    //primer constructor
    private int Dni;
    private String Nombre;
    private String Apellido;
    
    //segundo constructor
    public Responsable(int Dni,String Nombre, String Apellido ){
        this.Dni=Dni;
        this.Nombre=Nombre;
        this.Apellido=Apellido;
    }
    
    //tercer constructor
    public Responsable(){}
    
    
    //set y getters
      public void setDni(int Dni){
        this.Dni=Dni;
    }
    public int getDni(){
        return Dni;       
    }
    
      public void setNombre(String Nombre){
        this.Nombre=Nombre;
    }
    public String getNombre(){
        return Nombre;       
    }
    
      public void setApellido(String Apellido){
        this.Apellido=Apellido;
    }
    public String getApellido(){
        return Apellido;       
    }
    
}
