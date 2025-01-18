
/**
 * Write a description of class ProgramaArba here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */


import java.util.Scanner;
public class ProgramaArba{
 public static void main(String[] args) {
   int i=0,Dim=1;  
   int a,x;
   String p,c,pat,des, rey, nom ,type;
   double im,es,tn,imp, adi;
   Vehiculo v[]=new Vehiculo[Dim];  
     Scanner in = new Scanner(System.in);
     while (i<Dim){
         System.out.println ("Seleccione el vehiculo auto[1]/yate[2] "); 
         x = in.nextInt();
         if((x!=1) && (x!=2)) System.out.println("Escriba un numero valido☺");
             else {
                 System.out.println ("Ingrese año de fabricacion");
                 a = in.nextInt();
                 System.out.println ("Ingrese Propietario");
                 p = in.next();                   
                 System.out.println ("Ingrese Importe");
                 im = in.nextDouble();
                 System.out.println ("Ingrese CIT");
                 c= in.next();
                     if(x==1){
                            System.out.println ("Ingrese Patente del Auto= ");
                            pat = in.next();   
                            System.out.println ("Ingrese su decripcion del automovil= ");
                            des= in.next(); 
                            System.out.println ("Ingrese Adicional por año= ");
                            adi= in.nextDouble();  
                            Propietario pr= new Propietario(c,p);
                            v[i]=new Auto(adi, pat, des, a, im, pr);
                    }
                    else{
                        System.out.println ("Ingrese REY= ");
                            rey = in.next();   
                            System.out.println ("Ingrese su nombre ");
                            nom= in.next(); 
                            System.out.println ("Ingrese Tipo de vehiculo ");
                            type = in.next();
                            System.out.println ("Ingrese Eslora");
                            es = in.nextDouble();
                            System.out.println ("Ingrese Tonelaje");
                            tn = in.nextDouble();
                            System.out.println ("Ingrese Importe");
                            imp = in.nextDouble();
                            Propietario pr= new Propietario(c,p);
                            v[i]=new Yate(rey, nom, type, es, tn, imp ,a, im, pr);
                    } 
            
                 i++ ;       
                }
            }
        
            
            for(i=0;i<Dim;i++)System.out.println ("Rata, paga u$s "+ v[i].Calcular()) ;
        }
    }