package prog3.listagenerica;

public class Testing {

	public static void main(String[] args) {
		ListaGenericaEnlazada<Integer> l = new ListaGenericaEnlazada<Integer>();

		l.agregarInicio(77);
		l.agregarInicio(12);
		l.agregarInicio(7);
		l.agregarInicio(577);
		l.agregarInicio(70);
		l.agregarInicio(4);
		l.agregarInicio(64);
		l.agregarInicio(88);
		l.agregarInicio(9);
		l.agregarInicio(87);
		
		System.out.println(l);
		l=l.invertir();
		System.out.println(l);
		
	}

}
