package prog3.Pila_Cola;

public class TestBalanceo {

public static boolean Test(String s) throws Exception{
	
	PilaGenerica<Character> p= new PilaGenerica<Character>();
	int Haysimbolos=0;
	boolean resultado = true;
	char x,y;
	int cant=0,i=0;
	
	while (i<s.length()&&(resultado)) {
	x=s.charAt(i);
	cant++;
	
	if ((x=='{')||(x=='(')||(x=='[')) {
		p.apilar(x);
		
	}
	else if((x=='}')||(x==')')||(x==']')) {
	    if (!p.esVacia()){
		y=p.desapilar();
		if (((y=='{')&&(x=='}'))||
			((y=='(')&&(x==')'))||
			((y=='[')&&(x==']'))) 
		{ Haysimbolos++;}
	    }
	    else resultado=false;
	}
	i++;
	}
	i--;
	x=s.charAt(i);
	if (cant==1) {
		if ((x=='}')||(x==')')||(x==']'))return resultado;
	}
	if ((!p.esVacia())||(Haysimbolos==0))
	return !resultado;
	else return resultado;
}

}
