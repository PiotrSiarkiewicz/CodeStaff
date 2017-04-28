package siarkiewicz.piotr;

import org.jsoup.Connection;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.select.Elements;

import java.io.IOException;
/**
 * Created by Siara on 19.11.2016.
 */


public class UploadWebSite {
    private
    Connection connect;
    Document doc;
    Elements elem;
    public UploadWebSite(String url)
    {
        connect =  Jsoup.connect(url);


    }
    public String extractText() throws IOException {
        doc =  connect.get();
        elem = doc.select("div.song-text");
        return elem.toString();
    }
}