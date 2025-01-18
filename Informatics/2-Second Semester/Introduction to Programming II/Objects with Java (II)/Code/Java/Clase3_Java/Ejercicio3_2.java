import java.util.Scanner;
  public class Ejercicio3_2{
     public static void main(String[] args) {
     Balanza b=new Balanza();
     double P, M ;
     Scanner in = new Scanner(System.in);
     
     System.out.println ("Ingrese Peso");
     P= in.nextDouble();
     b.IniciarCompra();
     
     while (P!=0){
       System.out.println ("Ingrese Monto");
       M= in.nextDouble();
       b.registrarProducto(P,M);

      System.out.println ("Ingrese Peso");
      P= in.nextDouble();  
        }
     System.out.println ("Deposite $"+b.devolverMontoAPagar()+  "Bolivares");
       System.out.println (b.devolverResumenDeCompra());
    }
}