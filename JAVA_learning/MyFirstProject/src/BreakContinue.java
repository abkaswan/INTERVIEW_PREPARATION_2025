public class BreakContinue {
    public void execute(){
        // break = break out of a loop (STOP)
        // continue = skip current iteration of a loop (SKIP)
        for(int i = 0;i<10;i++){
            if(i==1) continue;
            if(i==5) break;
            System.out.println(i+" ");
        }
    }
}
