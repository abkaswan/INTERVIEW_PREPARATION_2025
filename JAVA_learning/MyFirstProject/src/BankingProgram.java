import java.util.Scanner;

public class BankingProgram {
    Scanner scanner = new Scanner(System.in);
    public void run(){
        // declare variables

        double balance = 0;
        boolean isRunning = true;
        int choice;

        while(isRunning) {
            // display menu
            System.out.println("***************");
            System.out.println("BANKING PROGRAM");
            System.out.println("***************");
            System.out.println("1. Show balance");
            System.out.println("2. Deposit");
            System.out.println("3. Withdraw");
            System.out.println("4. Exit");
            System.out.println("***************");

            System.out.print("Enter your choice (1-4): ");
            choice = scanner.nextInt();
            switch (choice) {
                case 1 -> showBalance(balance);
                case 2 -> balance += deposit();
                case 3 -> balance -= withdraw(balance);
                case 4 -> isRunning = false;
                default -> System.out.println("Invalid choice. Please try again.");
            }
            System.out.println("***************");
            System.out.println("Thank you ! Have a nice day ");
            System.out.println("***************");

        }

        // deposit()
        // withdraw()
        // EXIT message
        scanner.close();
    }
    void showBalance(double balance){
        System.out.println("***************");
        System.out.printf("$%.2f\n",balance);
    }
    double deposit(){
        double amount;
        System.out.print("Enter an amount to be deposited: ");
        amount = scanner.nextDouble();
        if(amount<0){
            System.out.println("Amount can't be negative");
            return 0;
        }
        else{
            return amount;
        }

    }
    double withdraw(double balance){
        double amount;
        System.out.print("Enter amount to be withdrawn: ");
        amount = scanner.nextDouble();

        if(amount>balance){
            System.out.println("INSUFFICIENT FUNDS");
            return 0;
        }
        else if(amount<0){
            System.out.println("Amount cna't be negative.");
            return 0;
        }
        else{
            return amount;
        }
    }
}
