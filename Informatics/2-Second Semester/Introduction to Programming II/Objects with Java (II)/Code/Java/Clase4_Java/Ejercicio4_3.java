/*Realice un programa ppal. que cree un micro con patente “ABC123”, destino “Mar del Plata” y hora de salida “5:00 am”.  
Cargue pasajeros en el micro de la siguiente manera:

        Leer nros. de asientos desde teclado que corresponden a pedidos de personas.
 
  La lectura finaliza cuando se ingresa el nro. de asiento -1 o cuando se llenó el micro.
    Para cada nro. de asiento leído debe:
 
        ☺validar el nro; 
        ☺en caso que esté libre, ocuparlo e informar a la persona el éxito de la operación;
        ☺en caso que esté ocupado informar a la persona la situación y mostrar el nro. del primer asiento libre.
        
  Al finalizar, informe la cantidad de asientos ocupados del micro.*/


import java.util.Scanner;
  public class Ejercicio4_3{
     public static void main(String[] args) {
     Scanner in = new Scanner(System.in);
     Micro m= new Micro("ABC123","Mar Del Plata","5:00 am");
     boolean t= false;
     int x=0,i=0;
     System.out.println("ingrese el numero de asiento= ");
     i=in.nextInt();
     while(i!=-1){
        if(m.Existe(i)){ 
            t= m.Ocupar(i);
            if(t) System.out.println("Se vendio el asiento solicitado");
            else { System.out.println("No disponible, Estamos buscando un asiento disponible");
                 x= m.Disponible();
                 if(x!=-1){
                     m.Ocupar(x); 
                     System.out.println("Se vendio el asiento "+x);}
                 else System.out.println("Micro completo");
            }
            }
        else System.out.println("Ingrese un numero coherente, ");
        
        System.out.println("ingrese otro numero de asiento= ");
        i=in.nextInt();
        }
   
     }
       
    }

