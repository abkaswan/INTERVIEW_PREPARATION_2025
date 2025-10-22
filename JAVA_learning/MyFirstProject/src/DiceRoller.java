import java.util.Random;
import java.util.Scanner;

public class DiceRoller {
    public void rollIt(){
        // declare variables
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        int numOfDice;
        int total= 0;

        // get # of dice from the users
        System.out.print("Enter the # of dice to roll : ");
        numOfDice = scanner.nextInt();
        // check if # of dice > 0
        if(numOfDice>0){
            for(int i = 0;i<numOfDice;i++){
                int roll = random.nextInt(1,7);
                System.out.println("You rolled: "+roll);
                printDie(roll);
                total+=roll;
            }
            System.out.println("Total: "+total);
        }
        else {
            System.out.println("# of dice must be greater than 0");
        }

        scanner.close();
    }
    void printDie(int roll){
        String dice1 = """
                 -------
                |       |
                |   ◘   |
                |       |
                 -------
                """;
        String dice2 = """
                 -------
                | ◘     |
                |       |
                |     ◘ |
                 -------
                """;
        String dice3 = """
                 -------
                |     ◘ |
                |   ◘   |
                | ◘     |
                 -------
                """;
        String dice4 = """
                 -------
                | ◘   ◘ |
                |       |
                | ◘   ◘ |
                 -------
                """;
        String dice5 = """
                 -------
                | ◘   ◘ |
                |   ◘   |
                | ◘   ◘ |
                 -------
                """;
        String dice6 = """
                 -------
                | ◘   ◘ |
                | ◘   ◘ |
                | ◘   ◘ |
                 -------
                """;
        switch (roll){
            case 1 -> System.out.print(dice1);
            case 2 -> System.out.print(dice2);
            case 3 -> System.out.print(dice3);
            case 4 -> System.out.print(dice4);
            case 5 -> System.out.print(dice5);
            case 6 -> System.out.print(dice6);
            default -> System.out.print("Invalid roll");
        }
    }
}
