import java.util.Scanner;
public class Ejercicio2_4{
  public static void main(String[] args){
    Partido[]v= new Partido[3];
    Scanner in = new Scanner(System.in);
    String lo,vi,ganador;
    int i,gol_v,gol_l;
    for(i=0;i<3;i++){
      System.out.println("Ingrese el local: ");
      lo= in.next();
      System.out.println("Ingrese el visitante: ");
      vi= in.next();
      System.out.println("Ingrese los goles del local: ");
      gol_l= in.nextInt();
      System.out.println("Ingrese los goles del visitante: ");
      gol_v= in.nextInt();
      v[i]= new Partido(lo,vi,gol_l,gol_v);
      System.out.println(v[i].getGanador());
    }
    System.out.println("La cantidad de partidos que gano River es de = "+rivergano(v)+" partidos.");
    System.out.println("La cantidad de goles que hizo Boca como local es de = "+golesboca(v)+" goles.");
    System.out.println("El promedio de partidos empatados es de = "+promedioempate(v)+" partidos.");
  } 
  public static int rivergano(Partido[]v){
      int s=0,i;
    for(i=0;i<3;i++)
        if (v[i].hayGanador())
        if(v[i].getGanador().equals("River")) s++;
  return s;
  }
  public static int golesboca(Partido[]v){
     int g=0,i;
    for(i=0;i<3;i++) 
      if(v[i].getLocal().equals("Boca")) g=g+ v[i].getGolesLocal();
    
  return g; 
  }
  public static double promedioempate(Partido[]v){
     int e=0,i;
    for(i=0;i<3;i++) 
      if (v[i].hayEmpate()) e++;
    e=(e*100)/3;
  return e; 
  }
}

