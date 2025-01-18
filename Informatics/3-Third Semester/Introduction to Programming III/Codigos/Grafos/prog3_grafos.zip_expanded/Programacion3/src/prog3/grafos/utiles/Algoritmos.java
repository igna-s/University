package prog3.grafos.utiles;

import prog3.grafos.*;
import prog3.listagenerica.ColaGenerica;
import prog3.listagenerica.ListaGenerica;
import prog3.listagenerica.ListaGenericaEnlazada;

public class Algoritmos<T> {

	/*
	 * Implemente en JAVA una clase llamada Algoritmos ubicada dentro del paquete
	 * prog3.grafos.utiles, cumpliendo la siguiente especificación: ●
	 * subgrafoCuadrado(Grafo<T> grafo): boolean // Retorna true si un dígrafo
	 * contiene un subgrafo cuadrado, false en caso contrario. Un subgrafo cuadrado
	 * es un ciclo simple de longitud 4. ● getGrado(Grafo<T> grafo) : int // Retorna
	 * el grado del digrafo pasado como parámetro. El grado de un digrafo es el de
	 * su vértice de grado máximo. El grado de un vértice en un grafo dirigido es la
	 * suma del número de aristas que salen de él (grado de salida) y el número de
	 * aristas que entran en él (grado de entrada). ● tieneCiclo(Grafo<T> grafo):
	 * boolean // Retorna true si el grafo dirigido pasado como parámetro tiene al
	 * menos un ciclo, false en caso contrario.
	 */

	public boolean subgrafoCuadrado(Grafo<T> grafo) {

		boolean[] visitados = new boolean[grafo.listaDeVertices().tamanio()];
		int i;
		boolean res = false;

		for (i = 0; i < visitados.length; i++) {
			res = recorrer(i, grafo, visitados, 0, i);

			if (res)
				break;
		}

		return res;
	}

	private boolean recorrer(int i, Grafo<T> grafo, boolean[] visitados, int ciclos, int pos) {

		boolean res = false;
		visitados[i] = true;

		Vertice<T> v = grafo.listaDeVertices().elemento(i);
		ListaGenerica<Arista<T>> a = grafo.listaDeAdyacentes(v);

		a.comenzar();
		while (!a.fin()) {
			int j = a.proximo().verticeDestino().posicion();

			if (!visitados[j]) {
				res = recorrer(j, grafo, visitados, ciclos + 1, pos);
			} else if ((j == pos) && (ciclos == 3))
				res = true;
			if (res)
				break;
		}

		visitados[i] = false;
		return res;
	}

	public boolean tieneCiclo(Grafo<T> grafo) {
		boolean res = false;
		int i;
		boolean[] visitado = new boolean[grafo.listaDeVertices().tamanio()];

		for (i = 0; i < visitado.length; i++) {
			res = tieneCiclo(i, grafo, visitado);
			if (res)break;
		}

		return res;
	}

	private boolean tieneCiclo(int i, Grafo<T> grafo, boolean[] visitado) {

		boolean exito = false;
		visitado[i] = true;

		Vertice<T> v = grafo.listaDeVertices().elemento(i);
		ListaGenerica<Arista<T>> a = grafo.listaDeAdyacentes(v);

		a.comenzar();
		while ((!a.fin()) && (!exito)) {
			int j = a.proximo().verticeDestino().posicion();
			if (!visitado[j]) {
				exito = tieneCiclo(j, grafo, visitado);}
			else
				{exito = true;}
		}
		
		return exito;
		
	}

	public int getGrado(Grafo<T> grafo) {
		boolean[] visitado = new boolean[grafo.listaDeVertices().tamanio()];
		int[] cant = new int[grafo.listaDeVertices().tamanio()];
		int i, max = -1;

		
		for (i = 0; i < grafo.listaDeVertices().tamanio(); i++) {
			getGrado(i, grafo, visitado, cant);
			}
		
		for (i = 0; i < grafo.listaDeVertices().tamanio(); i++) {
			System.out.println(cant[i]);
			if (cant[i] > max)
				max = cant[i];
			
		}
		return max;
	}

	private void getGrado(int i, Grafo<T> grafo, boolean[] visitado, int[] cant) {

		visitado[i] = true;
		Vertice<T> v = grafo.listaDeVertices().elemento(i);
		ListaGenerica<Arista<T>> a = grafo.listaDeAdyacentes(v);

		a.comenzar();
		while (!a.fin()) {

			int j = a.proximo().verticeDestino().posicion();
			cant[j]++;
			cant[i]++;
			
				
	/*	if (!visitado[j]) {
				getGrado(j, grafo, visitado, cant);  }*/
			
		}

		
		
	}
	
	
}