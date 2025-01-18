package romano;

import griego.*;

public class Delta extends AlphaC {
	void unMetodoD(AlphaC a, Delta d) {
		a.x = 10;
		d.x = 10;
		a.otroMetodoA();
		d.otroMetodoA();
	}
}


///Esto es invalido, ya que protected entre clases solo tiene acceso a los metodos publicos

/*
La palabra protected está relacionada con la herencia:
- Si se crea una subclase en un paquete diferente que el de la superclase, la subclase
tiene acceso sólo a los miembros definidos public de la superclase.
- Si la subclase pertenece al mismo paquete que la superclase, entonces la subclase tiene
acceso a todos los miembros declarados public y package.
*/