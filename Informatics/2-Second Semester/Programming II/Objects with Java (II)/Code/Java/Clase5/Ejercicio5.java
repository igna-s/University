/**
1 -  Queremos representar la información de empleados de un club: jugadores y entrenadores. 
	Cualquier empleado se caracteriza por su nombre, DNI, edad y sueldo básico. 
	Los jugadores son empleados que se caracterizan por el número de partidos jugados y el número de goles anotados.
	Los entrenadores son empleados  que se caracterizan por la cantidad de campeonatos ganados.

A- Implemente la jerarquía de clases, con los atributos de cada clase y métodos para obtener/modificar el valor de los mismos. 
B- Implemente constructores para los jugadores y entrenadores, que reciban toda la información necesaria para inicializar el objeto en cuestión. 
C- Cualquier empleado (jugador / entrenador) debe saber responder al mensaje calcularSueldoACobrar
    (que calcula y devuelve el sueldo a cobrar) pero de manera diferente:
	Para los jugadores: el sueldo a cobrar es el sueldo básico y si el promedio de goles por partido es superior a 0,5 se adiciona un plus de otro sueldo básico. 
	Para los entrenadores: el sueldo a cobrar es el sueldo básico al cual se le adiciona un plus por campeonatos ganados 
        (5000$ si ha ganado entre 1 y 4 campeonatos;  $30.000 si ha ganado entre 5 y 10 campeonatos; 50.000$ si ha ganado más de 10 campeonatos). 

D) Cualquier empleado debe responder al mensaje toString, que devuelve un String que lo representa. La representación de cualquier empleado está compuesta por su nombre y sueldo a cobrar. 

E) Escriba un programa principal que instancie un jugador y un entrenador con datos leídos desde teclado. Pruebe el correcto funcionamiento de cada método implementado. 
NOTA: Tomar como base la clase Entrenador y Jugador definidas en la Actividades anteriores. 

*/



import java.util.Scanner;
public class Ejercicio5{
 public static void main(String[] args) {
  double Sueldo;
  int DNI, partidos, goles, campeon, edad; 
  String Nombre;
  
  Persona p;
  Entrenador e;
  
  Scanner in = new Scanner(System.in);
  
  System.out.println("Ingrese DATOS DEL ENTRENADOR");
  System.out.println("Ingrese sueldo basico");
  Sueldo= in.nextDouble();
  System.out.println("Ingrese nombre");
  Nombre=in.next();
  System.out.println("Ingrese dni");
  DNI= in.nextInt();
  System.out.println("Ingrese edad");
  edad= in.nextInt();
  System.out.println("Ingrese campeonatos ganados ");
  campeon=in.nextInt();
  
  e= new Entrenador(campeon, DNI,  Nombre,  edad, Sueldo );
  
 System.out.println("Ingrese DATOS DEL JUGADOR");
  System.out.println("Ingrese sueldo basico");
  Sueldo= in.nextDouble();
  System.out.println("Ingrese nombre");
  Nombre=in.next();
  System.out.println("Ingrese dni");
  DNI= in.nextInt();
  System.out.println("Ingrese edad");
  edad= in.nextInt();
  System.out.println("Ingrese goles");
  goles= in.nextInt();
  System.out.println("Ingrese partidos");
  partidos= in.nextInt();
  
  p= new Persona(DNI,Nombre, edad, Sueldo , partidos, goles);
  
  System.out.println(p.toString());
  System.out.println(e.toString());
}  
}
