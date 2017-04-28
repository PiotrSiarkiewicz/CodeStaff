package siarkiewicz.piotr;



        import java.util.Arrays;
        import java.util.HashMap;
        import java.util.stream.Collectors;

/**
 * Created by Siara on 19.11.2016.
 */
public class Parser {
    public Parser()
    {

    }
    public static HashMap<String,Integer> createHashMap(String tekst)
    {

        HashMap map = new HashMap<String,Integer>();
        //String[] parts = Arrays.asList(tekst.split(" ")).stre;
        Arrays.stream(tekst.split(" "))
        .map(x -> map.containsKey(x) ? map.put(x, (Integer) map.get(x) + 1) : map.put(x, 1)).count();
//        Integer value;
//        for(int i=0; i<parts.length;i++)
//        {
//            //System.out.println(map.containsKey(parts[i]));
//            if(map.containsKey(parts[i]) == false) {
//                map.put(parts[i], 1);
//            }else
//            {
//                value = (Integer) map.get(parts[i])+1;
//                map.put(parts[i],value);
//            }
//        }
        return map;
    }
}