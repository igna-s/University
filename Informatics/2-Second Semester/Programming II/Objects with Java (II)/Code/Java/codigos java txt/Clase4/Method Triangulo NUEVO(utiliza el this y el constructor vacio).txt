/** method triangulo que calcula area , perimetro y tiene sus setters y getters
 * para sus lados y los colores del mismo de relleno o de borde
 */
public class Triangulo
{
   private double a,b,c, s;
   private String relleno; 
   private String color;


public  Triangulo(){}
 

public Triangulo(double a, double b, double c, String relleno, String color){
 this.a=a;
 this.b=b;
 this.c=c;
 this.relleno=relleno;
 this.color=color;
}  
public double getA(){
        return a;
    }
public double getB(){
        return b;
    } 
    
 public double getC(){
        return c;
    }   
 public String getColor(){
        return color;
    } 
 public String getRelleno(){
        return relleno;
    } 
    //SETS
  public void setA(double LadoA){
        a=LadoA;
    }
  public void setB(double LadoB){
        b=LadoB;}
        
  public void setC(double LadoC){
        c=LadoC;
    }
  public void setRelleno(String Rell){
        relleno=Rell;
    } 
  public void setColor(String Color){
         color=Color;
        } 
//DEVOLUCION
  
  public double calcularArea(double a,double b,double c){
  double s = (a+b+c) /2;
  double A;
  A=Math.sqrt(s*(s-a)*(s-b)*(s-c)); 
  return A;
 }
 
  public double calcularPerimetro(double a,double b,double c){
  return  (a+b+c) ;
  }
  
  
  
}