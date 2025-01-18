package unlp.info.math;

import java.util.Scanner;

public class Test {

	public static void main(String[] args) {

		double aux, aux2;
		Complex a, b;
		Scanner s = new Scanner(System.in);
		
		while (true) {

			System.out.println("Ingrese numero complejo-Parte real");
			aux = s.nextDouble();
			System.out.println("Ingrese numero complejo-Parte imaginaria");
			aux2 = s.nextDouble();

			a = new Complex(aux, aux2);

			System.out.println("Ingrese numero complejo-Parte real");
			aux = s.nextDouble();
			System.out.println("Ingrese numero complejo-Parte imaginaria");
			aux2 = s.nextDouble();

			b = new Complex(aux, aux2);

			System.out.println("Suma, " + a.add(b));
			System.out.println("Resta, " + a.substract(b));
		}

	}
}
