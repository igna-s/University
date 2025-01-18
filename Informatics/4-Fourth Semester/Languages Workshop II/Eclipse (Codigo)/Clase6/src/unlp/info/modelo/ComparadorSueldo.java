package unlp.info.modelo;

import java.util.Comparator;

public class ComparadorSueldo implements Comparator<Empleado> {
	public int compare(Empleado p1, Empleado p2) {
		return (int) (p1.getSueldo()-p2.getSueldo());
	}
		
}
