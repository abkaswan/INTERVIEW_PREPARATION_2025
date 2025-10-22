public class TwoDArrays {
    public void fun(){
        // 2D array = an array where each element is an array useful for storing a matrix of data

        String[][] groceries = {{"apple","orange","banana"},
                                {"potato","onion","carrot"},
                                {"chicken","pork","beef","fish"}};

        groceries[0][0] = "pineapple";
        groceries[1][1] = "celery";
        for(String[] foods : groceries){
            for(String food : foods){
                System.out.print(food+" ");
            }
            System.out.println();
        }

        // 2d array that resembles a telphone number pad
        char[][] telephone = {{'1','2','3'},
                             {'4','5','6'},
                             {'7','8','9'},
                             {'*','0','#'}};
        for(char[] row : telephone){
            for(char number : row){
                System.out.print(number + " ");
            }
            System.out.println();
        }

    }
}
