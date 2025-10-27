import java.util.Scanner;

public class Threading {
    public void run(){
        // Threading = Allows a program to run multiple tasks simultaneously
        //             Helps improve performance with time-consuming operations
        //             (File I/O, n/w communications , or any background tasks)

        // How to create a thread
        // Option 1 : Extend the Thread class (simpler)
        // Option 2 : Implement the Runnable interface (better)

        Scanner scanner = new Scanner(System.in);

        MyRunnable myRunnable = new MyRunnable();
        Thread thread = new Thread(myRunnable);
        thread.setDaemon(true);
        thread.start();

        System.out.println("You have 5 seconds to enter your name.");
        System.out.print("Enter your name : ");
        String name = scanner.nextLine();
        System.out.println("Hello "+name);

        scanner.close();

    }
}
