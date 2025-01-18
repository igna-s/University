package prog3.grafos.utiles;

import prog3.grafos.*;
import prog3.listagenerica.*;

public class Delta<T> {

	public int maxIslasDistintas(Grafo<String> grafo) {
		int aux = 0, x = 0, i;
		boolean[] visitado = new boolean[grafo.listaDeVertices().tamanio()];

		for (i = 0; i < 1; i++) { //// Tomo el primer vertice como muelle principal
			if (!visitado[i])
				aux = dfs(i, grafo, visitado, x, i);
		}
		return aux;
	}

	private int dfs(int i, Grafo<String> grafo, boolean[] visitado, int x, int muelle) {
		int aux = 0, max = 0, tot = 0;
		visitado[i] = true;
		Vertice<String> v = grafo.vertice(i);
		ListaGenerica<Arista<String>> a = grafo.listaDeAdyacentes(v);

		a.comenzar();

		while (!a.fin()) {

			int j = a.proximo().verticeDestino().posicion();
			if (!visitado[j]) {
				aux = dfs(j, grafo, visitado, x + 1, muelle);
				if ((aux > max) && (i == muelle))
					max = aux;
				else
					tot += aux;

			}

		}
		if (i == muelle)
			return max;
		else if (tot == 0) // Caso Base
			return x;
		else
			return tot;
	}

	public RutaMinima caminoMasCorto(Grafo<String> grafo, String islaO, String islaD) {
		RutaMinima ruta = new RutaMinima();
		boolean[] visitados = new boolean[grafo.listaDeVertices().tamanio()];
		ListaGenericaEnlazada<String> aux = new ListaGenericaEnlazada<String>();
		
          
		for (int i = 0; i < visitados.length; i++) {
			if (grafo.vertice(i).dato().equals(islaO)) {
				RutaMin(i, grafo, visitados, islaD, aux , ruta,1 /*Muelle*/,false);
			break;
			}
		}

		return ruta;

	}

	private void RutaMin(int i, Grafo<String> grafo, boolean[] visitados, String islaD, ListaGenericaEnlazada<String> aux, RutaMinima ruta, int muelle,boolean pase) {

		visitados[i]=true;
		
		Vertice<String> v = grafo.vertice(i);
		aux.agregarFinal(v.dato());
		ListaGenerica<Arista<String>> a = grafo.listaDeAdyacentes(v);
		
		
		if ((v.dato().equals(islaD))&&((aux.tamanio()<ruta.getL().tamanio())||(ruta.getL().tamanio()==0))) {
		     ruta.setL(aux.clonar());
		     if (pase==true) ruta.setX(1);
		}
        if (v.dato().equals(grafo.vertice(muelle).dato())) pase=true;
		
		a.comenzar();
		while (!a.fin()) {
			Arista<String> arista= a.proximo();
			int j=arista.verticeDestino().posicion();
            if (!visitados[j])
			RutaMin(j, grafo, visitados, islaD, aux,ruta, muelle,pase);
		}
		
		visitados[i]=false;
		aux.eliminarEn(aux.tamanio()-1);
	}

}