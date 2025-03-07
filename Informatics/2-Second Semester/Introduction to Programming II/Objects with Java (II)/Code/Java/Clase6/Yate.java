/** 	Embarcación, que tiene asociado un código del Registro Especial de Yates (REY), Nombre, un tipo de embarcación (lancha, crucero, velero, etc.), eslora 
    (longitud de proa a popa), un tonelaje (peso) y un valor declarado de la embarcación  **/
public class Yate extends Vehiculo
{

    private String REY;
    private String Nombre;
    private String Tipo;
    private double eslora;
    private double peso;
    private double valor;
    
    public Yate(String unREY, String Nombre, String Tipo, double eslora, double peso, double valor , int Año, double Importe, Propietario p ){
        super(Año,Importe, p);
        this.REY = unREY;
        this.Nombre = Nombre; 
        this.Tipo=Tipo;
        this.eslora=eslora;
        this.peso=peso;
        this.valor=valor;
        
    }
    
    public Yate(){
     
    }

    public String getNombre() {
        return Nombre;
    }


    public String getREY() {
        return REY;
    }

    public void setNombre(String Nombre) {
        Nombre=Nombre;
    }

    public void setREY(String unREY) {
        REY = unREY;
    }
    
    
     public String getTipo() {
        return Tipo;
    }

    public void setTipo(String tipo) {
        Tipo=tipo;
    }
    
     public double getEslora() {
        return eslora;
    }

    public void setNombre(double es) {
        eslora=es;
    }
    
     public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso=peso;
    }
    
     public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor=valor;
    }
    
    public  double Calcular(){
        double c=this.valor;
        if(0<c && c<6000)c=c*0.04;
          else if(c<180000)c=c*0.02;
             else c=c*0.05;
        
        return c/2;   ///Sobre 2 suponiendo que los montos cargados a sistema son anuales
    }
    
    
    
    
    
}

