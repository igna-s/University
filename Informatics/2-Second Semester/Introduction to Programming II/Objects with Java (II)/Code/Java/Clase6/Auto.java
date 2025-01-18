
/**
 * Write a description of class Auto here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Auto extends Vehiculo
{

    private String Patente;
    private String Descrip;
    private double Adi;
    
    public Auto(double Adi, String unPatente, String unDes, int Año, double Importe, Propietario p ){
        super(Año,Importe, p);
        Patente = unPatente;
        Descrip = unDes; 
        this.Adi= Adi;
    }
    
    public Auto(){
     
    }

    public String getDescripcion() {
        return Descrip;
    }


    public String getPatente() {
        return Patente;
    }

    public void setDescripcion(String unDes) {
        Descrip=unDes;
    }

    public void setPatente(String unPatente) {
        Patente = unPatente;
    }
    
    public  double Calcular(){
    return ( Adi+ getImporte() )/12;   ///Sobre 12 suponiendo que los montos cargados a sistema son anuales
    }
}
