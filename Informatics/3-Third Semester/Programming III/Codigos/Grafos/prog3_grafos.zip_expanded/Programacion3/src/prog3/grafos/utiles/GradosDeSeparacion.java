package prog3.grafos.utiles;

import prog3.grafos.Arista;
import prog3.grafos.Grafo;
import prog3.grafos.Vertice;
import prog3.listagenerica.ColaGenerica;
import prog3.listagenerica.ListaGenerica;
import prog3.listagenerica.ListaGenericaEnlazada;

public class GradosDeSeparacion {

	public static int maximoGradoDeSeparacion(Grafo<String> grafo) {
		boolean[] marca = new boolean[grafo.listaDeVertices().tamanio()];
		boolean inicio=false;
		int res=0;
		for (int i = 0; i < marca.length; i++) {
			if (!marca[i]) {
				if (inicio==true) return 0;
				inicio=true;
				res=bfs(i, grafo, marca, 0);
			}
		}
		return res;
	}

	private static int bfs(int i, Grafo<String> grafo, boolean[] marca, int dis) {
		ListaGenerica<Arista<String>> ady = null;
		ColaGenerica<Vertice<String>> q = new ColaGenerica<Vertice<String>>();
		q.encolar((grafo.listaDeVertices().elemento(i)));
		q.encolar(null);
		marca[i] = true;

		while (!q.esVacia()) {
			Vertice<String> v = q.desencolar();
			if (v != null) {
				ady = grafo.listaDeAdyacentes(v);
				ady.comenzar();

				while (!ady.fin()) {
					Arista<String> arista = ady.proximo();
					int j = arista.verticeDestino().posicion();

					if (!marca[j]) {

						Vertice<String> w = arista.verticeDestino();
						marca[j] = true;
						q.encolar(w);

					}
				}

			} else if (!q.esVacia()) {
				dis++;
				q.encolar(null);
			}
		}
		return dis;

	}

	/*
	 * Ejercicio 10 – Grados de Separación En nuestro interconectado mundo se
	 * especula que dos personas cualesquiera están relacionadas entre sí a lo sumo
	 * por 6 grados de separación. En este problema, debemos realizar un método para
	 * encontrar el máximo grado de separación en una red de personas, donde una
	 * arista entre dos personas representa la relación de conocimiento entre ellas,
	 * la cual es simétrica. Entre dos personas, el grado de separación es el mínimo
	 * número de relaciones que son necesarias para conectarse entre ellas. Si en la
	 * red hay dos personas que no están conectadas por una cadena de relaciones, el
	 * grado de separación entre ellas se considerará igual a -1. En una red, el
	 * máximo grado de separación es el mayor grado de separación entre dos personas
	 * cualesquiera de la red. Implemente en JAVA una clase llamada
	 * GradosDeSeparacion ubicada dentro del paquete prog3.grafos.utiles, cumpliendo
	 * la siguiente especificación: ● maximoGradoDeSeparacion(Grafo<String> grafo) :
	 * int // Retorna el máximo grado de separación del grafo recibido como
	 * parámetro. Si en el grafo hubiera dos personas cualesquiera que no están
	 * conectadas por una cadena de relaciones entonces se retorna 0.
	 * 
	 */

}
