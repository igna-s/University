package prog3.emprendimiento;

import prog3.arbolgeneral.ArbolGeneral;
import prog3.listagenerica.ListaGenerica;

public class Agua {

	public static float RedDeAguaPotable(ArbolGeneral<Character> a, float x) {

		float y, min = 99999999;
		int aux = 0;

		if (!a.esVacio()) {
			if (a.esHoja())
				return x;

			ListaGenerica<ArbolGeneral<Character>> lHijos = a.getHijos();
			if (a.tieneHijos()) {
				aux = lHijos.tamanio();
				lHijos.comenzar();
				while (!lHijos.fin()) {
					a = lHijos.proximo();
					y = RedDeAguaPotable(a, x / aux);
					if (y < min)
						min = y;
				}
				return min;
			}
		} 
		
		return min;
	}

}
