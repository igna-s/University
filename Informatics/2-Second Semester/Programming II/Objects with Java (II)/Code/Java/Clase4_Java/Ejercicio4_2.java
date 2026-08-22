import java.util.Scanner;
  public class Ejercicio4_2{
     public static void main(String[] args) {
     Scanner in = new Scanner(System.in);
     String n;
     int c;
     Entrenador e;
     System.out.println ("Ingrese nombre= ");
     n= in.next();
     
     System.out.println ("Ingrese Copas");
     c= in.nextInt();

     e=new Entrenador(n,30000,c);

     System.out.println (e.toString());
    }
}