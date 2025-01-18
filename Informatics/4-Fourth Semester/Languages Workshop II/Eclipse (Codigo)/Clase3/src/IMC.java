
public class IMC {
	
	private float peso;
	private float altura;
	
	public IMC() {
		
	}
	public IMC(float peso, float altura) {
		this.peso=peso;
		this.altura=altura;	
	}


	public float getPeso() {
		return peso;
	}

	public void setPeso(float peso) {
		this.peso = peso;
	}

	public float getAltura() {
		return altura;
	}

	public void setAltura(float altura) {
		this.altura = altura;
	}

	public float calculo() {

		return peso / (altura * altura);
		
	}
	public static float calculo(long peso2, long altura2) {

		return peso2 / (altura2 * altura2);
	}
}
