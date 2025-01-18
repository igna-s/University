package unlp.info.modelo;

public class Empleado extends Persona{
	private long legajo;
	private double sueldo;

	
	public Empleado() {
		super();
	}
	
	public long getLegajo() {
		return legajo;
	}

	public void setLegajo(long legajo) {
		this.legajo = legajo;
	}

	public double getSueldo() {
		return sueldo;
	}

	public void setSueldo(double sueldo) {
		this.sueldo = sueldo;
	}

	@Override
	public String toString() {
		return super.toString()+this.getSueldo();
	}
	
	public int compareTo(Empleado o) {


		int x=super.compareTo(o);
		if (x!=0)return x;
		else return (int) (this.sueldo-o.getSueldo());
	}
}
