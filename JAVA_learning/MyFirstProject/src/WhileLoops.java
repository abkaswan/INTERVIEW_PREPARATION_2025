import java.util.Scanner;

public class WhileLoops {
    public void create(){
        Scanner scanner = new Scanner(System.in);

        // in this below example when we use if statement , user can skip this by pressing enter to prevent users from skipping prompts we can use while loop
        String name = "";
        // if(name.isEmpty()){
        //     System.out.print("Enter your name: ");
        //     name = scanner.nextLine();
        // }

        // so using while loop instead of if statement
        while(name.isEmpty()){
            System.out.print("Enter your name: ");
            name = scanner.nextLine();
        }
        System.out.println("Hello "+name);

        // below is example of infinite loop
        // while(1==1){
        //     System.out.println("help! i'm stuck in a loop!");
        // }

        String response = "";
        while(!response.equals("Q")){
            System.out.println("You are playing a game");
            System.out.print("Press Q to quit: ");
            response = scanner.next().toUpperCase();
        }

        // with the do while loop you at least do this code once .
        int age = 0;
        do{
            System.out.println("Your age can't be negative");
            System.out.print("Enter your age: ");
            age = scanner.nextInt();
        }while(age<0);

        System.out.println("You are "+age+" years old");

        int number = 0;
        while(number<1 || number>10){
            System.out.print("Enter a number between 1-10: ");
            number = scanner.nextInt();
        }
        System.out.println("You picked "+number);
        scanner.close();
    }
}
