
/**
clase
 */
public abstract class Vehiculo
{

    private int Año;
    private Double Importe;
    private Propietario p;
    
    public Vehiculo(int unAño, Double unImporte, Propietario p){

        Año = unAño;
        Importe = unImporte;
        this.p=p;
    }
    
    public Vehiculo(){
     
    }

    public Double getImporte() {
        return Importe;
    }


    public int getAño() {
        return Año;
    }

    public void setImporte(Double unImporte) {
        Importe=unImporte;
    }

    public void setAño(int unAño) {
        Año = unAño;
    }
    
    public Propietario getPropietario(){
        return p;
    }   

    public void setPropietario(Propietario propietario){
        this.p=propietario;
        
    }
    public abstract double Calcular();
}
