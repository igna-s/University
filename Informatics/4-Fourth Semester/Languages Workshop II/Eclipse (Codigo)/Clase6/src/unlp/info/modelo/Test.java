package unlp.info.modelo;

import java.util.Arrays;

public class Test {

	public static void main(String arg[]) {

		Persona[] empleados = new Empleado[100];

		for (int i = 0; i < 100; i++) {
			Empleado empleado = new Empleado();
			empleado.setNombre("Nombre" + i);
			empleado.setApellido("Apellido" + i);
			empleado.setEdad(25 + i);
			empleado.setLegajo(1000 + i);
			empleado.setSueldo(25000 + i * 1000);
			empleados[i] = empleado;
		}

		Empleado[] emple = (Empleado[]) empleados;

		Arrays.sort(empleados);
		System.out.println("");
		for (int i = 0; i < 100; i++) {
			System.out.println("persona" + i + ":" + empleados[i]);
		}

		Arrays.sort(emple);

		System.out.println("");
		Arrays.sort(empleados);
		for (int i = 0; i < 100; i++) {
			System.out.println("empleado" + i + ":" + emple[i]);
		}

		System.out.println("");
		Arrays.sort(emple, new ComparadorSueldo());

		Arrays.sort(empleados);
		for (int i = 0; i < 100; i++) {
			System.out.println("empleado" + i + ":" + emple[i]);
		}
	}

	/// Deberia usar la clase comparator, que permite 1 o + comparaciones
	//Al menos no la desordena XD
}
