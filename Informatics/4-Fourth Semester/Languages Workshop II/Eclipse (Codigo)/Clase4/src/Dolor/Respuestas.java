package Dolor;

public class Respuestas {

	
/*
 Criterio\Solución                            Opción 1                             Opción 2
 
 Abstracción del mundo real                      
¿Considera que los objetos del                   Si                                       Si
mundo real están modelados en el
sistema?
¿Hay organización entre las clases               No                                       Si
(nivel de abstracción)?

Duplicación de código
¿Hay duplicación de código?                      Si                                       No
¿Es necesaria o puede ser evitada?               Evitada                                  Necesario

Re-uso de código
¿Se re-usa código?                               No                                       Si
¿Puede el código actual ser                     
re-usado si el sistema crece para                Si                                       Si
abarcar otros tipos de elementos
audiovisuales?

Mantenimiento del programa
¿Qué cambios aparecen si se quiere
agregar el DVD? Piense                           Se agregan un DvD                       Se crea un item
particularmente en el conjunto de
DVDs que tendría el Database
¿Qué tan fácil es cambiar el código?             Facil (Mucho pero apiñado)               Intermedio (+ corto, pero multiples clases)

Extensibilidad
¿Qué tan sencillo es agregar un
nuevo tipo de recurso como libros                Facil                                   Intermedio
electrónicos?
¿Cuáles son los cambios a realizar?         -Crear la Clase                              -Crear la clase, teniendo en cuenta la jerarquia de clases (Evitar repeticion de codigo)
                                            -Agregar una lista de ellos en Database      -Agregar la jerarquia correspondiente para que sea un item

Polimorfismo
Indique –en caso de existir- donde           No                                          Si (Al tener intems y sus subclases con metodos prints que es especifico segun objeto)
está aplicado este concepto

	
	
	
	
	
	Responda verdadero o falso según corresponda. JUSTIFIQUE.
	
	a. Una clase abstracta debe tener al menos un método abstracto. JUSTIFIQUE.
	V - Ya que puede poseer metodos abstractos y concretos (Requiere al menos 1 abstracto
	
	b. No pueden definirse constructores en una clase abstracta. JUSTIFIQUE.
	F - Sí, se pueden definir constructores en una clase abstracta. De hecho, es común definir constructores 
	en una clase abstracta para inicializar sus atributos o realizar tareas comunes a todas las subclases.
	
	c. Los métodos abstractos no pueden ser declarados en una clase no abstracta (concreta).
	JUSTIFIQUE
	V - Los métodos abstractos deben estar contenidos en una clase abstracta y ser implementados por las subclases concretas
	
	d. Si una clase B extiende una clase abstracta A debe implementar TODOS los métodos de
	la clase abstracta A. JUSTIFIQUE
	V - Ya que una clase abstracta contiene los comportamientos comunes  de la 
	subclases, los cuales estas deben implementar (Salvo que tambien sea una clase abstracta que implemente una parte de  los metodos concretos y el resto una clase c)
	 */
}
