/** 3- Escriba un programa que imprima en consola el factorial de un número N (ingresado por teclado, N > 0).  
 * Ejemplo: para N=5 debería imprimir 5! = 120  */
 

import java.util.Scanner;
public class clase1_3 {
    public static void main(String args[]) {
      int num,i, aux=1;
      Scanner scan = new Scanner(System.in);
      System.out.print("Ingrese un numero: ");

      num = scan.nextInt();
      for(i=num;i>1;i--)
        aux=aux*i; 
      System.out.println(aux);
      }
    }

