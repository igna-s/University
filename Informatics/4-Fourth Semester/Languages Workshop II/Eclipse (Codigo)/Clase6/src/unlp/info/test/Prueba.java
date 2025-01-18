package unlp.info.test;
import unlp.info.animal.*;
import unlp.info.animalespeligrosos.*;
import unlp.info.domestico.*;

public class Prueba {

	public static void main(String[] args) {

		PerroPeligroso gordo = new PerroPeligroso();
		gordo.ladra();
		gordo.mueveCola();
		gordo.muerde();
		PerroPeligroso rita = new PerroPeligroso();
		rita.muerde();
		rita.ladra();
		rita.mueveCola();

	}

	
	
}

///Che, faltaba el especificadorpublic para que tenga acceso


///El problema radica en que al Hacer AnimalPeligroso.ladra(), no esta definido en esa interfaz (Solucion= PerroPeligroso)