package prog3.listaenteros;

/**
 * La clase ListaDeEnterosEnlazada es una ListaDeEnteros, donde los elementos de
 * la lista (nodos) referencian al siguiente elemento (nodo), por este motivo,
 * la ListaDeEnterosEnlazada no tiene límite en la cantidad de elementos que se
 * pueden almacenar.
 */
public class ListaDeEnterosEnlazada extends ListaDeEnteros {
	/* primer nodo de la lista, si la lista esta vacia, inicio es null */
	private NodoEntero inicio;

	/*
	 * nodo actual que se va actualizando a medida que recorremos la lista, si la
	 * lista esta vacia, actual es null
	 */
	private NodoEntero actual;

	/* ultimo nodo de la lista, si la lista esta vacia, fin es null */
	private NodoEntero fin;

	/* cantidad de nodos en la lista */
	private int tamanio;

	@Override
	public void comenzar() {
		actual = inicio;
	}

	@Override
	public Integer proximo() {
		Integer elem = this.actual.getDato();
		this.actual = this.actual.getSiguiente();
		return elem;
	}

	@Override
	public boolean fin() {
		return (this.actual == null);
	}

	@Override
	public Integer elemento(int pos) {
		if (pos < 0 || pos > this.tamanio() - 1) // no es posicion valida
			return null;
		NodoEntero n = this.inicio;
		while (pos-- > 0)
			n = n.getSiguiente();
		return n.getDato();
	}

	@Override
	public boolean agregarEn(Integer elem, int pos) {
		if (pos < 0 || pos > this.tamanio()) // posicion no valida
			return false;
		this.tamanio++;
		NodoEntero aux = new NodoEntero();
		aux.setDato(elem);
		if (pos == 0) { // inserta al principio
			aux.setSiguiente(inicio);
			this.inicio = aux;
		} else {
			NodoEntero n = this.inicio;
			NodoEntero ant = null;
			int posActual = 0;
			while (!(n == null) && (posActual < pos)) {
				ant = n;
				n = n.getSiguiente();
				posActual++;
			}
			aux.setSiguiente(n);
			ant.setSiguiente(aux);

		}
		if (aux.getSiguiente() == null)
			this.fin = aux;
		return true;
	}

	@Override
	public boolean agregarInicio(Integer elem) {
		NodoEntero aux = new NodoEntero();
		aux.setDato(elem);

		if (this.inicio == null) {
			this.inicio = aux;
			this.actual = aux;
			this.fin = aux;
		} else {
			aux.setSiguiente(this.inicio);
			this.inicio = aux;
		}
		this.tamanio++;
		return true;
	}

	@Override
	public boolean agregarFinal(Integer elem) {
		NodoEntero aux = new NodoEntero();
		aux.setDato(elem);
		if (this.inicio == null) {
			this.inicio = aux;
			this.actual = aux;
			this.fin = aux;
		} else {

			fin.setSiguiente(aux);
			fin = aux;
		}
		tamanio++;
		return true;
	}

	@Override
	public boolean eliminar(Integer elem) {
		NodoEntero n = this.inicio;
		NodoEntero ant = null;
		while ((n != null) && (!n.getDato().equals(elem))) {
			ant = n;
			n = n.getSiguiente();
		}
		if (n == null)
			return false;
		else {
			if (ant == null)
				this.inicio = this.inicio.getSiguiente();
			else
				ant.setSiguiente(n.getSiguiente());
			this.tamanio--;

			return true;
		}
	}

	@Override
	public boolean eliminarEn(int pos) {
		if (pos < 0 || pos > this.tamanio() - 1) // posicion no valida
			return false;
		this.tamanio--;
		if (pos == 0) {
			this.inicio = this.inicio.getSiguiente();
			return true;
		}
		NodoEntero n = this.inicio;
		NodoEntero ant = null;
		while (!(n == null) && (pos > 0)) {
			pos--;
			ant = n;
			n = n.getSiguiente();
		}
		ant.setSiguiente(n.getSiguiente());
		if (ant.getSiguiente() == null)
			this.fin = ant;
		return true;
	}

	@Override
	public boolean incluye(Integer elem) {
		NodoEntero n = this.inicio;
		while (!(n == null) && !(n.getDato().equals(elem)))
			n = n.getSiguiente();
		return !(n == null);
	}

