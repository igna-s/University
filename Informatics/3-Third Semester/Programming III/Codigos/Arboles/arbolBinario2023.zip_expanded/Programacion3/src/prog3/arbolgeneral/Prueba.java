package prog3.arbolgeneral;

public class Prueba {

	public static void main(String[] args) throws Exception {
		ArbolGeneral<Integer> a=new ArbolGeneral<Integer>(2);
		ArbolGeneral<Integer> b=new ArbolGeneral<Integer>(7);
		ArbolGeneral<Integer> c=new ArbolGeneral<Integer>(99);
		
		b.agregarHijo(new ArbolGeneral<Integer>(1)); 
        b.agregarHijo(new ArbolGeneral<Integer>(10));     //  2
        b.agregarHijo(new ArbolGeneral<Integer>(55));     //  7
        c.agregarHijo(new ArbolGeneral<Integer>(11));     // 1,10,55,99
        c.agregarHijo(new ArbolGeneral<Integer>(13));     //        13,4,0
        c.agregarHijo(new ArbolGeneral<Integer>(4));
        c.agregarHijo(new ArbolGeneral<Integer>(0));
        
        
        a.agregarHijo(b);
        b.agregarHijo(c);
        
        System.out.println(a.altura());
        System.out.println(a.include(212));
        System.out.println(a.nivel(212));
        System.out.println(a.ancho());
        
     
	}

}
