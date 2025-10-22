import java.util.Scanner;

public class SearchArray {
    public void fun(){
        Scanner scanner = new Scanner(System.in);
        int[] numbers = {1,9,2,8,3,5,4};
        String[] fruits = {"apple","orange","banana"};
        int target = 7;
        String targetFruit;
        boolean isFound = false,isFoundFruit = false;

        System.out.print("Enter a fruit to search for : ");
        targetFruit = scanner.nextLine();

        //searching inside the int array
        for(int i = 0;i< numbers.length;i++){
            if(target == numbers[i]){
                System.out.println("element found at index "+i);
                isFound = true;
                break;
            }
        }
        if(!isFound){
            System.out.println("Element not found in the int array");
        }

        //searching inside the fruits array
        for(int i = 0;i< fruits.length;i++){
            // since strings are reference data types we will end up comparing memory addresses of these two which isn't the same as comparing them
            if(fruits[i].equals(targetFruit)){
                System.out.println("fruit found at index "+i);
                isFoundFruit = true;
                break;
            }
        }
        if(!isFoundFruit){
            System.out.println("Fruit not found in the fruits array");
        }
    }
}
