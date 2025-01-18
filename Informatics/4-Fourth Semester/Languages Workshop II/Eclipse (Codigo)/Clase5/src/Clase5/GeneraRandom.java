package Clase5;

import java.math.*;

public final class GeneraRandom { /// Agrego final para que no se pueda tener subclases ni sobreescritura

	private static final int i = Integer.MAX_VALUE;

	// Marca el constructor como privado para evitar la creación de instancias
    private GeneraRandom() {}
	
	public static int ObtenerRandom() { return (int) (Math.random() * i);}

}

//No es posible sin el privateGeneraRandom(), ya que es todo estatico (Osea, se podria, pero no haria nada, no seria correcto)

///El public indica que cualquiera tiene acceso a esa clase 
///El final nos indica que no se puede modificar en subclases (Es cte.), ademas no se puede heredar
/// Una clase que cumple los mismo es la clase String