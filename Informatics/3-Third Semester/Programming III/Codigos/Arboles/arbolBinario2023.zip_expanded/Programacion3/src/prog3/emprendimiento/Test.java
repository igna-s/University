package prog3.emprendimiento;


import prog3.arbolgeneral.ArbolGeneral;

public class Test {

	public static void main(String[] args) throws Exception {
		Empleado emple= new Empleado("Santos",33337,8);
		Empleado emple2= new Empleado("Menem",33333399,8);
		Empleado emple3= new Empleado("Unity",7,8);
		Empleado emple4= new Empleado("Alguien",5,8);
		Empleado emple5= new Empleado("Nshrd",333999,8);
		Empleado emple6= new Empleado("Hola",30,8);
		Empleado emple7= new Empleado("Yqs",99,8);
		Empleado emple8= new Empleado("Alv",5,8);
		Empleado emple9= new Empleado("Felipe",59,8);
		
		                                                                 //Lv
		ArbolGeneral<Empleado> a=new ArbolGeneral<Empleado>(emple);      //1)       a
		ArbolGeneral<Empleado> b=new ArbolGeneral<Empleado>(emple2);     //2)   b   c   d
		ArbolGeneral<Empleado> c=new ArbolGeneral<Empleado>(emple3);     //3) e f       ghi
		ArbolGeneral<Empleado> d=new ArbolGeneral<Empleado>(emple4);     //4) j
		ArbolGeneral<Empleado> e=new ArbolGeneral<Empleado>(emple5);     //
		ArbolGeneral<Empleado> f=new ArbolGeneral<Empleado>(emple6);     //
		ArbolGeneral<Empleado> g=new ArbolGeneral<Empleado>(emple7);     //
		ArbolGeneral<Empleado> h=new ArbolGeneral<Empleado>(emple8); 
		ArbolGeneral<Empleado> i=new ArbolGeneral<Empleado>(emple);     
		ArbolGeneral<Empleado> j=new ArbolGeneral<Empleado>(emple9); 
		
		
		e.agregarHijo(j);
		b.agregarHijo(e);
		b.agregarHijo(f);
		
		d.agregarHijo(g);
		d.agregarHijo(h);
		d.agregarHijo(i);
		
		a.agregarHijo(b);
		a.agregarHijo(c);
		a.agregarHijo(d);
		
		System.out.println("////Empresa///");
		Empresa empre= new Empresa(a);
		System.out.println("Imprimo");
		empre.imprimir();
		
		System.out.println("Empleados categoria 3: "+ empre.empleadosPorCategoria(3));
		System.out.println("Categoria con mas empleados: " +empre.categoriaConMasEmpleados());
		System.out.println("Total: "+empre.cantidadTotalDeEmpleados());
		
		System.out.println("Remplazo el Presidente");
		empre.reemplazarPresidente();
	    System.out.println("Imprimo");
		empre.imprimir();
		
		
		
		                                                                 //Lv
		ArbolGeneral<Character> a1=new ArbolGeneral<Character>('A');      //1)       a
		ArbolGeneral<Character> b1=new ArbolGeneral<Character>('B');     //2)   b   c   d
		ArbolGeneral<Character> c1=new ArbolGeneral<Character>('C');     //3) e  f       ghi
		ArbolGeneral<Character> d1=new ArbolGeneral<Character>('D');     //4) jk
		ArbolGeneral<Character> e1=new ArbolGeneral<Character>('E');     //
		ArbolGeneral<Character> f1=new ArbolGeneral<Character>('F');     //
		ArbolGeneral<Character> g1=new ArbolGeneral<Character>('G');     //
		ArbolGeneral<Character> h1=new ArbolGeneral<Character>('H'); 
		ArbolGeneral<Character> i1=new ArbolGeneral<Character>('I');     
		ArbolGeneral<Character> j1=new ArbolGeneral<Character>('J');
		ArbolGeneral<Character> k=new ArbolGeneral<Character>('k');
		
		
		e1.agregarHijo(j1);
		e1.agregarHijo(k);
		b1.agregarHijo(e1);
		b1.agregarHijo(f1);
		
		d1.agregarHijo(g1);
		d1.agregarHijo(h1);
		d1.agregarHijo(i1);
		
		a1.agregarHijo(b1);
		a1.agregarHijo(c1);
		a1.agregarHijo(d1);
	
		
		System.out.println("////Agua///");
		System.out.println("Ingresando 1000L, queda en el nodo mas macrisioso " + Agua.RedDeAguaPotable(a1,1000) + "l");
	
		Trie t=new Trie();

		System.out.println("////Diccionario///");
		System.out.println("Agrego Laura, Lara, Negro");
		t.agregarPalabra("Laura");
		t.agregarPalabra("Lara");
	    t.agregarPalabra("Laura");
		t.agregarPalabra("Lana");
		t.agregarPalabra("Lanilla");
		t.agregarPalabra("Laura");
		t.agregarPalabra("Nene");
		t.agregarPalabra("Negro");
		
		System.out.println("Imprimo por nivel");
	    t.imprimir();
	//    System.out.println("Imprimo preorden");
	 //   t.imprimir2();
	    System.out.println("Busco las palabras que comienzen con La");
	    System.out.println(t.palabrasQueEmpiezanCon("La"));
	    
	}
	
	

}
