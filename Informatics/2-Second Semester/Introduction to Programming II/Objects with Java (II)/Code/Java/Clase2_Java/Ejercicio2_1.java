
import java.util.Scanner;
public class Ejercicio2_1{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int DNI,Edad; 
    String persona;
    Persona p = new Persona();
    System.out.println("Ingrese el DNI= " ); 
    DNI=in.nextInt();
    p.setDNI(DNI);
    System.out.println("Ingrese el nombre= " ); 
    persona=in.next();
    p.setNombre(persona);
    System.out.println("Ingrese la edad= " ); 
    Edad=in.nextInt();
    p.setEdad(Edad);

    System.out.println(p.getDNI()+" " + p.getNombre()+ " "+p.getEdad());
}  
    
}
