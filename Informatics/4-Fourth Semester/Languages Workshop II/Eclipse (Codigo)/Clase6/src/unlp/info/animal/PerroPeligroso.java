package unlp.info.animal;

import unlp.info.animalespeligrosos.AnimalPeligroso;
import unlp.info.domestico.PerroDomestico;

public class PerroPeligroso implements AnimalPeligroso, PerroDomestico {
	public void muerde() {
		System.out.println("GRRRR!");
	}

	public void ladra() {
		System.out.println("GUAU GUAU!");
	}

	public void mueveCola() {
		System.out.println("Mueve cola");
	}
}