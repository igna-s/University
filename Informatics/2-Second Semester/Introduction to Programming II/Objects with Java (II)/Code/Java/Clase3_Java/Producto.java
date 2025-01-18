public class Producto  {
    private String nombre;
    private int Codigo;
    private int Unidades;
    private String Marca;
    private String Descrpicion;
    //código y nombre del producto, descripción, marca y unidades disponibles.  

    
    public Producto(String unNombre, int unCodigo, int unasUnidades, String unaMarca, String unaDescrpicion){
        nombre = unNombre;
        Codigo = unCodigo;
        Unidades = unasUnidades;
        Marca=unaMarca;
        Descrpicion=unaDescrpicion;
    }
    
    public Producto(){
     
    }

    public int getCodigo() {
        return Codigo;
        
    }

        public String getMarca() {
        return Marca;
        
    }
        public String getDescrpicion() {
        return Descrpicion;
        
    }
    
    public int getUnidades() {
        return Unidades;
    }

    public String getNombre() {
        return nombre;
    }

    public void setCodigo(int unCodigo) {
        Codigo = unCodigo;
    }

    public void setDescrpicion(String unaDescripcion) {
        Descrpicion = unaDescripcion;
    }
    
    public void setMarca(String unaMarca) {
        Marca = unaMarca;
    }
    
    public void setUnidades(int unaUnidades) {
        Unidades =+ unaUnidades;
    }

    public void setNombre(String unNombre) {
        nombre = unNombre;
    }
    
    public String toString(){
        String aux; 
        aux = "Nombre de producto = " + nombre + ", Codigo= " + Codigo + " .Hay " + Unidades + " unidades y su marca es '" + Marca + "' ésta es su breve descripcion=   " + Descrpicion + ".";
        return aux;
    }
    
}
