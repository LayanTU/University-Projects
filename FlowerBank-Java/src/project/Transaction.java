package project;
import java.util.Scanner;

public class Transaction extends User {
	
	//instances
    private int TransferAmount;
    private Balance balance;

    //constructor
    public Transaction (String Name, int Password, int AccountType, int balance, int TransactionAmount) {
        super (Name, Password, AccountType);
        TransferAmount = TransactionAmount;
        this.balance = new Balance (balance); //composition
    }

    //set && get 
    public void setTransferAmount (int TransactionAmount) {
        TransferAmount = TransactionAmount;
    }
    
    public int getTransferAmount () {
        return TransferAmount;
    }

    public Balance getBalance () {
        return balance;
    }
    
    //abstract method used
    public void validateUserDetails(Scanner input) {
        checkPassword(input);
    }
    
    //check transaction validity && perform transaction
    public void performTransaction () {
        int limit = minimumLimit ();
        
        if (TransferAmount <= balance.getBalance () && balance.getBalance () - TransferAmount >= limit) {
            balance.withdrawMoney (TransferAmount);
            System.out.println ("Transaction approved!");
        } else {
            System.out.println ("Transaction denied! Amount exceeds limits.");
        }
    }

    //print transaction details
    //override method
    public String toString () {
        return super.toString () + "Transaction Amount: " + TransferAmount + ", " + balance.toString ();
    }
}
