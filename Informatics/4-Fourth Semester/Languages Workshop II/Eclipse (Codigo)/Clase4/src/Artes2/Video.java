package Artes2;

/******************************************
* This subclass of the class MultiMediaItem represents a video object.
******************************************/
public class Video extends MultiMediaItem {
private String director;
public Video(String theTitle, String theDirector, String theLanguage, int time) {
super(theTitle, theLanguage, time);
director = theDirector;
}
public String getDirector() {
return director;
}
public void print() {
super.print();
System.out.println("Director: " + director);
}
}
