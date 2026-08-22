package prog3.mapa;

import prog3.grafos.*;
import prog3.listagenerica.*;

public class Mapa {

	private Grafo<String> ciudades;

	public Grafo<String> getCiudades() {
		return ciudades;
	}

	public void setCiudades(Grafo<String> ciudades) {
		this.ciudades = ciudades;
	}

	// Retorna la lista de ciudades que se deben atravesar para ir de ciudad1 a
	// ciudad2 en caso

	public ListaGenerica<String> devolverCamino(String ciudad1, String ciudad2) {
		boolean exito = false;
		boolean[] marca = new boolean[ciudades.listaDeVertices().tamanio()];
		ListaGenericaEnlazada<String> lis = new ListaGenericaEnlazada<String>();
		for (int i = 0; i < marca.length; i++) {
			if ((ciudad1.equals(ciudades.vertice(i).dato()))) {
				marca[i] = true;
				this.dfs(i, ciudades, lis, marca, ciudad2);
				break;
			}
		}
		return lis;
	}

	private boolean dfs(int i, Grafo<String> grafo, ListaGenericaEnlazada<String> lis, boolean[] marca,
			String ciudad2) {

		boolean exito = false;
		Vertice<String> v = grafo.listaDeVertices().elemento(i);
		if (ciudad2.equals(v.dato())) {
			lis.agregarFinal(v.dato());
			exito = true; /// Caso base
			marca[i] = true;

		} else {
			ListaGenerica<Arista<String>> ady = grafo.listaDeAdyacentes(v);
			ady.comenzar();
			while (!ady.fin()) {
				int j = ady.proximo().verticeDestino().posicion();
				if (!marca[j]) {
					lis.agregarFinal(v.dato());
					marca[i] = true;
					exito = this.dfs(j, grafo, lis, marca, ciudad2);
					if (exito)
						break;
					lis.eliminarEn(lis.tamanio() - 1);
				}
			}
		}
		return exito;
	}

	/*
	 * El método devolverCaminoExceptuando (String ciudad1, String ciudad2,
	 * ListaGenerica<String> ciudades): ListaGenerica<String> // Retorna la lista de
	 * ciudades que forman un camino desde ciudad1 a ciudad2, sin pasar por las
	 * ciudades que están contenidas en la lista ciudades pasada por parámetro, si
	 * no existe camino retorna la lista vacía. (Sin tener en cuenta el
	 * combustible).
	 */

	public ListaGenerica<String> devolverCaminoExceptuando(String ciudad1, String ciudad2,
			ListaGenerica<String> lista) {
		boolean exito = true;
		boolean[] marca = new boolean[ciudades.listaDeVertices().tamanio()];
		ListaGenericaEnlazada<String> lis = new ListaGenericaEnlazada<String>();

		for (int i = 0; i < marca.length; i++) {
			if ((ciudad1.equals(ciudades.vertice(i).dato()))) {

				lista.comenzar();
				while (!lista.fin() && (exito)) {
					if (ciudad1.equals(lista.proximo())) {
						exito = false;
					}
				}
				if (exito) {
					this.pain(i, ciudades, lis, marca, ciudad2, lista);
				}
			}
		}
		return lis;
	}

	private boolean pain(int i, Grafo<String> grafo, ListaGenericaEnlazada<String> lis, boolean[] marca, String ciudad2,
			ListaGenerica<String> lista) {

		boolean exito = false;
		Vertice<String> v = grafo.listaDeVertices().elemento(i);
		marca[i] = true;

		lista.comenzar();
		while (!lista.fin())
			if (v.dato().equals(lista.proximo())) {
				return false;
			}

		if (ciudad2.equals(v.dato())) {
			lis.agregarFinal(v.dato());
			exito = true; /// Caso base

		} else {
			ListaGenerica<Arista<String>> ady = grafo.listaDeAdyacentes(v);
			ady.comenzar();
			while (!ady.fin()) {
				int j = ady.proximo().verticeDestino().posicion();
				if (!marca[j]) {

					lis.agregarFinal(v.dato());
					exito = this.pain(j, grafo, lis, marca, ciudad2, lista);
					if (exito)
						break;
					lis.eliminarEn(lis.tamanio() - 1);
				}
			}
		}
		return exito;

	}

	ListaGenerica<String> caminoMasCorto(String ciudad1, String ciudad2) {
		ListaGenericaEnlazada<String> camino = new ListaGenericaEnlazada<String>();
		ListaGenericaEnlazada<String> aux = new ListaGenericaEnlazada<String>();
		boolean[] visitado = new boolean[this.ciudades.listaDeVertices().tamanio()];
		int i;

		for (i = 0; i < visitado.length; i++) {
			if (ciudad1.equals(ciudades.vertice(i).dato())) {
				caminoMasCorto(i, ciudades, visitado, camino, aux, ciudad2);
				break;
			}

		}

		return camino;
	}

	private void caminoMasCorto(int i, Grafo<String> ciudades, boolean[] visitado, ListaGenericaEnlazada<String> camino,
			ListaGenericaEnlazada<String> aux, String ciudad2) {

		visitado[i] = true;
		Vertice<String> v = ciudades.vertice(i);
		aux.agregarFinal(v.dato());

		if (ciudad2.equals(v.dato())) {

			if ((aux.tamanio() < camino.tamanio()) || (camino.esVacia())) {
				camino.comenzar();
				while (!camino.esVacia()) {
					camino.eliminarEn(0);
				}
				aux.comenzar();
				while (!aux.fin()) {
					camino.agregarFinal(aux.proximo());
				}
			}

		} else {

			ListaGenerica<Arista<String>> lista = ciudades.listaDeAdyacentes(v);
			lista.comenzar();
			while (!lista.fin()) {
				Arista<String> arista = lista.proximo();
				int j = arista.verticeDestino().posicion();

				if (!(visitado[j])) {
					caminoMasCorto(j, ciudades, visitado, camino, aux, ciudad2);
				}
			}

		}

		visitado[i] = false;
		aux.eliminarEn(aux.tamanio() - 1);
	}

