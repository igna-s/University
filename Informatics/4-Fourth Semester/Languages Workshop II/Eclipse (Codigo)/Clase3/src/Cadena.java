
public class Cadena {
	
		public static void main(String[] args) {
		Hijo h = new Hijo();
		}
		
}


///Corregido la variable incompatible
/*
Imprime
Constructor Abuelo()
Constructor Padre()
Constructor Hijo()

Las llamadas sucesivas que forman la cadena de constructores se encuentran en los constructores de las clases:

En la clase Hijo, se llama al constructor de Padre usando super().
En la clase Padre, se llama al constructor de Abuelo usando super().
Como solo tienen 1 constructor el programa los agrega automaticamente

*/