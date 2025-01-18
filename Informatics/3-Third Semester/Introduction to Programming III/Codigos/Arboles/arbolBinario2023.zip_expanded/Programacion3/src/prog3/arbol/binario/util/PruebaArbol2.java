package prog3.arbol.binario.util;

import prog3.arbol.ArbolBinario;
import prog3.listagenerica.ListaGenericaEnlazada;




public class PruebaArbol2 {

	public static void main(String[] args) throws Exception {
		
     ///Clase 4_A
      
       
       
		ArbolBinario<Integer> arbolBinarioB=new ArbolBinario<Integer>(1);
		ArbolBinario<Integer> hijoIzquierdoB=new ArbolBinario<Integer>(2);
		ArbolBinario<Integer> REST=new ArbolBinario<Integer>(3);		
		REST.agregarHijoIzquierdo(new ArbolBinario<Integer>(4));
		
		hijoIzquierdoB.agregarHijoIzquierdo(REST);
		hijoIzquierdoB.agregarHijoDerecho(new ArbolBinario<Integer>(5));
		ArbolBinario<Integer> hijoDerechoB=new ArbolBinario<Integer>(6);
		hijoDerechoB.agregarHijoIzquierdo(new ArbolBinario<Integer>(7));
         hijoDerechoB.agregarHijoDerecho(new ArbolBinario<Integer>(8));
		arbolBinarioB.agregarHijoIzquierdo(hijoIzquierdoB);
		arbolBinarioB.agregarHijoDerecho(hijoDerechoB);
		
		ArbolBinario<Integer> a=new ArbolBinario<Integer>(1);
		a=arbolBinarioB;

     	
	///Clase 4_B
     	
     	ArbolBinario<String> aB=new ArbolBinario<String>("Tiene 4 patas");
		ArbolBinario<String> hijoB=new ArbolBinario<String>("Se mueve");
		
		ArbolBinario<String> RES=new ArbolBinario<String>("Ladra");		
	///	RES.agregarHijoIzquierdo(new ArbolBinario<String>("ES UN PERRO"));
		
		hijoB.agregarHijoIzquierdo(RES);
		hijoB.agregarHijoDerecho(new ArbolBinario<String>("ES UNA MESA"));
		
		ArbolBinario<String> hijoDB=new ArbolBinario<String>("Tiene alguna pata");
		hijoDB.agregarHijoIzquierdo(new ArbolBinario<String>("ES UN PIRATA"));
         hijoDB.agregarHijoDerecho(new ArbolBinario<String>("ES UN CARRO"));
		aB.agregarHijoIzquierdo(hijoB);
		aB.agregarHijoDerecho(hijoDB);
     	
		ArbolBinario<String> aString=aB;
		
		System.out.println(Utiles.sumaMaximaVertical(a));
		System.out.println(Utiles.sumaMaximaHorizontal(a));
		System.out.println(Adivinanza.secuenciaConMasPreguntas(aString));
		a.recorridoPorNiveles();
     	System.out.println("");
		System.out.println(Utiles.trayectoriaPesada(a));
		
		ListaGenericaEnlazada<ListaGenericaEnlazada<String>> lista= new ListaGenericaEnlazada<ListaGenericaEnlazada<String>>();
		lista=Adivinanza.secuenciaConMasPreguntas2(aString); 
		
		int i=0;
		for (i=0;i<lista.tamanio();i++)
		     System.out.println(lista.elemento(i));
	}

}
