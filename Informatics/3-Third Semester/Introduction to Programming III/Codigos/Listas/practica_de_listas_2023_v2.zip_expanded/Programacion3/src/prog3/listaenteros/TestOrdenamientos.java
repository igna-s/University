package prog3.listaenteros;

public class TestOrdenamientos {

	public static void main(String[] args) {
		
		ListaDeEnterosEnlazada l= new ListaDeEnterosEnlazada();
		ListaDeEnterosEnlazada l2= new ListaDeEnterosEnlazada();
		
		l.agregarInicio(60);
		l.agregarInicio(50);
		l.agregarInicio(10);
		l.agregarInicio(20);
		l.agregarInicio(40);
		l.agregarInicio(90);
		l.agregarInicio(100);
		
		imprimir2(l);
		imprimir2(l.ordenar());
		
		
		l2.agregarInicio(25);
		l2.agregarInicio(11);
		l2.agregarInicio(45);
		l2.agregarInicio(55);
		l2.agregarInicio(65);
		l2.agregarInicio(465);
		l2.agregarInicio(95);
		
		imprimir2(l);
		imprimir2(l2);
		imprimir2(l.combinarOrdenado(l2));
		System.out.println(l2);
		imprimir2(l2.mergeSortMethod());
		System.out.println(l2.mergeSortMethod());
		
      
		
	}
	
	private static void imprimir2(ListaDeEnteros L) {
		  int i;
		  System.out.println("Corte");
		  for (i = 0; i < L.tamanio(); i++)
		   System.out.println(L.elemento(i));

		 }
}