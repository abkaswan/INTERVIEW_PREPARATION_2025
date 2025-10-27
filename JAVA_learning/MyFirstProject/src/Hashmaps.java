import java.util.HashMap;

public class Hashmaps {
    public void run(){
        // HashMap = a data structure that stores key-value pairs
        //           Keys are unique , but values can be duplicated
        //           Does not maintain any order, but is memory efficient
        //           HashMap<Key, Value>

        HashMap<String , Double> map = new HashMap<>();
        map.put("apple",0.50);
        map.put("orange",0.75);
        map.put("banana",0.25);
        map.put("coconut",1.00);
        // so if you put another key-value pair within the hashmap where keys are not unique , it will just override the previous value
        map.put("apple",0.56567);

        // remove
        // map.remove("apple");

        // get the value with the key
        System.out.println(map.get("coconut"));

        // print the hashmap
        System.out.println(map);

        // check if a key or value exist, for key , ex :
        System.out.println(map.containsKey("banana"));
        if(map.containsKey("pineapple")){
            System.out.println(map.get("apple"));
        }
        else {
            System.out.println("key not found.");
        }

        // for value , ex :
        System.out.println(map.containsValue(1.00));

        // size
        System.out.println(map.size());

        // display the map
        System.out.println("\nBelow is the map --->");
        for(String key : map.keySet()){
            System.out.println(key+" : $"+map.get(key));
        }
    }
}
