import java.sql.Date;
import java.util.Scanner;

public class Test {

	public static void main(String[] args) {

		if (args.length == 2) {

			IMC i = new IMC();
			// i.setAltura(Float.parseFloat(args[0]));
			// i.setPeso(Float.parseFloat(args[1])); //Pasaje via main

			Scanner read = new Scanner(System.in);
			float aux2 = 0;

			boolean x = true;
			while (x == true) {
				System.out.println("Ingrese peso (kg)");
				aux2 = read.nextFloat();
				i.setPeso(aux2);
				if (aux2 > 0)
					x = false;

			}

			x = true;
			while (x == true) {
				System.out.println("Ingrese altura (mts)");
				aux2 = read.nextFloat();
				i.setAltura(aux2);
				if (aux2 > 0)
					x = false;
			}

			float aux = i.calculo();

			if (aux > 25) {
				System.out.println("Usted tiene sobrepeso");
			} else if (aux < 18) {
				System.out.println("Usted tiene anorexia");
			} else
				System.out.println("15-10- Ud. parece saludable");
			
			IMC.calculo(0, 0);  //SI SE PUEDE, PERO TIENE QUE SER STATIC o tener las variables declaradas internamente
                                //Sobrecarga
		}

	}
}