	ListaGenerica<String> caminoSinCargarCombustible(String ciudad1, String ciudad2, int tanqueAuto) {

		ListaGenericaEnlazada<String> aux = new ListaGenericaEnlazada<String>();
		boolean[] visitado = new boolean[this.ciudades.listaDeVertices().tamanio()];
		int i;

		for (i = 0; i < visitado.length; i++) {
			if (ciudad1.equals(ciudades.vertice(i).dato())) {
				caminoMasCombustible(i, ciudades, visitado, aux, ciudad2, tanqueAuto);
				break;
			}

		}

		return aux;

	}

	private boolean caminoMasCombustible(int i, Grafo<String> ciudades2, boolean[] visitado,
			ListaGenericaEnlazada<String> aux, String ciudad2, int combustible) {
		// TODO Auto-generated method stub

		boolean exito = false;
		visitado[i] = true;
		Vertice<String> v = ciudades.vertice(i);
		aux.agregarFinal(v.dato());

		if (ciudad2.equals(v.dato()) && (combustible > 0)) {
			exito = true;
		} else {

			ListaGenerica<Arista<String>> lista = ciudades.listaDeAdyacentes(v);
			lista.comenzar();
			while (!lista.fin() && (!exito)) {
				Arista<String> arista = lista.proximo();
				int j = arista.verticeDestino().posicion();

				if ((!(visitado[j])) && ((combustible - arista.peso()) > 0)) {
					exito = caminoMasCombustible(j, ciudades, visitado, aux, ciudad2, combustible);
				}
			}

		}

		visitado[i] = false;
		if (!exito)
			aux.eliminarEn(aux.tamanio() - 1);
		return exito;
	}

	/*
	 * El método caminoSinCargarCombustible(String ciudad1, String ciudad2, int
	 * tanqueAuto): ListaGenerica<String> // Retorna la lista de ciudades que forman
	 * un camino para llegar de ciudad1 a ciudad2. El auto no debe quedarse sin
	 * combustible y no puede cargar. Si no existe camino retorna la lista vacía.
	 */

	/*
	 * El método caminoConMenorCargaDeCombustible (String ciudad1, String ciudad2,
	 * int tanqueAuto): ListaGenerica<String> // Retorna la lista de ciudades que
	 * forman un camino para llegar de ciudad1 a ciudad2 teniendo en cuenta que el
	 * auto debe cargar la menor cantidad de veces. El auto no se debe quedar sin
	 * combustible en medio de una ruta, además puede completar su tanque al llegar
	 * a cualquier ciudad. Si no existe camino retorna la lista vacía.
	 */

	ListaGenerica<String> caminoConMenorCargaDeCombustible(String ciudad1, String ciudad2, int combustible) {

		ListaGenericaEnlazada<String> camino = new ListaGenericaEnlazada<String>();
		ListaGenericaEnlazada<String> aux = new ListaGenericaEnlazada<String>();
		ListaGenericaEnlazada<Integer> max= new ListaGenericaEnlazada<Integer>();
		max.agregarInicio(0);
		boolean[] visitado = new boolean[this.ciudades.listaDeVertices().tamanio()];
		int i;

		for (i = 0; i < visitado.length; i++) {
			if (ciudad1.equals(ciudades.vertice(i).dato())) {
				MenorCarga(i, ciudades, visitado, camino, aux, ciudad2, combustible, combustible, 0, max);
				break;
			}

		}

		return camino;
	}

	private void MenorCarga(int i, Grafo<String> ciudades, boolean[] visitado, ListaGenericaEnlazada<String> camino,
			ListaGenericaEnlazada<String> aux, String ciudad2, int combustible, int llenado, int recarga, ListaGenericaEnlazada<Integer> max) {

		
		visitado[i] = true;
		Vertice<String> v = ciudades.vertice(i);
		aux.agregarFinal(v.dato());

		if (ciudad2.equals(v.dato())) {

			if ((recarga < max.elemento(0)) || (camino.esVacia())) {
				max.eliminarEn(0);
				max.agregarInicio(recarga);
				camino.comenzar();
				while (!camino.esVacia()) {
					camino.eliminarEn(0);
				}
				aux.comenzar();
				while (!aux.fin()) {
					camino.agregarFinal(aux.proximo());
				}
			}

		} else {

			ListaGenerica<Arista<String>> lista = ciudades.listaDeAdyacentes(v);
			lista.comenzar();
			while (!lista.fin()) {
				Arista<String> arista = lista.proximo();
				int j = arista.verticeDestino().posicion();

				if (!(visitado[j])) {

					if (llenado >= arista.peso()) {
						if (arista.peso() > combustible) {
							combustible = llenado;
							recarga++;
						}

						 MenorCarga(j, ciudades, visitado, camino, aux, ciudad2, combustible-arista.peso(), llenado, recarga,max);
					}
				}
			}

		}

		visitado[i] = false;
		aux.eliminarEn(aux.tamanio() - 1);
       
	}


	
}
