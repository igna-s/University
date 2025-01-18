package prog3.grafos.utiles;

import prog3.grafos.*;
import prog3.listagenerica.*;

public class Prueba {

	public static void main(String[] args) {
			 Vertice<String> v1 = new VerticeImplListAdy<String>("Buenos Aires");
			 Vertice<String> v2 = new VerticeImplListAdy<String>("Santiago");
			 Vertice<String> v3 = new VerticeImplListAdy<String>("Lima");
		
			 Grafo<String> ciudades = new GrafoImplListAdy<String>();
			 ciudades.agregarVertice(v1);
			 ciudades.agregarVertice(v2);
			 ciudades.agregarVertice(v3);
			
			 ciudades.conectar(v1, v2, 3); 
			 ciudades.conectar(v1, v3, 2); 

			
			 
			 Recorridos<String> r = new Recorridos<String>();
			 ListaGenericaEnlazada<Vertice<String>> l= new ListaGenericaEnlazada<Vertice<String>>();
			 System.out.println("--- Se imprime el GRAFO con DFS ---");
			 l=r.dfs(ciudades);
			 for (int i=0;i<3;i++) {
			     System.out.println(l.proximo().dato());
			 }
			 
			 System.out.println("--- Se imprime el GRAFO con BFS ---");
			 l=r.bfs(ciudades);
			 for (int i=0;i<3;i++) {
			     System.out.println(l.proximo().dato());
			 }
			 
			 Vertice<String> g5 = new VerticeImplListAdy<String>("Lima");
			 Vertice<String> g1 = new VerticeImplListAdy<String>("Buenos Aires");
			 Vertice<String> g2 = new VerticeImplListAdy<String>("Santiashshgo");
			 Vertice<String> g3 = new VerticeImplListAdy<String>("Limna");
			 Vertice<String> g4 = new VerticeImplListAdy<String>("Santiago");
			 
		
			 Grafo<String> ciudades2 = new GrafoImplListAdy<String>();
			 ciudades2.agregarVertice(g5);
			 ciudades2.agregarVertice(g1);
			 ciudades2.agregarVertice(g2);
			 ciudades2.agregarVertice(g3);
			 ciudades2.agregarVertice(g4);
			
    	     ciudades2.conectar(g1, g2, 3); 
		     ciudades2.conectar(g2, g3, 2); 
			 ciudades2.conectar(g3, g4, 3); 
      	 	 ciudades2.conectar(g4, g1, 2); 

         	 ciudades2.conectar(g1, g5, 2); 
     		 ciudades2.conectar(g5, g1,6);
     		 
     		
			 Algoritmos<String> a = new Algoritmos<String>();
			 a.tieneCiclo(ciudades2);
			 System.out.println("La condicion es-" + a.subgrafoCuadrado(ciudades2));
			 System.out.println("La condicion es-" + a.tieneCiclo(ciudades2));
			 System.out.println("El grado es-" + a.getGrado(ciudades2));
			 
			 
			 Delta<String> d = new Delta<String>();
			 System.out.println("El maximo es-" + d.maxIslasDistintas(ciudades2));
			 System.out.println("El camino mas corto es-" + d.caminoMasCorto(ciudades2,"Santiago","Lima"));
			 
			 
			 System.out.println("--- Guia de Turismo ---");
			 
			 GuiaDeTurismo<String> aaa = new GuiaDeTurismo<String>();
			 
			 Grafo<String> ciudades3= new GrafoImplListAdy<String>();
			 
			 Vertice<String> j5 = new VerticeImplListAdy<String>("C");
			 Vertice<String> j1 = new VerticeImplListAdy<String>("A");
			 Vertice<String> j2 = new VerticeImplListAdy<String>("Itau");
			 Vertice<String> j3 = new VerticeImplListAdy<String>("B");
			 Vertice<String> j4 = new VerticeImplListAdy<String>("Santiago");
			 
			 
			 ciudades3.agregarVertice(j5);
			 ciudades3.agregarVertice(j1);
			 ciudades3.agregarVertice(j2);
			 ciudades3.agregarVertice(j3);
			 ciudades3.agregarVertice(j4);
			 
			 
			 ciudades3.conectar(j1, j2, 30); 
		     ciudades3.conectar(j2, j3, 999999); 
			 ciudades3.conectar(j3, j4, 30); 
      		 ciudades3.conectar(j4, j1, 30); 
      		
      		 ciudades3.conectar(j1, j4, 30); 
		     ciudades3.conectar(j4, j3, 30); 
			 ciudades3.conectar(j3, j2, 99999); 
      		 ciudades3.conectar(j2, j1, 30); 
      		 
      		 ciudades3.conectar(j1, j3, 20); 
      		 ciudades3.conectar(j3, j1, 20); 
			 
      		 ciudades3.conectar(j4, j5, 25); 
     		 ciudades3.conectar(j5, j4, 30); 
			 
			 System.out.println("El camino mas corto es-" + aaa.caminoConMenorNrodeViajes(ciudades3, "A","B"));
			 System.out.println("El maximo grado de separacion es-" + GradosDeSeparacion.maximoGradoDeSeparacion(ciudades3));
		
			 Parcial p = new Parcial();
			 System.out.println(p.resolver(ciudades3, "C", 500000));
			 System.out.println(p.QuedateEnCasa(ciudades3, 99,"Itau"));
	}
	

}
