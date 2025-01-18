package unlp.info.modelo;

public class Persona implements Comparable<Persona> {

	private String nombre;
	private String apellido;
	private int edad;

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public String getApellido() {
		return apellido;
	}

	public void setApellido(String apellido) {
		this.apellido = apellido;
	}

	public int getEdad() {
		return edad;
	}

	public void setEdad(int edad) {
		this.edad = edad;
	}

	@Override
	public String toString() {
		return this.getApellido()+this.getNombre();
	}
	
	@Override
	public int compareTo(Persona o) {
		if ((apellido.equals(o.getApellido()) && (nombre.equals(o.getNombre()))))
			return (0);
		if (apellido.equals(o.getApellido()))
			return nombre.compareTo(o.getNombre());
		return apellido.compareTo(o.apellido);
	}

}
