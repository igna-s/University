package unlp.info.math;

public final class Complex {

	private double re;
	private double im;

	public Complex(double re, double im) {
		this.im = im;
		this.re = re;
	}

	public Complex add(Complex c) {

		double aux1, aux2;
		aux1 = (c.getIm() + this.im);
		aux2 = (c.getRe() + this.re);
		Complex aux = new Complex(aux1, aux2);
		return aux;

	}

	public Complex substract(Complex c) {

		double aux1, aux2;
		aux1 = (this.im - c.getIm());
		aux2 = (this.re - c.getRe());
		Complex aux = new Complex(aux1, aux2);
		return aux;

	}

	@Override
	public boolean equals(Object o) {

		if ((o != null) && (o instanceof Complex)) {
			Complex c = (Complex) o;
			return ((c.getIm() == this.im) && (c.getRe() == this.re));
		}
		return false;
	}

	@Override
	public String toString() {
		return ("Nro: " + this.re + " - " + this.im + "i");
	}

	public static Complex valueOf(double re, double im) {

		return new Complex(re, im);

	}

	public double getRe() {
		return re;
	}

	public void setRe(double re) {
		this.re = re;
	}

	public double getIm() {
		return im;
	}

	public void setIm(double im) {
		this.im = im;
	}

}
