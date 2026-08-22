package prog3.Pila_Cola;

public class PruebaPila {

	public static void main(String[] args) throws Exception {

/*		PilaGenerica<Character> p = new PilaGenerica<Character>();

		p.apilar('A');
		p.apilar('B');
		p.apilar('C');
		p.apilar('D');
		p.apilar('E');
		char aux;
		aux = p.desapilar();
		aux = p.desapilar();
		aux = p.desapilar();
		
		while (!p.esVacia()) {
				System.out.println(p.tope());
			
		}*/
		
		
/*		String de caracteres. Considere que un string de caracteres {[]} está
		balanceado si cada símbolo de apertura se corresponde con un símbolo de cierre
		de manera “armoniosa”. Por ejemplo, "{( ) [ ( ) ] }" está balanceado, pero "( [ )
		]" no lo está.*/
				
	
	String h= ")";
	System.out.println(TestBalanceo.Test(h));
	ColaGenerica<Integer> c= new ColaGenerica<Integer>();
	
	c.encolar(10);
	c.encolar(11);
	c.encolar(12);
	c.encolar(13);
	c.encolar(14);
	c.desencolar();
	c.desencolar();
	
	while (!c.esVacia()) {
		System.out.print(c.desencolar());
		
	}
	}	
}
