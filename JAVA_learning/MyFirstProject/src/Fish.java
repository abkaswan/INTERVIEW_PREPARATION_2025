public class Fish extends Animal implements Prey,Predator {

    // if you have the same named method in the child class you'll use that first , it has precedence
    @Override
    void move(){
        System.out.println("This animal is swimming.");
    }

    @Override
    public void flee(){
        System.out.println("*The fish is swimming away.");
    }
    @Override
    public void hunt(){
        System.out.println("*The fish is hunting.");
    }
}
