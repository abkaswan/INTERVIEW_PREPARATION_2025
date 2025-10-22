import java.util.Scanner;

public class ForLoops {
    public void execute()  throws InterruptedException {
        for(int i = 1;i<=10;i++){
            System.out.println(i);
        }
        for(int i = 10;i>0;i--){
            System.out.println(i);
        }
        for(int i = 1;i<=10;i+=2){
            System.out.println(i);
        }
        for(int i = 10;i>0;i-=3){
            System.out.println(i);
        }

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter how many times you want to loop: ");
        int max = scanner.nextInt();

        for (int i = 1;i<=max;i++){
            System.out.println(i);
        }

        // program to simulate a countdown
        System.out.print("How many seconds to count down from?: ");
        int start = scanner.nextInt();

        for (int i = start;i>0;i--){
            System.out.println(i);
            Thread.sleep(1000);
        }
        System.out.println("Happy New year!");

        scanner.close();
    }
}
