
/**
Escriba un programa para restringir la entrada de autos al centro de la ciudad: sólo pasarán aquellos con patente par.
 Para ello se leen números de patentes, por cada una debe informar en consola si el auto tiene o no permitido el paso.  
 La lectura finaliza cuando se ingresa la patente 0. Al finalizar, informar el porcentaje de autos que ingresaron respecto al total de autos. 
  */
import java.util.Scanner;
public class clase1_2{
public static void main(String[] args)
  {
    int Par=0;
    int Total=0;
    Scanner in = new Scanner(System.in);      // Declarar el scanner e indicar que se leerá desde teclado
    System.out.print("Ingrese la parte numerica de la patente: ");
    int a = in.nextInt(); 
    while (a!=0){
      if (a%2 ==0){ System.out.println("la patente " + a + " cumple (es par)");
                  Par++;
                } 
      else System.out.println("la patente " + a + " no cumple (es impar)") ;
    
    Total++ ;        
    System.out.print("Ingrese OTRA patente: ");
    a = in.nextInt();     
    }
    if (a!=0){
    System.out.println("El porcentaje de autos que ingresaron es " + ((Par*100)/Total)+ " %");
    in.close();   // Cerrar el scanner
 }
}
}