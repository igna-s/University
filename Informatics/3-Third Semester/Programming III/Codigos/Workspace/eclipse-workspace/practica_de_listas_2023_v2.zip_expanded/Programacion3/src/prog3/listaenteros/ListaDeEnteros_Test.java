package prog3.listaenteros;

public class ListaDeEnteros_Test {


	 public static void main(String[] args) {
	  ListaDeEnteros L = new ListaDeEnterosEnlazada();
	  L.agregarInicio(1);
	  L.agregarInicio(2);
	  L.agregarInicio(3);
	  L.agregarInicio(4);
	  L.agregarInicio(5);

	  System.out.println(L.toString());
	  System.out.println();
	  imprimir(L);
	  imprimir2(L);
	  ImprimirReves(L);

	 }

	 private static void imprimir(ListaDeEnteros L) {
	  L.comenzar();
	  while (!L.fin()) {
	   System.out.println(L.proximo());

	  }
	 }

	 private static void imprimir2(ListaDeEnteros L) {
	  int i;
	  for (i = 0; i < L.tamanio(); i++)
	   System.out.println(L.elemento(i));

	 }
	 public static void ImprimirReves(ListaDeEnteros L){
	  L.comenzar();
	  imprimirRecursivo(L);
	  
	 }
	 private static void imprimirRecursivo(ListaDeEnteros L){
	  if (!L.fin()){
	   int aux=L.proximo();
	   imprimirRecursivo(L);
	   System.out.println(aux);
	  }
	  
	  
	 }
		
		
	}
