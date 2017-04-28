package siarkiewicz.piotr;

import java.util.Collection;
import java.util.HashMap;

/**
 * Created by Siara on 20.11.2016.
 */
public class Maps {
    HashMap<String,Integer> map;
    public Maps(HashMap<String,Integer> map)
    {
        this.map = map;
    }
    public void showMaps()
    {
        Collection<Integer> values = map.values();
        System.out.println(values);

    }
    public Integer amountOfWrod(String word)
    {

        return (Integer)map.get(word);
    }

}
