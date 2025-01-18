import java.util.Scanner;
public class Ejercicio2_2{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int DNI,Edad; 
    String persona;
    int i, min=999;
    Persona[]v= new Persona[15];
    
    for(i=0;i<2;i++){
      System.out.println("Ingrese el DNI= " ); 
      DNI=in.nextInt();
      System.out.println("Ingrese el nombre= " ); 
      persona=in.next();
      System.out.println("Ingrese la edad= " ); 
      Edad=in.nextInt();
      v[i]= new Persona(persona,DNI,Edad);
      System.out.println(v[i]);
 
    }
    System.out.println("la cantidad de personas con mas de 65 años es= " + suma(v)) ;   
    System.out.println("la persona con menor DNI dice= Hola, " + v[resultado(v)]) ;  
}
    public static int suma(Persona[]v){   
      int i,s=0;
      for(i=0;i<2;i++)
        if (v[i].getEdad()  >65 ) s=s+1;
      return s;  
    }
    public static int resultado(Persona[]v){
        int i,r=0,min=999;
      for(i=0;i<2;i++)
        if (v[i].getDNI() < min ) { min=v[i].getDNI();
           r=i;}
       return r;
        }
        
     
}  

