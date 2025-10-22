import java.util.Scanner;

public class NestedLoops {
    public void run(){
        //nested loop = a loop inside another loop , used often with matrices or DSA
        for(int i = 1;i<=3;i++){
            for(int j = 1;j<=9;j++){
                System.out.print(j+" ");
            }
            System.out.println();
        }

        Scanner scanner = new Scanner(System.in);
        int rows;
        int cols;
        char symbol;

        System.out.print("Enter the # of rows : ");
        rows = scanner.nextInt();
        System.out.print("Ente the # of cols : ");
        cols = scanner.nextInt();
        System.out.print("Enter the symbol to use: ");
        symbol = scanner.next().charAt(0);

        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                System.out.print(symbol);
            }
            System.out.println();
        }

        scanner.close();

    }
}
