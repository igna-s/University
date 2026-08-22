package prog3.grafos.utiles;

import prog3.grafos.*;
import prog3.listagenerica.*;

public class Recorridos<T> {

	public ListaGenericaEnlazada<Vertice<T>> dfs(Grafo<T> grafo) {
		boolean[] marca = new boolean[grafo.listaDeVertices().tamanio()];
		ListaGenericaEnlazada<Vertice<T>> lis = new ListaGenericaEnlazada<Vertice<T>>();
		for (int i = 0; i < marca.length; i++) {
			if (!marca[i])
				this.dfs(i, grafo, lis, marca);
		}
		return lis;
	}

	private void dfs(int i, Grafo<T> grafo, ListaGenericaEnlazada<Vertice<T>> lis, boolean[] marca) {
		marca[i] = true;
		Vertice<T> v = grafo.listaDeVertices().elemento(i);
		lis.agregarFinal(v);
		System.out.println(v.dato());
		ListaGenerica<Arista<T>> ady = grafo.listaDeAdyacentes(v);
		ady.comenzar();
		while (!ady.fin()) {
			int j = ady.proximo().verticeDestino().posicion();
			if (!marca[j]) {
				this.dfs(j, grafo, lis, marca);
			}
		}
	}

/////----------------------------------------------------------------

	public ListaGenericaEnlazada<Vertice<T>> bfs(Grafo<T> grafo) {
		boolean[] marca = new boolean[grafo.listaDeVertices().tamanio()];
		ListaGenericaEnlazada<Vertice<T>> lis = new ListaGenericaEnlazada<Vertice<T>>();
		for (int i = 0; i < marca.length; i++) {
			if (!marca[i])
				this.bfs(i, grafo, marca,lis);

		}
       return lis;
	}

	private void bfs(int i, Grafo<T> grafo, boolean[] marca, ListaGenericaEnlazada<Vertice<T>> lis) {
		ListaGenerica<Arista<T>> ady = null;
		ColaGenerica<Vertice<T>> q = new ColaGenerica<Vertice<T>>();
		q.encolar((grafo.listaDeVertices().elemento(i)));
		marca[i] = true;

		while (!q.esVacia()) {
			Vertice<T> v = q.desencolar();
			lis.agregarFinal(v);
			System.out.println(v.dato());
			ady = grafo.listaDeAdyacentes(v);
			ady.comenzar();
			
			while (!ady.fin()) {
                Arista<T> arista=ady.proximo();
                int j= arista.verticeDestino().posicion();
                
                if (!marca[j]) {
                	
                	Vertice<T> w = arista.verticeDestino();
                	marca[j]=true;
                	q.encolar(w);
                	
                }
			}
		}

	}

}
