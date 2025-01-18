package prog3.listagenerica;

public class ColaGenerica<T> {
	
		private NodoGenerico<T> inicio;


		public void encolar(T elem) {
			NodoGenerico<T> aux = new NodoGenerico<T>();
			NodoGenerico<T> recorrido = new NodoGenerico<T>();
			aux.setDato(elem);
			aux.setSiguiente(null);

			if (esVacia()) {
				inicio = aux;
			} else {
				recorrido=inicio;
				while (recorrido.getSiguiente()!=null)
					recorrido=recorrido.getSiguiente();
				recorrido.setSiguiente(aux);
			}
		}

		public T desencolar() throws Exception {

			if (!esVacia()) {
				NodoGenerico<T> aux = new NodoGenerico<T>();
				aux=inicio;
				inicio=inicio.getSiguiente();
		
	            return aux.getDato();
			}
			else throw new Exception ("Esta Vacia, anda a bañarte");
		}

		
		public T tope()throws Exception {
			if (!esVacia()) {
				NodoGenerico<T> aux = new NodoGenerico<T>();
				aux=this.inicio;
				while(aux.getSiguiente()!=null)
					aux=aux.getSiguiente();
	        return inicio.getDato();
		}
		else throw new Exception ("Esta Vacia, anda a bañarte");
	}

		public boolean esVacia() {
			return (inicio == null);
		}

	}


