
/**
 Escriba un programa que defina una matriz de enteros de tamaño 10x10.
 Inicialice la matriz con los primeros 100 números pares 
 (ej: la pos. 0,0 contendrá 0; la pos. 0,1 contendrá 2; la pos. 0,2 contendrá 4; así siguiendo). 
Luego realice las siguientes operaciones: 
-    Mostrar el contenido de la matriz en consola. 
-    Calcular e informar la suma de todos los elementos almacenados entre las filas 2 y 9 y las columnas 0 y 3
-    Generar un vector de 10 posiciones donde cada posición i contiene la suma de los elementos de la columna i de la matriz.
-    Lea un valor entero e indique si se encuentra o no en la matriz. En caso de encontrarse indique su ubicación (fila y columna) en caso contrario imprima “No se encontró el elemento”

 */
import java.util.Scanner;
public class clase1_6{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int [][]v= new int[10][10];
    int f,c,suma=0,x,i=0;
    for (c=0;c<10;c++){
      for (f=0;f<10;f++ ){
      i=i+2;
      v[f][c]=i;
      }
    }
    for (c=0;c<10;c++){
      for (f=0;f<10;f++ ){
      System.out.print(" "+v[f][c]+" ");
      }
      System.out.println("");
    }
    for (c=0;c<3;c++){
      for (f=2;f<10;f++ ){
      suma=suma+(v[f][c]);
      }
    } 
    System.out.println("la suma de la matriz en los intervalos de fila 2 y 9; columna 0 y 3 es : " +suma);
    suma=0;
    for (f=0;f<10;f++){
      for (c=0;c<10;c++ ){
      suma=suma+(v[f][c]);
      }
      System.out.println("la suma de la de la columna '"+f+"' da: " +suma);
      suma=0;
    } 
     System.out.print("ingrese el valor que quiera buscar en la matriz= ");
     x=in.nextInt();
     c=0;f=0;
    while ((c<10) && ((f<10) && (x!=v[f][c]))){
      f=0;
      while ((f<9) && (x!=v[f][c])) f++;    
      c++;
    }
    System.out.print(x);
    System.out.print(v[f][c]);
    if (x==v[f][c])  System.out.print("el valor '"+x+" se encontro en la posicion; f: "+f+" c: "+c+"  ");
    else System.out.print("el valor '"+x+"' no se encontro");
    in.close();
  }
}