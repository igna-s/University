package prog3.emprendimiento;

import prog3.arbolgeneral.ArbolGeneral;
import prog3.listagenerica.ColaGenerica;
import prog3.listagenerica.ListaGenerica;
import prog3.listagenerica.ListaGenericaEnlazada;

public class Empresa extends Empleado {
	private ArbolGeneral<Empleado> emple = new ArbolGeneral<Empleado>();

	public Empresa() {
	}

	public Empresa(ArbolGeneral<Empleado> emple) {
		this.emple = emple;
	}

	public int empleadosPorCategoria(int categoria) throws Exception {
		ArbolGeneral<Empleado> arbol = null;
		ColaGenerica<ArbolGeneral<Empleado>> cola = new ColaGenerica<ArbolGeneral<Empleado>>();
		ListaGenerica<ArbolGeneral<Empleado>> l;
		cola.encolar(emple);
		cola.encolar(null);

		categoria--;
		int total = 0, nivel = 0;

		while ((!cola.esVacia()) && (nivel <= categoria)) {
			arbol = cola.desencolar();
			if (arbol != null) {
				l = arbol.getHijos();
				l.comenzar();

				if (nivel == categoria)
					while (!cola.esVacia()) {
						cola.desencolar();
						total++;
					}
				else
					while (!l.fin()) {
						cola.encolar(l.proximo());
					}
			} else {
				if (!cola.esVacia()) {
					cola.encolar(null);
					total = 0;
					nivel++;
				}
			}
		}

		return total;
	}

	public int categoriaConMasEmpleados() throws Exception {
		ArbolGeneral<Empleado> arbol = null;
		ColaGenerica<ArbolGeneral<Empleado>> cola = new ColaGenerica<ArbolGeneral<Empleado>>();
		ListaGenerica<ArbolGeneral<Empleado>> l;
		cola.encolar(emple);
		cola.encolar(null);

		int max = -1, maxNv = -1;
		int total = 0, nivel = 0;

		while (!cola.esVacia()) {
			arbol = cola.desencolar();
			if (arbol != null) {
				l = arbol.getHijos();
				l.comenzar();
				total++;
				while (!l.fin()) {
					cola.encolar(l.proximo());
				}
			} else {

				if (max < total) {
					max = total;
					maxNv = nivel;
				}

				if (!cola.esVacia()) {
					cola.encolar(null);
					total = 0;
					nivel++;
				}
			}
		}
		return ++maxNv;
	}

	public int cantidadTotalDeEmpleados() throws Exception {
		ArbolGeneral<Empleado> arbol = null;
		ColaGenerica<ArbolGeneral<Empleado>> cola = new ColaGenerica<ArbolGeneral<Empleado>>();
		ListaGenerica<ArbolGeneral<Empleado>> l;
		cola.encolar(emple);
		cola.encolar(null);

		int total = 0;

		while (!cola.esVacia()) {
			arbol = cola.desencolar();
			if (arbol != null) {
				l = arbol.getHijos();
				l.comenzar();
				total++;
				while (!l.fin()) {
					cola.encolar(l.proximo());
				}
			} else {
				if (!cola.esVacia()) {
					cola.encolar(null);
				}
			}
		}
		return total;
	}

	public void reemplazarPresidente() {
		int max;

		ArbolGeneral<Empleado> aux = null, e = new ArbolGeneral<Empleado>(), arbol = emple;
		Empleado reemplazo = new Empleado();
		ListaGenerica<ArbolGeneral<Empleado>> l = emple.getHijos();

		for (int i = 0; i < 4; i++) {

			l = arbol.getHijos();      max = 0;

			if (!l.esVacia()) {
				l.comenzar();

				while (!l.fin()) {
					e = l.proximo();

					if (e.getDato().getAntiguedad() > max) {
						max = e.getDato().getAntiguedad();
						reemplazo = e.getDato();
						aux = e;
					}
				}
				arbol.setDato(reemplazo);
				if (!aux.esHoja())
					arbol = aux;
				else {
					arbol.eliminarHijo(aux);
					break;
				}
			}
		}}

	public void imprimir() throws Exception {

		ListaGenerica<Empleado> result = new ListaGenericaEnlazada<Empleado>();
		ColaGenerica<ArbolGeneral<Empleado>> cola = new ColaGenerica<ArbolGeneral<Empleado>>();
		ArbolGeneral<Empleado> arbol_aux;
		Empleado aux;
		cola.encolar(emple);
		cola.encolar(null);
		int nivel = 1;

		while (!cola.esVacia()) {
			arbol_aux = cola.desencolar();
			if (arbol_aux != null) {
				result.agregarFinal(arbol_aux.getDato());
				aux = arbol_aux.getDato();
				System.out.print(" " + aux.toString() + "|");

				if (arbol_aux.tieneHijos()) {
					ListaGenerica<ArbolGeneral<Empleado>> hijos = arbol_aux.getHijos();
					hijos.comenzar();
					while (!hijos.fin()) {
						cola.encolar(hijos.proximo());
					}

				}

			}

			else {
				if (!cola.esVacia())
					cola.encolar(null);
				System.out.print(" Nivel " + nivel);
				System.out.println("");
				nivel++;
			}
		}

	}
}