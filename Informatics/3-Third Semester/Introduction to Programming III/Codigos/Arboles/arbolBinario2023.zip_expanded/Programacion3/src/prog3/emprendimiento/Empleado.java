package prog3.emprendimiento;


public class Empleado  {
  private String nombre;
  private int antiguedad;
  private int categoria;
  
  public Empleado() {};
  
  public Empleado(String nombre, int anti, int cat) {
	  this.antiguedad=anti;
	  this.categoria=cat;
	  this.nombre=nombre;
	    
  }

public String getNombre() {
	return nombre;
}

public void setNombre(String nombre) {
	this.nombre = nombre;
}

public int getAntiguedad() {
	return antiguedad;
}

public void setAntiguedad(int antiguedad) {
	this.antiguedad = antiguedad;
}

public int getCategoria() {
	return categoria;
}

public void setCategoria(int categoria) {
	this.categoria = categoria;
};
  
  
@Override
public String toString() {
	return("Nombre " +this.nombre+ " Data " +this.antiguedad +this.categoria); 
}
  
  
}
