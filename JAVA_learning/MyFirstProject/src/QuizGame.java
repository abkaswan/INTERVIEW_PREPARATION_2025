import java.util.Scanner;

public class QuizGame {
    public void play(){
        // java quiz game

        String[] questions = {"What is the main function of a router?",
                            "Which part of the computer is considered the brain?",
                            "What year was Facebook launched?",
                            "Who is known as the father of computer?",
                            "What was the first programming language?"};

        // options array[][]
        String[][] options = {{"1. Forwarding","2. Routing","3. Switching","4. All of the above"},
                            {"1. CPU","2. Monitor","3. Keyboard","4. Mouse"},
                            {"1. 2004","2. 2005","3. 2006","4. 2007"},
                            {"1. Charles Babbage","2. Alan Turing","3. John von Neumann","4. Bill Gates"},
                            {"1. Fortran","2. COBOL","3. Assembly Language","4. All of the above"}};
        int[] answers = {2,1,1,1,4};
        int score = 0;
        int guess;
        Scanner scanner = new Scanner(System.in);
        System.out.println("******************************");
        System.out.println("Welcome to the JAVA quiz game!");
        System.out.println("******************************");

        for(int i = 0;i< questions.length;i++){
            System.out.println(questions[i]);
            for(String option : options[i]){
                System.out.println(option);
            }

            System.out.print("Enter your guess : ");
            guess = scanner.nextInt();

            if(guess == answers[i]){
                System.out.println("*******");
                System.out.println("CORRECT!");
                System.out.println("*******");
                score++;
            }
            else{
                System.out.println("*******");
                System.out.println(" WRONG! ");
                System.out.println("*******");
            }
        }
        System.out.println("Your final score is : "+score+" out of "+questions.length);
        scanner.close();
    }
}
