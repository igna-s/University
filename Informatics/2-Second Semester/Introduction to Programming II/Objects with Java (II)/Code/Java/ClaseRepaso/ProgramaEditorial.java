
/**
 c)    Implementar la clase ProgramaEditorial, su método main y los métodos que considere
 necesarios para la lectura y almacenamiento de a lo sumo 1000 ejemplares. Luego,
 haga la impresión de un listado de todos los ejemplares existentes 
 */
import java.util.Scanner;
public class ProgramaEditorial{
    public static void main (String[]args){
        Scanner in = new Scanner(System.in);
        //varibales de asignacion para ejemplares, libros, revistas y responsables=
        //ejemplar
            String ident;
            int paginas;
            String resumen;
            int año;
            //libros
                String titulo;
                int capitulos;
                boolean portable;
                //revistas
                String NombreR;
                int volumen=0;
                int articulos;
        //responsable
            int dni;
            String nombre;
            String apellido;        
        //end
        int i=0,x=0,Ejemplares=0;    
              
        System.out.print("escriba cantidad de ejemplares a leer= ");
        Ejemplares=in.nextInt();
        Ejemplar[]v= new Ejemplar[Ejemplares];
        while (i<Ejemplares) {
            System.out.print("¿Que quiere ingresar? libro[1] o Revista[2]= ");
            x=in.nextInt();
            if (x==1 | x==2){
                System.out.println("|Escriba la informacion general del escrito|");
                System.out.print("Escriba el identificador= ");
                ident=in.next();
                System.out.print("Escriba la cantidad de paginas= ");
                paginas=in.nextInt();
                System.out.print("Escriba un breve resumen= ");
                resumen=in.next();
                in.nextLine();
                System.out.print("escriba el año de publicacion | si no a sido publicado ingrese el año 0=");
                año=in.nextInt();
            //
                System.out.println("|Ahora escriba la informacion del responable|");
                System.out.print("Escriba el dni del responable= ");
                dni=in.nextInt();
                System.out.print("Escriba el nombre del responsable= ");
                nombre=in.next();
                System.out.print("Escribe el apellido del responsable= ");
                apellido=in.next();
            //
                System.out.println("EXITO☺ ");
                if(x==1){
                  System.out.print("Ingrese el titulo del libro= ");
                  titulo=in.next();
                  in.nextLine();
                  System.out.print("capitulos del libro= ");
                  capitulos=in.nextInt();
                  System.out.print("portable True|False= ");
                  portable=in.nextBoolean();
                  Responsable resp=new Responsable(dni,nombre,apellido);
                  v[i]=new Libro(titulo,capitulos,portable,ident,paginas,resumen,año,resp);
                  i++;
                }
                else{  
                  System.out.print("Ingrese el titulo de la revista= ");
                  NombreR=in.next();
                  in.nextLine();
                  System.out.print("Ingrese la cantidad de articulos que tiene la revista= ");
                  articulos=in.nextInt();
                  volumen=0;
                  Responsable resp=new Responsable(dni,nombre,apellido);
                  v[i]=new Revista(NombreR,volumen,articulos,ident,paginas,resumen,año,resp);
                  i++;
                }
            }
        else System.out.println("No se ingreso un numero valido!!");
        }
    for(i=0;i<Ejemplares;i++)
        System.out.println(v[i].Imprimir());
    in.close();
    }
}
