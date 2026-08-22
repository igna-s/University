package prog3.grafos.utiles;

import prog3.grafos.*;
import prog3.listagenerica.*;

/*● caminoConMenorNrodeViajes(Grafo<String> grafo, String puntoInteresOrigen, String
puntoInteresDestino) : ListaGenerica <String> // Retorna la lista de puntos de interés que
se deben atravesar en el grafo para ir de puntoInteresOrigen a puntoInteresDestino,
haciendo la menor cantidad de viajes.*/
public class GuiaDeTurismo<T> {

	ListaGenerica<String> caminoConMenorNrodeViajes(Grafo<String> grafo, String Origen, String destino) {
		boolean[] visitados = new boolean[grafo.listaDeVertices().tamanio()];
		ListaGenericaEnlazada<Integer> min = new ListaGenericaEnlazada<Integer>();
		min.agregarInicio(-1);
		ListaGenericaEnlazada<String> aux = new ListaGenericaEnlazada<String>();
		ListaGenericaEnlazada<String> camino = new ListaGenericaEnlazada<String>();

		for (int i = 0; i < visitados.length; i++) {
			if (grafo.vertice(i).dato().equals(Origen)) {
				caminoConMenor(i, grafo, visitados, destino, camino, aux, min,0);
				break;
			}

		}

		return camino;
	}

	private void caminoConMenor(int i, Grafo<String> grafo, boolean[] visitados, String destino,
			ListaGenericaEnlazada<String> camino, ListaGenericaEnlazada<String> aux,
			ListaGenericaEnlazada<Integer> min,int act) {

		visitados[i] = true;
		Vertice<String> v = grafo.vertice(i);
		ListaGenerica<Arista<String>> a = grafo.listaDeAdyacentes(v);
		aux.agregarFinal(v.dato());
		
		if ((destino.equals(v.dato()))&&(act>min.elemento(0))) {
       	 Operar (camino,aux,min,act);
        }

		a.comenzar();
		while (!a.fin()) {
		Arista<String> arista = a.proximo();
		int j= arista.verticeDestino().posicion();
             
        if  ((!visitados[j])){
            	 if (arista.peso()<act) caminoConMenor(j, grafo, visitados, destino, camino, aux, min,arista.peso());
            	 else caminoConMenor(j, grafo, visitados, destino, camino, aux, min,act);
             }
		}
	
		visitados[i] = false;
		aux.eliminarEn(aux.tamanio() - 1);

	}

	private void Operar(ListaGenericaEnlazada<String> camino, ListaGenericaEnlazada<String> aux,ListaGenericaEnlazada<Integer> min, int act) {
		
		
		camino.comenzar();
		while (!camino.esVacia()) {
			camino.eliminarEn(0);
		}
		aux.comenzar();
		while(!aux.fin()) {
			camino.agregarFinal(aux.proximo());
		}
		
		min.eliminarEn(0);
		min.agregarInicio(act);
		
	}
}
