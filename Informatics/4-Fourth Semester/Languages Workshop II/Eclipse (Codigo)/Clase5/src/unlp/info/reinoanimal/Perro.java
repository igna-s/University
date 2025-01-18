package unlp.info.reinoanimal;

public class Perro extends Animal {
	@Override
   protected void saludo() {
		System.out.println("Guau!");
	}
}



//Los constructores son todos package por defecto - Ta bien

//El problema con este codigo es que el saludo de gato debe tener al menos la misma visibilidad que la clase padre (Protected o Public)