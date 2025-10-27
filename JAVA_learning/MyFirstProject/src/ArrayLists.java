import java.util.ArrayList;
import java.util.Scanner;

public class ArrayLists {
    public void run(){
        ArrayList<Integer> list1 = new ArrayList<>();
        ArrayList<Double> list2 = new ArrayList<>();
        ArrayList<String> list3 = new ArrayList<>();

        list1.add(3);
        list1.add(1);
        list1.add(2);
        System.out.println(list1);

        list2.add(3.14);
        list2.add(1.99);
        list2.add(2.01);
        System.out.println(list2);

        list3.add("Stars");
        list3.add("Pluto");
        list3.add("Earth");
        // ---- some useful methods for arrayList -->
        // list3.remove(1);
        // list3.set(0,"Jupiter");
        // System.out.println(list3.get(2));
        // System.out.println(list3.size());
        // Collections.sort(list3);
        for(String ele : list3){
            System.out.println(ele);
        }
        // System.out.println(list3);

        Scanner scanner = new Scanner(System.in);
        ArrayList<String> foods = new ArrayList<>();
        System.out.print("Enter the # of food you would like : ");
        int numOfFood = scanner.nextInt();
        scanner.nextLine();
        for(int i = 1;i<=numOfFood;i++){
            System.out.print("Enter food #"+i+": ");
            String food = scanner.nextLine();
            foods.add(food);
        }
        System.out.println(foods);

        scanner.close();
    }

}
