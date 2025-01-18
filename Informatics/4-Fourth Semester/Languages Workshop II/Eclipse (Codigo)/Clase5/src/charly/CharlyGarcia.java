package charly;

public class CharlyGarcia {

	private static CharlyGarcia INSTANCE;

	private CharlyGarcia() {}

	public static CharlyGarcia getInstance() {

		if (INSTANCE == null) {
			INSTANCE = new CharlyGarcia();
		}
		return INSTANCE;

	}
	 public void cantar(){
		 System.out.println("Charly Garcia está cantando");}

}
/*
+----------------------------------+
|          CharlyGarcia            |
+----------------------------------+
| - Instance: CharlyGarcia         |
+----------------------------------+
| - CharlyGarcia(): void           |
| + getInstance(): CharlyGarcia    |
|                                  |
+----------------------------------+*/