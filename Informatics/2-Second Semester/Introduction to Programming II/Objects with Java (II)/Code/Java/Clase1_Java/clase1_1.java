
/**Escriba un programa que lea desde teclado 3 valores double. Determine si a partir de ellos se forma un triángulo válido y en ese caso
 * muestre en consola el perímetro del mismo. 
NOTA: Un triángulo es válido si se cumplen las siguientes tres condiciones: 
(a < b + c) ,  (b < a + c), (c < a + b), donde a,b,c son los lados.  */

import java.util.Scanner; // Importar funcionalidad para entrada
public class clase1_1
{
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);      // Declarar el scanner e indicar que se leerá desde teclado
    System.out.print("Ingrese A: ");
    double a = in.nextDouble(); 
    System.out.print("Ingrese B: ");
    double b = in.nextDouble();
    System.out.print("Ingrese C: ");
    double c = in.nextDouble();
    in.close();   // Cerrar el scanner
    if ((a < b + c) &&  (b < a + c) && (c < a + b)) System.out.println("true");
    else System.out.println("false");    
    }
}

