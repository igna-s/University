package prog3.grafos.utiles;
import prog3.listagenerica.*;
public class RutaMinima {

	private int x;
	private ListaGenericaEnlazada<String> l;
	
	public RutaMinima(){
		x=0;
		l= new ListaGenericaEnlazada<String>();		
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public ListaGenericaEnlazada<String> getL() {
		return l;
	}

	public void setL(ListaGenericaEnlazada<String> l) {
		this.l = l;
	}

	@Override
	public String toString() {
		if (x==99999) return "RutaMinima [x=" + 0 + ", l=" + null + "]";
		return "RutaMinima [x=" + x + ", l=" + l + "]";
	}
	
	
	
}
