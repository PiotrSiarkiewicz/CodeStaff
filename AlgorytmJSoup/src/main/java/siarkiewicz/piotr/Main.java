package siarkiewicz.piotr;
import java.io.IOException;

/**
 * Created by Siara on 18.11.2016.
 */
public class Main
{
    public static void main(String[] args) throws IOException    {

        UploadWebSite webSite = new UploadWebSite("http://www.tekstowo.pl/piosenka,big_cyc,babcia_klozetowa.html");
        System.out.println(webSite.extractText());
        Maps map = new Maps(Parser.createHashMap(webSite.extractText()));
        // map.showMaps();
        System.out.println("Liczba słów: "+map.amountOfWrod("<br"));
    }













}