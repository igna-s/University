package prog3.arbol;

import prog3.listagenerica.*;

public class ArbolBinario<T> {
	private T dato;
	private ArbolBinario<T> hijoIzquierdo;
	private ArbolBinario<T> hijoDerecho;

	public ArbolBinario() {
		super();
	}

	public ArbolBinario(T dato) {
		this.dato = dato;
	}

	/*
	 * getters y setters
	 * 
	 */
	public T getDato() {
		return dato;
	}

	public void setDato(T dato) {
		this.dato = dato;
	}

	public ArbolBinario<T> getHijoIzquierdo() {
		return this.hijoIzquierdo;
	}

	public ArbolBinario<T> getHijoDerecho() {
		return this.hijoDerecho;

	}

	public void agregarHijoIzquierdo(ArbolBinario<T> hijo) {
		this.hijoIzquierdo = hijo;
	}

	public void agregarHijoDerecho(ArbolBinario<T> hijo) {
		this.hijoDerecho = hijo;
	}

	public void eliminarHijoIzquierdo() {
		this.hijoIzquierdo = null;
	}

	public void eliminarHijoDerecho() {
		this.hijoDerecho = null;
	}

	public boolean esVacio() {
		return this.getDato() == null && !this.tieneHijoIzquierdo() && !this.tieneHijoDerecho();
	}

	public boolean esHoja() {
		return (!this.tieneHijoIzquierdo() && !this.tieneHijoDerecho());

	}

	@Override
	public String toString() {
		return this.getDato().toString();
	}

	public boolean tieneHijoIzquierdo() {
		return this.hijoIzquierdo != null;
	}

	public boolean tieneHijoDerecho() {
		return this.hijoDerecho != null;
	}

	public boolean esLleno() throws Exception {
		

			ArbolBinario<T> arbol = null;
			ColaGenerica<ArbolBinario<T>> cola = new ColaGenerica<ArbolBinario<T>>();
			cola.encolar(this);
			cola.encolar(null);
			int cantidad=0;
			int nivel=0;
			boolean lleno=true;
			while ((!cola.esVacia())&&(lleno)) {
				arbol = cola.desencolar();
				if (arbol != null) {
					if (arbol.tieneHijoIzquierdo()) {
						cola.encolar(arbol.getHijoIzquierdo());
						cantidad++;
					}
					if (arbol.tieneHijoDerecho()) {
						cola.encolar(arbol.getHijoDerecho());
						cantidad++;
					}
				} else if (!cola.esVacia()) {
					
					if  (cantidad == Math.pow(2, ++nivel)) {
					cantidad=0;
					cola.encolar(null);
				}
					else lleno=false;
			}
			
		}
			return lleno;}

	boolean esCompleto() {

		/*
		 * Haria un recorrido es lleno, pero me fijaria: Si tiene hijo izq y der
		 * continuar: 1 Si tiene solo hijo derecho continuar: 0 y devuelvo false Si
		 * tiene solo hijo izquierdo continuar:2, y si aparece otra hoja continuar: 0 y
		 * devuelvo false si llega al final con 1 o 2 es Completo
		 */
		return false;
	}

	// imprime el arbol en preorden
	public void printPreorden() {
		System.out.print(" " + this.getDato() + " ");
		if (this.tieneHijoIzquierdo()) {
			this.getHijoIzquierdo().printPreorden();
		}
		if (tieneHijoDerecho()) {
			this.getHijoDerecho().printPreorden();
		}
	}

	// imprime el arbol en postorden
	public void printInorden() {

		if (this.tieneHijoIzquierdo()) {
			this.getHijoIzquierdo().printInorden();
		}
		System.out.print(" " + this.getDato() + " ");
		if (tieneHijoDerecho()) {
			this.getHijoDerecho().printInorden();
		}
	}

	// imprime el arbol en postorden
	public void printPostorden() {

		if (this.tieneHijoIzquierdo()) {
			this.getHijoIzquierdo().printPostorden();
		}
		if (tieneHijoDerecho()) {
			this.getHijoDerecho().printPostorden();
		}
		System.out.print(" " + this.getDato() + " ");

	}

	public void recorridoPorNiveles() throws Exception {

		ArbolBinario<T> arbol = null;
		ColaGenerica<ArbolBinario<T>> cola = new ColaGenerica<ArbolBinario<T>>();
		cola.encolar(this);
		cola.encolar(null);
		while (!cola.esVacia()) {
			arbol = cola.desencolar();
			if (arbol != null) {
				System.out.print(arbol.getDato() +" ");
				if (arbol.tieneHijoIzquierdo()) {
					cola.encolar(arbol.getHijoIzquierdo());
				}
				if (arbol.tieneHijoDerecho()) {
					cola.encolar(arbol.getHijoDerecho());
				}
			} else if (!cola.esVacia()) {
				cola.encolar(null);
				System.out.println();
			}
		}
	}

	public ListaGenerica<T> frontera() {
		ListaGenerica<T> l = new ListaGenericaEnlazada<T>();
		l=front(l);
		return l;
	}
	private ListaGenerica<T> front(ListaGenerica<T> l) {
		
		if (this.tieneHijoIzquierdo()) {
			this.getHijoIzquierdo().front(l);
		}

		if (tieneHijoDerecho()) {
			this.getHijoDerecho().front(l);
		}
		if (this.esHoja()) {
			l.agregarFinal(this.getDato());
		}
       return l; 
		
	}

	public int contarHojas() {
		int hojas = 0;

		if (this.esHoja())
			return 1; // Caso Base

		if (this.tieneHijoIzquierdo())
			hojas += this.hijoIzquierdo.contarHojas();

		if (tieneHijoDerecho())
			hojas += this.hijoDerecho.contarHojas();

		return hojas;
	}

}
