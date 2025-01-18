import java.util.Scanner;
  public class Ejercicio3_4{
     public static void main(String[] args) {
     int i,DNI,edad,partidos,goles;
     Scanner in = new Scanner(System.in);
     String n;
      Persona[]v= new Persona[3];
      for(i=0;i<3;i++){
        
     System.out.println ("Ingrese nombre= ");
      n= in.next();
     System.out.println ("Ingrese Dni");
     DNI= in.nextInt();
      System.out.println ("Ingrese Edad= ");
      edad= in.nextInt();
     System.out.println ("Ingrese Partidos= ");
      partidos= in.nextInt();
      System.out.println ("Ingrese Goles=");
      goles= in.nextInt();
     v[i]= new Persona(n,DNI,edad,partidos,goles);
     }
     System.out.print("La cantidad de jugadores con mas de 100 partidos es= "+masdecien(v));   
    }
    
  public static int masdecien(Persona[]v){
    int i,s=0;
    for(i=0;i<3;i++){
        if(v[i].getPartidos()>100) s++;
  
    }    
    return s;  
    
  
  }
}
     
     


