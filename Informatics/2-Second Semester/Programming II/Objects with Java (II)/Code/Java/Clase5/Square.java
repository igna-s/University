
/**
       ■
 */
public class Square extends Figura{
   private double lado1;
  
  /* Añadido: tema constructores (1er constructor) */ 
  public Square(double nuevoL1, String nuevoCR, String nuevoCL, Punto unPunto){
      super(nuevoCR,nuevoCL,unPunto);
      lado1 = nuevoL1;
  } 
  
    /* Añadido: tema constructores (2do constructor) */ 
  public Square(double nuevoL1){
      this(nuevoL1,"blanco","negro",new Punto());
      
  } 
  
    /* Añadido: tema constructores (3er constructor) */ 
   public Square(){

   } 
   
   
  public double getLado1(){
       return lado1;       
  }
  public void setLado1(double nuevoLado)
  {
       lado1=nuevoLado;
  }

    
    public double calcularArea(){
     return lado1*2;
  }
  
  public double calcularPerimetro(){
     return (4*lado1);
  }
  
  public void dibujar(){
     System.out.println("Square: " );
     super.dibujar();
     System.out.println("Lados: " + lado1 );
  }
  

}
