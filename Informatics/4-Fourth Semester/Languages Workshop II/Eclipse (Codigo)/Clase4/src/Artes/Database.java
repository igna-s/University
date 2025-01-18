package Artes;

import java.util.ArrayList;
import java.util.Iterator;
/**
* The database class provides a facility to store Book, Video and CD
* objects. A list of all books, CDs and videos can be printed to the
* terminal.
*/
public class Database {
private ArrayList textbooks;
private ArrayList cds;
private ArrayList videos;
/**
* Construct an empty Database.
*/
public Database() {
textbooks = new ArrayList();
cds = new ArrayList();
videos = new ArrayList();
}
/** * Add a textbook to the database.
*/
public void addTextbook(Textbook textbook) {
textbooks.add(textbook);
}
/**
* Add a CD to the database.
*/
public void addCD(CD cd) {

cds.add(cd);
}
/**
* Add a video to the database.
*/
public void addVideo(Video video) {
videos.add(video);
}
/**
* Print a list of all currently stored CDs and videos to the text terminal.
*/
public void list() {
// print list of textbooks
for(Iterator iter = textbooks.iterator(); iter.hasNext(); ) {
Textbook textbook = (Textbook)iter.next();
textbook.print();
System.out.println(); // empty line between items
}
// print list of CDs
for(Iterator iter = cds.iterator(); iter.hasNext(); ) {
CD cd = (CD)iter.next();
cd.print();
System.out.println(); // empty line between items
}
// print list of videos
for(Iterator iter = videos.iterator(); iter.hasNext(); ) {
Video video = (Video)iter.next();
video.print();
System.out.println(); // empty line between items
}
}
}