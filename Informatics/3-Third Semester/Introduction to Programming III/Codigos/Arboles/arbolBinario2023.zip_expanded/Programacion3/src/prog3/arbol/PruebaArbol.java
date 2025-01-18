package prog3.arbol;


import prog3.listagenerica.ListaGenerica;
import prog3.listagenerica.ListaGenericaEnlazada;


public class PruebaArbol {

	public static void main(String[] args) throws Exception {
		
      ///Clase 4_A
      
       
       
		ArbolBinario<Integer> arbolBinarioB=new ArbolBinario<Integer>(1);
		ArbolBinario<Integer> hijoIzquierdoB=new ArbolBinario<Integer>(2);
		hijoIzquierdoB.agregarHijoIzquierdo(new ArbolBinario<Integer>(3));
		hijoIzquierdoB.agregarHijoDerecho(new ArbolBinario<Integer>(4));
		ArbolBinario<Integer> hijoDerechoB=new ArbolBinario<Integer>(6);
		hijoDerechoB.agregarHijoIzquierdo(new ArbolBinario<Integer>(7));
         hijoDerechoB.agregarHijoDerecho(new ArbolBinario<Integer>(8));
		arbolBinarioB.agregarHijoIzquierdo(hijoIzquierdoB);
		arbolBinarioB.agregarHijoDerecho(hijoDerechoB);
		
		ArbolBinario<Integer> a=new ArbolBinario<Integer>(1);
		a=arbolBinarioB;
				
     	a.printPreorden();
		System.out.println("");
		a.printInorden();
		System.out.println("");
		a.printPostorden();
		System.out.println("");
		System.out.println(a.contarHojas());
     	a.recorridoPorNiveles();
     	System.out.println("");
     	
     	ListaGenerica<Integer> l = new ListaGenericaEnlazada<Integer>();
     	l=a.frontera();
     	System.out.println(l.toString());
     	
     	System.out.println("¿Es lleno? "+a.esLleno()); 
     	
	}

}
