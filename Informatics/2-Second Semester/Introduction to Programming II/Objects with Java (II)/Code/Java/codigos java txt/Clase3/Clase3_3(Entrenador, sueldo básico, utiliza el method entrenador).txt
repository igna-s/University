import java.util.Scanner;
  public class Ejercicio3_3{
     public static void main(String[] args) {
     Entrenador e=new Entrenador();
     Scanner in = new Scanner(System.in);
     String n;
     int c;
     
     System.out.println ("Ingrese nombre= ");
     n= in.next();
     e.setNombre(n);
     
     System.out.println ("Ingrese Copas");
     c= in.nextInt();
     e.setCampeon(c);

    e.setSueldo(e.calcularSueldoACobrar(c));  
    
     System.out.println (e.toString());
    }
}