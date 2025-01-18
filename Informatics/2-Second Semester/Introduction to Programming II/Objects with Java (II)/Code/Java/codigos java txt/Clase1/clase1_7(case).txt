/*
7- Escriba un programa que simule el ingreso de personas a un banco. 
Cada persona que ingresa indica la operación que desea realizar 
(0: “cobro de cheque” 1: “depósito/ extracción en cuenta” 2: “pago de impuestos o servicios” 3: “cobro de jubilación” 
4: “cobro de planes”). La recepción de personas culmina cuando un empleado ingresa la  operación 999 (cierre del banco). 

Informar la cantidad de personas atendidas por cada operación y la operación más solicitada. 
*/

import java.util.Scanner; // Importar funcionalidad para entrada

public class Clase1_7 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);      // Declarar el scanner e indicar que se leerá desde teclado
        int [] vector = new int [5];
        int x=0;
        int pos=0;
        int max = -1;
        //inicializa vector
        while(x !=5){
               vector[x]=0;
                x++;                              
            }
      //lee operaciones  
        System.out.println ("Ingrese un numero");
        x = in.nextInt();
      while(x !=999){
        switch (x) {
            case 0:  vector[x] = vector[x] +1;
                     break;
            case 1:  vector[x] = vector[x] +1;
                     break;
            case 2:  vector[x] = vector[x] +1;
                     break;
            case 3:  vector[x] = vector[x] +1;
                     break;
            case 4:  vector[x] = vector[x] +1;;
                     break;
            default: System.out.println ("No valido");
                     break;

                    } 
        System.out.println ("Ingrese un numero");
        x = in.nextInt();
      }
      in.close();
      //maximo
      x=0;
      while(x !=5){
           if (vector[x]>max){
                  max=vector[x];
                  pos=x;
            }
           System.out.println ("La operacion" + x + " Tubo " +vector[x]+ " Operaciones");
           x++;
        }
      System.out.println ("La operacion con + operaciones fue: "+ pos);  
}
}