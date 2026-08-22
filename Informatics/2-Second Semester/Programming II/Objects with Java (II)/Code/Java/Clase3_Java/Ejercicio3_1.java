
import java.util.Scanner;
public class Ejercicio3_1{
 public static void main(String[] args) {
  double a,b,c;
  Scanner in = new Scanner(System.in);
   Triangulo t=new Triangulo();
   System.out.println ("Ingrese a");
   a = in.nextInt();
   t.setA(a);
   System.out.println ("Ingrese b");
   b = in.nextInt();
   t.setB(b);
   System.out.println ("Ingrese c");
   c = in.nextInt();
   t.setC(c);
   in.close();
   
   System.out.println("El area es igual a = "+ t.calcularArea(a,b,c));
   System.out.println("El perimetro es igual a = "+ t.calcularPerimetro(a,b,c));
  }
}
