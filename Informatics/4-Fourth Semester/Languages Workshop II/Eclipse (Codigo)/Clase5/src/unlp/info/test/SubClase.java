package unlp.info.test;

public class SubClase extends SuperClase {
	 SubClase() {
	}
}

///No compila, ya que el constructor de SuperClase es privado, lo que indica que solo ella puede acceder al mismo, sin darle la oportunidaad a"Subclase2 de hacerlo, se modifica eso para package, yqs