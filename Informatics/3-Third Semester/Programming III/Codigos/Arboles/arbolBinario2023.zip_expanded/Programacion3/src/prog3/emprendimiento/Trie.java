package prog3.emprendimiento;

import prog3.arbolgeneral.*;
import prog3.listagenerica.ColaGenerica;
import prog3.listagenerica.ListaGenerica;
import prog3.listagenerica.ListaGenericaEnlazada;

public class Trie {

	private ArbolGeneral<Character> t;

	public Trie() {
		super();
		ArbolGeneral<Character> a= new ArbolGeneral<Character>(' ');
        this.t=a;
	}

	public Trie(ArbolGeneral<Character> t) {
		super();
		this.t = t;
	}

	public ArbolGeneral<Character> getT() {
		return t;
	}

	public void setT(ArbolGeneral<Character> t) {
		this.t = t;
	}

	public void agregarPalabra(String palabra) {
		agregacion(palabra, t);
	}

	private void agregacion(String palabra, ArbolGeneral<Character> Arbol) {

		if (!(palabra.length() == 0)) {
				char x;
				ListaGenerica<ArbolGeneral<Character>> l;
				x = palabra.charAt(0);
				palabra = palabra.substring(1);
				int aux = 0;
				ArbolGeneral<Character> a = new ArbolGeneral<Character>(x);
				ArbolGeneral<Character> b = new ArbolGeneral<Character>();
				boolean noagregue = true;
				l = Arbol.getHijos();
                l.comenzar();
				if (!l.esVacia()) {
					while ((!l.fin()) && (noagregue)) {
						b = l.proximo();
						if (b.getDato() > x) {
							noagregue = false;
							l.agregarEn(a, aux);
							agregacion(palabra, b);
							
						} else if (b.getDato() == x) {
							noagregue = false;
							agregacion(palabra, b);
				
						}
						aux++;
					}
					
				} 
				if (noagregue) {
					l.agregarInicio(a);
					agregacion(palabra, a);
					
				}
			}
		}
	

	public ListaGenericaEnlazada<String> palabrasQueEmpiezanCon(String x) {
		ListaGenericaEnlazada<String> l=new ListaGenericaEnlazada<String>();
		///esteRecorrido (l,t,x,0);
		return l;
	}	
	private void esteRecorrido(ListaGenericaEnlazada<String> l, ArbolGeneral<Character> t , String x,int nivel){	
		if (!t.esVacio()) {

			ListaGenerica<ArbolGeneral<Character>> lista;
			ArbolGeneral<Character> a= new ArbolGeneral<Character>();
			lista=t.getHijos();
			lista.comenzar();
			
			while (!lista.fin()) {
				a = lista.proximo();
				if (x.charAt(nivel)==a.getDato()||(a.getDato()==' '))
                     esteRecorrido(l,a,x.substring(1),nivel++);
				}

}

	}

	public void imprimir2() {t.preOrden();}
	public void imprimir() throws Exception {

		ListaGenerica<Character> result = new ListaGenericaEnlazada<Character>();
		ColaGenerica<ArbolGeneral<Character>> cola = new ColaGenerica<ArbolGeneral<Character>>();
		ArbolGeneral<Character> arbol_aux;
		cola.encolar(t);
		cola.encolar(null);

		while (!cola.esVacia()) {
			arbol_aux = cola.desencolar();
			if (arbol_aux != null) {
				result.agregarFinal(arbol_aux.getDato());
	
				System.out.print(arbol_aux.getDato());

				if (arbol_aux.tieneHijos()) {
					ListaGenerica<ArbolGeneral<Character>> hijos = arbol_aux.getHijos();
					hijos.comenzar();
					while (!hijos.fin()) {
						cola.encolar(hijos.proximo());
					}

				}

			}

			else {
				if (!cola.esVacia())
					cola.encolar(null);
				System.out.println("");
		
			}
		}

	}
}
