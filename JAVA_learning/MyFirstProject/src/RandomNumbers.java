import java.util.Random;

public class RandomNumbers {
    public void run(){
        // random numbers

        Random random = new Random();
        int number1 ;
        int number2;
        int number3;

        // if you only give random.nextInt() it will give randome between Integer.MIN_VALUE to Integer.MAX_VALUE.
        // gives the origin and bound , so this gives us the random number between 1 and 5
        number1 = random.nextInt(1,6);
        number2 = random.nextInt(1,6);
        number3 = random.nextInt(1,6);

        System.out.println(number1);
        System.out.println(number2);
        System.out.println(number3);

        double number4;
        // if you only give random.nextDouble it will generate a double between 0 and 1
        number4 = random.nextDouble(1,100);
        System.out.println(number4);

        boolean isHeads;
        isHeads = random.nextBoolean();
        if(isHeads){
            System.out.println("Heads");
        }
        else {
            System.out.println("Tails");
        }

    }
}
