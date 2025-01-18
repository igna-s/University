package Artes2;
/***************************************
* This subclass of MultiMediaItem represents a CD object.
****************************************/
public class CD extends MultiMediaItem {
private String artist;
public CD(String title, String artist, String language, int time) {
super(title, language, time);
this.artist = artist;
}
public void print() {
super.print();
System.out.println("Artist: " + artist);
}
}
