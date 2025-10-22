public class PStudent extends Person {
    double gpa;

    PStudent(String first,String last,double gpa){
        super(first,last);
        this.gpa = gpa;
    }
    void showGPA(){
        System.out.println(this.first+" "+this.last+"'s gpa is : "+this.gpa);
    }
}
