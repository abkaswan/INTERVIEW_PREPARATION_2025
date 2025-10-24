public class BankAccount {

    private String accountNumber;
    private double balance;
    BankAccount(String accountNumber,double balance){
        this.accountNumber = accountNumber;
        this.balance = balance;
    }
    // getter
    String getAccountNumber(){
        return this.accountNumber;
    }
    // setter
    void setAccountNumber(String accountNumber){
        this.accountNumber = accountNumber;
    }
    // getter
    String getBalance(){
        return "$"+this.balance;
    }
    // setter with validation
    void setBalance(double balance) {
        if (balance < 0) {
            System.out.println("Price can't be less than zero.");
        } else {
            this.balance = balance;
        }
    }
}
