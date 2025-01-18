package prog3.arbol.binario.util;

import prog3.arbol.ArbolBinario;
import prog3.listagenerica.ListaGenericaEnlazada;

public class Adivinanza {

	public static ListaGenericaEnlazada<String> secuenciaConMasPreguntas(ArbolBinario<String> a) {
		ListaGenericaEnlazada<String> l = new ListaGenericaEnlazada<String>();
		ListaGenericaEnlazada<String> l2 = new ListaGenericaEnlazada<String>();

		if (a.tieneHijoIzquierdo()) {
			l = secuenciaConMasPreguntas(a.getHijoIzquierdo());
			l.agregarInicio("SI");
		}

		if (a.tieneHijoDerecho()) {
			l2 = secuenciaConMasPreguntas(a.getHijoDerecho());
			l2.agregarInicio("NO");
		}

		if (a.esHoja()) {
			l.agregarInicio(a.getDato());
			return l;
		}
		if (l.tamanio() < l2.tamanio()) {
			l2.agregarInicio(a.getDato());
			return l2;
		} else {
			l.agregarInicio(a.getDato());
			return l;

		}
	}

	public static ListaGenericaEnlazada<ListaGenericaEnlazada<String>> secuenciaConMasPreguntas2(ArbolBinario<String> a) {

		ListaGenericaEnlazada<String> aux = new ListaGenericaEnlazada<String>();
		ListaGenericaEnlazada<ListaGenericaEnlazada<String>> l1 = new ListaGenericaEnlazada<ListaGenericaEnlazada<String>>();
		ListaGenericaEnlazada<ListaGenericaEnlazada<String>> l2 = new ListaGenericaEnlazada<ListaGenericaEnlazada<String>>();
		ListaGenericaEnlazada<ListaGenericaEnlazada<String>> ret = new ListaGenericaEnlazada<ListaGenericaEnlazada<String>>();
		int x;

		if (a.tieneHijoIzquierdo()) {
			l1 = secuenciaConMasPreguntas2(a.getHijoIzquierdo());
			l1.comenzar();
			for (x = 0; x < l1.tamanio(); x++) {
				aux = l1.elemento(x);
				l1.eliminarEn(x);
				aux.agregarInicio("SI");
				aux.agregarInicio(a.getDato());
				l1.agregarInicio(aux);
			}

		}

		if (a.tieneHijoDerecho()) {
			l2 = secuenciaConMasPreguntas2(a.getHijoDerecho());
			l2.comenzar();
			for (x = 0; x < l1.tamanio(); x++) {
				aux = l2.elemento(x);
				l2.eliminarEn(x);
				aux.agregarInicio("SI");
				aux.agregarInicio(a.getDato());
				l2.agregarInicio(aux);
			}
		}

		if (a.esHoja()) {
			aux.agregarInicio(a.getDato());
			l1.agregarInicio(aux);
			return l1;
		}

		
		//////////Analisis devolucion/////////
       if (l1.tamanio()==0)
    	   return l2;
       
       if (l2.tamanio()==0)
    	   return l1;
		
		if (l1.elemento(0).tamanio() == l2.elemento(0).tamanio()) {
		   l1.comenzar();
		   l2.comenzar();
		   for (x=0;x<l1.tamanio();x++) 
			   ret.agregarInicio(l1.proximo());
		   for (x=0;x<l2.tamanio();x++) 
			   ret.agregarInicio(l2.proximo());  
			return ret;   
		
		}

		else if (l1.elemento(0).tamanio() < l2.elemento(0).tamanio())
			return l2;
		else
			return l1;

	}
}
