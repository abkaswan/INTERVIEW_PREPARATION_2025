import java.util.Scanner;

public class UserInputArray {
    public void fun(){
        Scanner scanner = new Scanner(System.in);

        // with static size :
        // String[] foods = new String[3];
        // foods[0] = "pizza";
        // foods[1] = "taco";
        // foods[2] = "hamburger";
        // System.out.println(foods.length);

        String[] foods;
        int size;

        System.out.print("What # of food do you want? : ");
        size = scanner.nextInt();
        // clear the input buffer
        scanner.nextLine();
        foods = new String[size];

        for(int i = 0;i<foods.length;i++){
            System.out.print("Enter a food: ");
            foods[i] = scanner.nextLine();
        }

        for(String food : foods){
            System.out.println(food);
        }

        scanner.close();
    }
}