	@Override
	public String toString() {
		String str = "";
		NodoEntero n = this.inicio;
		while (n != null) {
			str = str + n.getDato() + " -> ";
			n = n.getSiguiente();
		}
		if (str.length() > 1)
			str = str.substring(0, str.length() - 4);
		return str;
	}

	@Override
	public int tamanio() {
		return this.tamanio;
	}

	@Override
	public boolean esVacia() {
		return this.tamanio() == 0;

	}

	public ListaDeEnterosEnlazada ordenar() {

		ListaDeEnterosEnlazada aux = new ListaDeEnterosEnlazada();
		this.comenzar();
		ListaDeEnterosEnlazada L = new ListaDeEnterosEnlazada();

		while (!this.fin()) {
			aux.agregarFinal(this.proximo());
		}
		int x, menor = 9999;

		while (!aux.esVacia()) {
			aux.comenzar();
			menor = 9999;

			while (!aux.fin()) {
				x = aux.proximo();
				if (x < menor) {
					menor = x;
				}
			}
			L.agregarFinal(menor);
			aux.eliminar(menor);
		}

		return L;

	}

	public ListaDeEnterosEnlazada combinarOrdenado(ListaDeEnterosEnlazada listaF) {

		ListaDeEnterosEnlazada lista1 = new ListaDeEnterosEnlazada();
		this.comenzar();
		while (!this.fin()) {
			lista1.agregarFinal(this.proximo());
		}
		lista1 = lista1.ordenar();

		ListaDeEnterosEnlazada lista2 = new ListaDeEnterosEnlazada();
		listaF.comenzar();
		while (!(listaF.fin())) {
			lista2.agregarFinal(listaF.proximo());
		}
		lista2 = lista2.ordenar();

		boolean esListaUno;
		// Verifique todo, ahora arranco;
		ListaDeEnterosEnlazada aux = new ListaDeEnterosEnlazada();
		int x;

		lista1.comenzar();
		lista2.comenzar();

		while ((!lista1.esVacia()) || (!lista2.esVacia())) {
			if (lista1.esVacia()) {
				esListaUno = false;
			} else if (lista2.esVacia()) {
				esListaUno = true;
			} else if (lista1.elemento(0) < lista2.elemento(0)) {
				esListaUno = true;
			} else {
				esListaUno = false;
			}

			if (esListaUno == true) {
				x = lista1.proximo();
				aux.agregarFinal(x);
				lista1.eliminar(x);
			} else {
				x = lista2.proximo();
				aux.agregarFinal(x);
				lista2.eliminar(x);
			}
		}

		return aux;
	}

	private ListaDeEnterosEnlazada combinacion(ListaDeEnterosEnlazada l, ListaDeEnterosEnlazada izq,
			ListaDeEnterosEnlazada der) {

		int x;
		der.comenzar();
		izq.comenzar();

		boolean esListaIzq;
		while ((!der.esVacia()) || (!izq.esVacia())) {
			if (izq.esVacia()) {
				esListaIzq = false;
			} else if (der.esVacia()) {
				esListaIzq = true;
			} else if (izq.elemento(0) < der.elemento(0)) {
				esListaIzq = true;
			} else {
				esListaIzq = false;
			}

			if (esListaIzq == true) {
				x = izq.proximo();
				l.agregarFinal(x);
				izq.eliminar(x);
			} else {
				x = der.proximo();
				l.agregarFinal(x);
				der.eliminar(x);
			}

		}
		return l;
	}

	public ListaDeEnterosEnlazada mergeSortMethod() {

		int x, j, fin;
		if (this.tamanio() <= 1)
			return this;

		else {
			ListaDeEnterosEnlazada l = new ListaDeEnterosEnlazada();
			ListaDeEnterosEnlazada izq = new ListaDeEnterosEnlazada();
			ListaDeEnterosEnlazada der = new ListaDeEnterosEnlazada();

			this.comenzar();
			x = ((this.tamanio()) / 2);
			fin =this.tamanio();

			l.comenzar();
			izq.comenzar();
			der.comenzar();

			for (j = 0; j < x; j++) {
				izq.agregarFinal(this.proximo());

			}

			for (j = x; j < fin; j++) {
				der.agregarFinal(this.proximo());

			}
			izq = izq.mergeSortMethod();
			der = der.mergeSortMethod();

			l = combinacion(l, izq, der);
			return l;

		}

	}

}
