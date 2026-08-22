
import java.util.Scanner;
public class Ejercicio4_1{
 public static void main(String[] args) {
  double a,b,c;
  String B,R;
  Triangulo t;
  Scanner in = new Scanner(System.in);
   
   System.out.println ("Ingrese a");
   a = in.nextInt();
   System.out.println ("Ingrese b");
   b = in.nextInt();
   System.out.println ("Ingrese c");
   c = in.nextInt();
   System.out.println ("Ingrese borde");
   B = in.next();
   System.out.println ("Ingrese relleno");
   R = in.next();
   t=new Triangulo(a,b,c,R,B);
   System.out.println("El area es igual a = "+ t.calcularArea(a,b,c));
   System.out.println("El perimetro es igual a = "+ t.calcularPerimetro(a,b,c));
   in.close();
  }
}
