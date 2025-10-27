import java.util.ArrayList;

public class Generics {
    public void run(){
        // Generics = A concept where you can write a class, interface or method
        //            that is compatible with different data types.
        //            <T> type parameter (placeholder that gets replaced with a real type)
        //            <String> type argument (specific the type)

        // this is type argument because we are specifying what we are creating in ArrayList
        // if you will go to ArrayList implementation you will see ArrayList<E> type parameters there
        ArrayList<String> fruits = new ArrayList<>();
        fruits.add("apple");
        fruits.add("orange");
        fruits.add("banana");

        // creating and using type parameter
        Box<String> box = new Box<>();
        box.setItem("banana");
        System.out.println(box.getItem());

        Box<Integer> box1 = new Box<>();
        box1.setItem(3);
        System.out.println(box1.getItem());

        // now we can also have two or more types also , ex :
        Product<String,Double> product1 = new Product<>("Apple",0.30);
        Product<String,Integer> product2 = new Product<>("ticket",15);

        System.out.println(product1.getItem());
        System.out.println(product2.getPrice());

    }
}
