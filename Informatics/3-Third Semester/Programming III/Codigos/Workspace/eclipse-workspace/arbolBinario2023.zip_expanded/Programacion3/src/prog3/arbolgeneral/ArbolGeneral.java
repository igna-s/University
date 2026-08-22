package prog3.arbolgeneral;



import prog3.listagenerica.ColaGenerica;
import prog3.listagenerica.ListaGenerica;
import prog3.listagenerica.ListaGenericaEnlazada;

public class ArbolGeneral<T> {

	private T dato;

	private ListaGenerica<ArbolGeneral<T>> hijos = new ListaGenericaEnlazada<ArbolGeneral<T>>();

	public T getDato() {
		return dato;
	}

	public void setDato(T dato) {
		this.dato = dato;
	}

	public void setHijos(ListaGenerica<ArbolGeneral<T>> hijos) {
		this.hijos = hijos;
	}

	public ArbolGeneral() {
	};

	public ArbolGeneral(T dato) {
		this.dato = dato;
		this.hijos = new ListaGenericaEnlazada<ArbolGeneral<T>>();
	}

	public ArbolGeneral(T dato, ListaGenerica<ArbolGeneral<T>> hijos) {
		this(dato);
		this.hijos = hijos;
	}

	public ListaGenerica<ArbolGeneral<T>> getHijos() {
		return this.hijos;
	}

	public void agregarHijo(ArbolGeneral<T> unHijo) {

		this.getHijos().agregarFinal(unHijo);
	}

	public boolean esHoja() {

		return !this.tieneHijos();
	}

	public boolean tieneHijos() {
		return this.hijos != null && !this.hijos.esVacia();
	}

	public boolean esVacio() {

		return this.dato == null && !this.tieneHijos();
	}

	public void eliminarHijo(ArbolGeneral<T> hijo) {
		if (this.tieneHijos()) {
			ListaGenerica<ArbolGeneral<T>> hijos = this.getHijos();
			if (hijos.incluye(hijo))
				hijos.eliminar(hijo);
		}
	}

	public void preOrden() {
		

			if (!this.esVacio()) {

					System.out.println(this.dato);				

			
					ListaGenerica<ArbolGeneral<T>> lista = this.getHijos();
					ArbolGeneral<T> arbol = null;
					lista.comenzar();

					while (!lista.fin()) {
						arbol = lista.proximo();
		                arbol.preOrden();}

		}}

	

	public Integer altura() {

		if (!this.esVacio()) {

			if (this.esHoja())
				return 0;

			else {
				ListaGenerica<ArbolGeneral<T>> lista = this.getHijos();
				ArbolGeneral<T> arbol = null;
				int maximo = 0, act = 0;

				lista.comenzar();

				while (!lista.fin()) {
					arbol = lista.proximo();
					act = arbol.altura();
					if (maximo < act)
						maximo = act;
				}

				return maximo + 1;
			}
		}
		return 0;
	}

	public boolean include(T dato) {

		if (!this.esVacio()) {
			if (this.esHoja()) {
				if (this.getDato() == dato)
					return true;
			}

			else {
				ListaGenerica<ArbolGeneral<T>> lista = this.getHijos();
				ArbolGeneral<T> arbol = null;
				boolean esTrue = false;

				lista.comenzar();

				while ((!lista.fin()) && (!esTrue)) {
					arbol = lista.proximo();
					if (this.getDato() == dato)
						esTrue = true;
					else
						esTrue = arbol.include(dato);
				}

				return esTrue;
			}
		}
		return false;

	}

	public Integer nivel(T dato) {

		if (!this.esVacio()) {

			if (this.esHoja()) {
				if (this.dato == dato)
					return 0;
			}

			else {
				ListaGenerica<ArbolGeneral<T>> lista = this.getHijos();
				ArbolGeneral<T> arbol = null;

				int Res = -1;
				lista.comenzar();

				while ((!lista.fin()) && (Res == -1)) {
					arbol = lista.proximo();
					if (this.dato == dato)
						return 0;
					Res = arbol.nivel(dato);

				}
				if (Res > -1)
					return Res + 1;
			}
		}
		return -1;
	}

	public Integer ancho() throws Exception {
		ArbolGeneral<T> arbol = null;
		ColaGenerica<ArbolGeneral<T>> cola = new ColaGenerica<ArbolGeneral<T>>();
		ListaGenerica<ArbolGeneral<T>> l;
		int max = -1, tot = 0;

		cola.encolar(this);
		cola.encolar(null);
		while (!cola.esVacia()) {
			arbol = cola.desencolar();
			if (arbol != null) {
				l = arbol.getHijos();
				tot++;
				l.comenzar();
				while (!l.fin()) {
					cola.encolar(l.proximo());
					
				}
			} else {
				if (tot > max)
					max = tot;
				tot = 0;
				if (!cola.esVacia())
				cola.encolar(null);

			}
		}
		return max;
	}
}