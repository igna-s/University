package romano;

import griego.*;
class Beta {
void unMetodoB(){
AlphaB a = new AlphaB();
a.x=10;
a.unMetodoA();
}
}




//Si se modifica la configuracion: -Si bien la clase delta es public, sus metodos son package (el mismo no funcionaria, ya que la clase protected es privada entre paquetes y "Publica" en el mismo paquete)