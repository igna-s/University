package Artes;

/***************************************
* The CD class represents a CD object.
***************************************/
public class CD {
private String title;
private String artist;
private String language;
private int playingTime;
private boolean available;
private String comment;
public CD(String title, String artist, String language, int time) {
this.title = title;
this.artist = artist;
this.language = language;
playingTime = time;
available = true;
comment = "<no comment>";
}
public void setComment(String comment) {
this.comment = comment;
}
public boolean getAvailable() {
return available;
}
public void print() {

System.out.print("Title: " + title);
if(available) System.out.println("*");
else System.out.println();
System.out.println("Comment: " + comment);
System.out.println("Language: " + language);
System.out.println("Playing time: " + playingTime + " mins");
System.out.println("Artist: " + artist);
}
}