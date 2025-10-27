import java.sql.Time;
import java.util.Timer;
import java.util.TimerTask;

public class TimerTasks {
    public void wow(){
        // Timer = Class that schedules tasks at specific times or periodically
        //         Useful for : sending notifications, scheduled updates , repetitive actions

        // TimerTask = Represents the task that will be executed by the Timer
        //             You will extend the TimerTask class to define your task
        //             Create a subclass of TimerTask and @Override run()

        Timer timer = new Timer();
        TimerTask timerTask = new TimerTask() {
            int count = 3;
            @Override
            public void run() {
                System.out.println("Hello Abhishek!");
                count--;
                if(count<=0){
                    System.out.println("Greetings done bitch!");
                    timer.cancel();
                }
            }
        };
        timer.schedule(timerTask,0,1000);
    }
}
