import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;

public class CountDownTimer {
    public void tick(){
        // JAVA COUNTDOWN TIMER PROGRAM
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter # of seconds to countdown from : ");
        int response = scanner.nextInt();
        Timer timer = new Timer();
        // can use inherit class of TimerTask and can override run method but since one time use , using anonymous class is best option
        TimerTask task = new TimerTask() {

            int count = response;
            @Override
            public void run() {
                System.out.println(count);
                count--;
                if(count<0){
                    System.out.println("Happy NEW YEAR!");
                    timer.cancel();
                }
            }
        };

        // | Method                                     | Type            | Behavior                                                          | When to Use                                                 |
        // | ------------------------------------------ | --------------- | ----------------------------------------------------------------- | ----------------------------------------------------------- |
        // | `schedule(task, delay, period)`            | Fixed **delay** | Waits for previous task to finish, then delays by period          | When tasks should not overlap                               |
        // | `scheduleAtFixedRate(task, delay, period)` | Fixed **rate**  | Runs on a consistent schedule (tries to maintain fixed intervals) | When precise timing matters (like a clock, animation, etc.) |

        timer.scheduleAtFixedRate(task,0,1000); //(task,delay,period)
        // timer.schedule(task,0,1000); //(task,delay,period)

    }
}
