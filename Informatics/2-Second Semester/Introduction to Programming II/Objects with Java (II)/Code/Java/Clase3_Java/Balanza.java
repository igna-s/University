
public class Balanza{
  private int cantidad;
  private double monto;
  
  
  
  public void IniciarCompra ()
  {
      cantidad=0;
      monto=0; 
  }
  
  public void registrarProducto(double cant, double precio)
  {
      cantidad++;
      monto=monto+cant*precio; 
  }
  public double devolverMontoAPagar(){
      return(monto);
    }
  public String devolverResumenDeCompra() {
    return ("Total a pagar: $" + monto + " por la compra de "+ cantidad +" productos");   
    }
  
}  