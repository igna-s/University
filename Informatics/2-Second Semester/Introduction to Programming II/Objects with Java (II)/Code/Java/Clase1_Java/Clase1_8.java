/*8-
 * El dueño de un restaurante entrevista a cinco clientes y les pide que califiquen (con puntaje de 1 a 10) los siguientes aspectos: 
 (0) Atención al cliente (1) Calidad de la comida (2) Precio  (3) Ambiente.

 Escriba un programa que lea desde teclado las calificaciones de los cinco clientes para cada uno de los aspectos y
 almacene la información en una estructura. Luego imprima la calificación  promedio obtenida por cada aspecto. 
*/

import java.util.Scanner; // Importar funcionalidad para entrada

public class Clase1_8 {
  public static void main(String[] args) {
        Scanner in = new Scanner(System.in);      // Declarar el scanner e indicar que se leerá desde teclado
        double [] vector = new double [4];
        int i;
        int x=0;

        //inicializa vector
        for (i=0;i<4;i++){
               vector[x]=0;                            
            }
            
         //lee operaciones  
      for (i=0;i<4;i++){
         System.out.println ("Clasifique Atencion al cliente");
          x = in.nextInt();
          vector[0] = x+vector[0];
          System.out.println ("Clasifique Calidad del plato");
          x = in.nextInt();
          vector[1] = x+vector[1];
          System.out.println ("Clasifique Precio del plato");
          x = in.nextInt();
          vector[2] = x+vector[2];
          System.out.println ("Clasifique el Ambiente del restorant");
          x = in.nextInt();
          vector[3] = x+vector[3];
      }
      
      //Devuelve clasificacion promedio
      for (i=0;i<4;i++){
               System.out.println ("El aspecto " + i + " obtuvo " + vector[i]/5);                             
            }
      in.close();
        }
}
