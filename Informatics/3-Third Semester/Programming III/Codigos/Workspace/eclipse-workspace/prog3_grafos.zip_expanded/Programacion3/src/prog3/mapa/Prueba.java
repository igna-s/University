package prog3.mapa;

import prog3.grafos.*;
import prog3.listagenerica.*;

public class Prueba {

	public static void main(String[] args) {
			 Vertice<String> v1 = new VerticeImplListAdy<String>("Buenos Aires");
			 Vertice<String> v2 = new VerticeImplListAdy<String>("Santiago");
			 Vertice<String> v3 = new VerticeImplListAdy<String>("Lima");
			 Vertice<String> v4 = new VerticeImplListAdy<String>("NEGRO");
			 Vertice<String> v5 = new VerticeImplListAdy<String>("Sapo");
			 Vertice<String> v6 = new VerticeImplListAdy<String>("LimON");
			 Vertice<String> v7 = new VerticeImplListAdy<String>("FIN");
			 
			 Grafo<String> ciudades = new GrafoImplListAdy<String>();
			 ciudades.agregarVertice(v1);
			 ciudades.agregarVertice(v2);
			 ciudades.agregarVertice(v3);
			 ciudades.agregarVertice(v4);
			 ciudades.agregarVertice(v5);
			 ciudades.agregarVertice(v6);
			 ciudades.agregarVertice(v7);
			
			 ciudades.conectar(v1, v2, 3); 
			 ciudades.conectar(v2, v3, 2); 
			 ciudades.conectar(v3, v4, 1); 
			 ciudades.conectar(v4, v5, 2); 
			 ciudades.conectar(v5, v6, 9999); 
			 ciudades.conectar(v6, v1, 3); 
			 ciudades.conectar(v6, v5, 2); 
			 ciudades.conectar(v5, v4, 3); 
			 ciudades.conectar(v4, v3, 2); 
			 ciudades.conectar(v3, v2, 9); 
			 ciudades.conectar(v2, v1, 3); 
			 ciudades.conectar(v1, v6, 3); 
			 
         	 ciudades.conectar(v4, v1, 9); 
			 ciudades.conectar(v1, v4, 3); 
			 ciudades.conectar(v3, v1, 9999); 
			 ciudades.conectar(v2, v5, 2); 
			 ciudades.conectar(v1, v1, 3); 
			 
			 ciudades.conectar(v4, v7, 3); 
			 ciudades.conectar(v7, v4, 3); 
			 ciudades.conectar(v3, v7, 3); 
			 ciudades.conectar(v7, v3, 3); 
			 
			 
			 Mapa m = new Mapa();
			 ListaGenerica<String> s;
			 m.setCiudades(ciudades);
             s = m.devolverCamino("FIN","Buenos Aires");
			 if (s.tamanio()!=0) System.out.println(s);
			 else System.out.println(s+"No");
			 
			 ListaGenerica<String> lis = new ListaGenericaEnlazada<String>();
			 lis.agregarInicio("Lima");
			 lis.agregarInicio("Santiago");
			 lis.agregarInicio("LimON");
			 lis=m.devolverCaminoExceptuando ("FIN","Buenos Aires",lis);
			 if (lis.tamanio()!=0) System.out.println(lis);
			 else System.out.println(lis+"No");
			 
			 lis = m.caminoMasCorto("FIN", "Buenos Aires");
			 if (lis.tamanio()!=0) System.out.println(lis);
			 else System.out.println(lis+"No");
			 
			 lis = m.caminoSinCargarCombustible("FIN", "Buenos Aires",500);
			 if (lis.tamanio()!=0) System.out.println(lis);
			 else System.out.println(lis+"No");
			 
			 lis = m.caminoConMenorCargaDeCombustible("FIN", "Buenos Aires",10);
			 if (lis.tamanio()!=0) System.out.println(lis);
			 else System.out.println(lis+"No");
			 
	}
			 
			 
	}


