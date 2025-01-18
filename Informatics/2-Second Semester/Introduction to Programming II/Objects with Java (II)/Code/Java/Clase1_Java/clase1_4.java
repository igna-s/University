//*4- Escriba un programa que imprima en consola el factorial de todos los números entre 1 y 9. 
//*¿Qué modificación debe hacer para imprimir el factorial de los números impares solamente?


public class clase1_4 {
    public static void main(String args[]) {
      int i,j, aux=1;
      for (j=9;j>=0;j=j-2) {
        for(i=j;i>1;i--)
           aux=aux*i;    
      System.out.println("El numero " + j + " tiene como factorial a: " + aux);
      aux=1;
    }
  }
}
    


