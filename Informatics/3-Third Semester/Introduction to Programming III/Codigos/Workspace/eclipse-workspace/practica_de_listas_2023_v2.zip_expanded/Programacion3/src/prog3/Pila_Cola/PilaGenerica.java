package prog3.Pila_Cola;

public class PilaGenerica<T> {
	private NodoGenerico<T> inicio;


	public void apilar(T elem) {
		NodoGenerico<T> aux = new NodoGenerico<T>();
		aux.setDato(elem);
		aux.setSiguiente(null);

		if (esVacia()) {
			inicio = aux;
		} else {
			aux.setSiguiente(inicio);
			inicio = aux;
		}
	}

	public T desapilar() throws Exception {

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

        return inicio.getDato();
	}
	else throw new Exception ("Esta Vacia, anda a bañarte");
}

	public boolean esVacia() {

		return (inicio == null);
	}

}
