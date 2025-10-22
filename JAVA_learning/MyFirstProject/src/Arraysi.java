import java.util.Arrays;

public class Arraysi {
    public void main(){
        // array => a collection of values of the same data type , think of it as a variable that can store more than 1 value
        // arrays is a refernece data point so printing it will give memory address
        String[] fruits = {"apple","orange","banana","coconut"};
        System.out.println(fruits);
        System.out.println(fruits[0]);
        fruits[0]= "pineapple";
        System.out.println(fruits[0]);

        int numOfFruits = fruits.length;
        System.out.println(numOfFruits);
        System.out.println("All the elements in the array fruits are : ");
        for(int i = 0;i<numOfFruits;i++){
            System.out.print(fruits[i]+" ");
        }
        System.out.println("\nPrinting it in another way (enhanced for loop OR for each loop) ->");
        for(String fruit : fruits){
            System.out.print(fruit+" ");
        }

        // sort the array
        Arrays.sort(fruits);
        System.out.println("\nAfter sorting : ");
        for(String fruit : fruits){
            System.out.print(fruit+" ");
        }

        // use fill to fill the array
        Arrays.fill(fruits,"pineapple");
        System.out.println("\nAfter filling : ");
        for(String fruit : fruits){
            System.out.print(fruit+" ");
        }

    }
}
