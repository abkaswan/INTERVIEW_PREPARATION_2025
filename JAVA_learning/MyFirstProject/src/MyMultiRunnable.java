public class MyMultiRunnable implements Runnable {
    private final String text ;
    MyMultiRunnable(String text){
        this.text = text;
    }
    @Override
    public void run(){
        for(int i = 1;i<=5;i++){
           try {
               Thread.sleep(1000);
               System.out.println(text + " ---- " + Thread.currentThread().getName()+" "+i);
           }
           catch (InterruptedException e){
               System.out.println("Thread was interrupted.");
           }
        }
    }
}
