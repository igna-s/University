
/**
 * Write a description of class Triangulo here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Triangulo
{
   private double a,b,c, s;
   private String relleno; 
   private String color;


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