package project;

public class Balance {
	
	//instances
    private int CurrentBalance;

    //constructor
    public Balance (int balance){
        CurrentBalance = balance;
    }

    //get balance method
    public int getBalance () {
        return CurrentBalance;
    }

    //deposit money and make sure the amount is valid
    public void depositMoney (int Amount) {
        if (Amount > 0) {
            CurrentBalance += Amount;
            System.out.println ("Deposited: " + Amount);
            System.out.println ("Your new account balance is: " + CurrentBalance);
        } else {
            System.out.println("Invalid deposit amount!");
        }
    }

    //withdraw money and check it doesn't withdraw more than what's already in balance
    public void withdrawMoney (int Amount) {
        if (Amount > 0 && Amount <= CurrentBalance) {
            CurrentBalance -= Amount;
            System.out.println("Withdrawal successful. Amount withdrawn: " + Amount);
            System.out.println("Your remaining balance is: " + CurrentBalance);
        } else {
            System.out.println("You cannot withdraw " + Amount + " due to insufficient balance, remaining balance is: " + CurrentBalance);
        }
    }

    //print current balance
    //override method
    public String toString() {
        return "Current Balance: " + CurrentBalance;
    }
}
