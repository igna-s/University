public class Propietario


  {
    private String CIT;
    private String NomAp;
    
    public Propietario(String unCIT, String unNomAp){
        CIT = unCIT;
        NomAp = unNomAp; 
        
    }
    
    public Propietario(){
     
    }

    public String getNomAp() {
        return NomAp;
    }


    public String getCIT() {
        return CIT;
    }

    public void setNomAp(String unNomAp) {
        NomAp=unNomAp;
    }

    public void setCIT(String unCIT) {
        CIT = unCIT;
    }
    

}