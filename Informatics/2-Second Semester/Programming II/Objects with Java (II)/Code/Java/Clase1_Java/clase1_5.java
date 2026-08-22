/**5- Escriba un programa que lea las alturas de los 15 jugadores de un equipo de básquet y las almacene en un vector.  Luego informe: 
-    la altura promedio
-    la cantidad de jugadores con altura por encima del promedio
NOTA: Dispone de un esqueleto para este programa en Ej05Jugadores.java
 * 
 */
import java.util.Scanner;
public class clase1_5
{
  public static void main(String[] args){
    double [] v = new double[15];
    int i;
    double suma=0, alt;
    
    Scanner in = new Scanner(System.in);
    for (i=0;i<15;i++){     
    System.out.print("Ingrese la altura: ");
    alt = in.nextInt(); 
    v[i]=alt;
    suma = suma + alt;
}
suma=(suma/15);
System.out.print("Promedio altura: " + suma);
   for (i=0;i<15;i++){ 
    if (v[i]>suma) 
       System.out.println("Altura de: " + (i) + " Por encima del promedio ");
}
    in.close();
  }
}