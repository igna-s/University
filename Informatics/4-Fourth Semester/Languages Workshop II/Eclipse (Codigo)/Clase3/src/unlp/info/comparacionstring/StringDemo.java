package unlp.info.comparacionstring;

public class StringDemo {

	public static void main(String[] args) {
		String str1 = "Leones y Tigres y Osos!";
		String str2 = "Leones y Tigres y Osos!";
		String str3 = str2;
		String str4 = new String("Leones y Tigres y Osos!");
		String str5 = " Y yo!";
		String str6 = "Leones y Tigres y Osos! Y yo!";
		String str7 = str1 + str5;
		System.out.println(str1 == str2);
		System.out.println(str1 == str3);
		System.out.println(str1 == str4);
		System.out.println(str2 == str3);
		System.out.println(str2 == str4);
		System.out.println(str3 == str4);
		System.out.println(str6 == str7);
		System.out.println(str1.equals(str4));
		System.out.println(str6.equals(str7));
	}
}


/*
Sentencia                   true/false                 ¿Por qué? - JUSTIFIQUE
str1 == str2                      T                    Porque hacen referencia al mismo objeto en mem (Java hace eso en asignaciones identicas siempre que no haya un New u otras excepciones de por medio -Ver Pool de Cadenas-)
str1 == str3                      T                    Porque hacen referencia al mismo objeto en mem
str1 == str4                      F                    Porque se crea una nueva instancia (Y str1 no tiene la misma posicion de memora que str4, en estos casos no se usa el pool de cadenas)
str2 == str3                      T                    Porque hacen referencia al mismo objeto en mem
str2 == str4                      F                    Porque se crea una nueva instancia(Idem str1)
str3 == str4                      F                    Porque se crea una nueva instancia(Idem str1)
str6 == str7                      F                    Porque al concatenar 4 y 5 se crea un nuevo objeto que se guarda separado de str6)
str1.equals(str4)                 T                    Porque equals compara contenido, no posicion de memoria a que apunta el puntero como los casos anteriores
str6.equals(str7)                 T                    Porque equals compara contenido, no posicion de memoria
*/



/*

Almacenamiento de cadenas literales: Cuando creas una cadena literal en tu código fuente, como "Hola", Java verifica si una cadena con el mismo contenido ya existe en el pool de cadenas. Si existe, en lugar de crear una nueva cadena, Java reutiliza la referencia a la cadena existente en el pool.

Referencias compartidas: Cuando varias variables hacen referencia a la misma cadena literal, todas esas variables apuntan a la misma instancia en el pool de cadenas. Esto ahorra memoria ya que no se duplica el mismo contenido de cadena.

Eficiencia de memoria: La reutilización de cadenas literales en el pool de cadenas reduce la cantidad de memoria utilizada por tu programa, especialmente cuando trabajas con muchas cadenas idénticas.

Uso del operador new: Si creas una cadena utilizando el operador new, como new String("Hola"), Java creará una nueva instancia de cadena en el montón (heap) de memoria, independientemente de si una cadena idéntica ya existe en el pool de cadenas. Esto puede resultar en que haya dos objetos de cadena con el mismo contenido, pero referencias diferentes.

Método intern(): Puedes utilizar el método intern() para forzar una cadena a ser almacenada en el pool de cadenas. Por ejemplo, str.intern() toma la cadena str y la agrega al pool de cadenas si no se encuentra allí.

*/





/*
 * El equals compara contenido de un elemento
 
 
 
 Si, seria comveniente sobreescribir el metodo equals de la Clase Persona
 El criterio es el siguiente: -Fijarse que el objeto sea una Persona y no sea null
                              -Hacer el downcastin del objeto a una persona  
                              -Comparar los campos que se consideren necesarios (Nombre y apellido, solo dni, etc) utilizando equals de esas subclases o == si son primitivos
                              -Devolver true- False
 
 Ej
 @Override
public boolean equals(Object o) {
    if (this == o) return true;
    if (o == null || getClass() != o.getClass()) return false;
    Persona persona = (Persona) o;
    return Objects.equals(nombre, persona.nombre) &&
           Objects.equals(identificacion, persona.identificacion) &&
           Objects.equals(fechaNacimiento, persona.fechaNacimiento);
}
 
 
 El metodo por default es la comparacion de las posiciones de memoria
 
 
 
 
 * */
