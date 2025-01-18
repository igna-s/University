package Artes;

/***************************************
* The Video class represents a video object.
* **************************************/
public class Video {
private String title;
private String director;
private String language;
private int playingTime;
private boolean available;
private String comment;
public Video(String title, String director, String language, int time) {
this.title = title;
this.director = director;
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
System.out.println("Director: " + director);
}
}