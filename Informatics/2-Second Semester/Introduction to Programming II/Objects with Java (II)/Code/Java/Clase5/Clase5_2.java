
/**
 Utilizando la jerarquía de figuras, generar una aplicación que permita realizar el dibujo mostrado. 
Un dibujo se caracteriza por su título, el nombre de su autor, y las figuras que lo componen (el máximo es establecido en la creación del dibujo). 
El dibujo debe saber mostrarse en consola, a través de dibujar las figuras que lo componen;
 responder si está completo, es decir si contiene el máximo de figuras admitidas; permitir agregar una nueva figura. 

Ayuda: 
Agregar la clase Square a la jerarquía de figuras. 
Implementar la clase Dibujo
¿Atributos? ¿Métodos?
Implementar el programa que instancie el dibujo 
de la imagen y lo muestre. 
*/

import java.util.Scanner;
 
public class Clase5_2{
  public static void main(String[] args) {
  double lado1,lado2,lado3,lado4,radio;
  String Nombre,Titulo, Relleno, ColorL;
  int dimf,x,y,i;
  Punto p;
  Square s;
  Scanner in = new Scanner(System.in);
  Dibujo Fig= new Dibujo("Martin","Casa Soleada", 4);
  
  Triangulo t = new Triangulo(71,71,71,"Rojo","Negro",new Punto(56,100));
    Circulo c = new Circulo (32,"Naranja","Negro",new Punto(149,82));
    Square c1 = new Square (71,"Amarillo","Negro",new Punto(56,156));
    Square c2 = new Square (26,"Marron","Negro",new Punto(56,177));
    Fig.agregarFigura(c);
    Fig.agregarFigura(c1);
    Fig.agregarFigura(c2);
    Fig.agregarFigura(t);
    //system out print
    System.out.println(Fig.toString());
    Fig.mostrar();
    
    
  } 
}