public class MultiThreading {
    public void fun(){
        // MultiThreading = Enables a program to run multiple threads concurrently
        //                  (Thread = A set of instructions that run independently)
        //                  Useful for background tasks or time-consuming operations

        // two ways as per previous lesson : extends the thread class or implement the runnable interface
        Thread thread1 = new Thread(new MyMultiRunnable("Ping"));
        Thread thread2 = new Thread(new MyMultiRunnable("Pong"));

        System.out.println("Game start!");

        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();

        } catch (InterruptedException e) {
            System.out.println("Main thread was interrupted");;
        }

        System.out.println("Game Over!");
    }
}
