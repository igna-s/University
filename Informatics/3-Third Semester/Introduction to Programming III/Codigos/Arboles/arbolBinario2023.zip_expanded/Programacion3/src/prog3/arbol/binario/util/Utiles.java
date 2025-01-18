package prog3.arbol.binario.util;

import prog3.arbol.ArbolBinario;
import prog3.listagenerica.ColaGenerica;
import prog3.listagenerica.ListaGenericaEnlazada;

public class Utiles {

	public static int sumaMaximaVertical(ArbolBinario<Integer> a) {
		int x = 0, y = 0;

		if (a.tieneHijoIzquierdo()) {
			x = sumaMaximaVertical(a.getHijoIzquierdo());
		}
		if (a.tieneHijoDerecho()) {
			y = sumaMaximaVertical(a.getHijoDerecho());
		}
		if (a.esHoja())
			return a.getDato();

		if (x > y)
			return x + a.getDato();
		else
			return y + a.getDato();
	}

	public static int sumaMaximaHorizontal(ArbolBinario<Integer> a) throws Exception {

		ArbolBinario<Integer> arbol = null;
		ColaGenerica<ArbolBinario<Integer>> cola = new ColaGenerica<ArbolBinario<Integer>>();
		cola.encolar(a);
		cola.encolar(null);
		int tot = 0, max = -1;
		while (!cola.esVacia()) {
			arbol = cola.desencolar();
			if (arbol != null) {

				tot += arbol.getDato();

				if (arbol.tieneHijoIzquierdo()) {
					cola.encolar(arbol.getHijoIzquierdo());
				}
				if (arbol.tieneHijoDerecho()) {
					cola.encolar(arbol.getHijoDerecho());
				}
			} else {
				if (tot > max)
					max = tot;
				tot = 0;
				if (!cola.esVacia()) cola.encolar(null);
			}

		}

		return max;
	}
	
public static ListaGenericaEnlazada<Integer> trayectoriaPesada(ArbolBinario<Integer> a){
	ListaGenericaEnlazada<Integer> l = new ListaGenericaEnlazada<Integer>();
	///int nivel=0;
	///tot=0;
	l=pain(a,0,l,0);
	return l;
}
private static ListaGenericaEnlazada<Integer> pain(ArbolBinario<Integer> a,int nivel, ListaGenericaEnlazada<Integer> l, int tot){
	ListaGenericaEnlazada<Integer> x = new ListaGenericaEnlazada<Integer>();
	ListaGenericaEnlazada<Integer> y= new ListaGenericaEnlazada<Integer>();

	
	if (a.tieneHijoIzquierdo()) {
		x = pain(a.getHijoIzquierdo(),(nivel+1),l, (tot+a.getDato()*nivel));
		if (a.getHijoIzquierdo().esHoja())
		l.agregarFinal(x.elemento(0));
	}
	
	if (a.esHoja()) {
		x.agregarFinal(a.getDato()*nivel+tot);
		
		return x;	
		}
	
	if (a.tieneHijoDerecho()) {
		y = pain(a.getHijoDerecho(),(nivel+1),l,(tot+a.getDato()*nivel));
		if (a.getHijoDerecho().esHoja())
		l.agregarFinal(y.elemento(0));
	}
	
	return l;
}
}
