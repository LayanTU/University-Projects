package projectTest;
import java.util.Scanner;
import project.Transaction;

public class FlowerBank {

	public static void main (String[] args) {
		
		//instance to allow user inputs
		Scanner input = new Scanner (System.in);
		System.out.println ("Welcome to Flower Bank!");

		//user inputs
        System.out.print ("Enter your name: ");
        String Name = input.nextLine ();

        System.out.print ("Enter a 4-digit password: ");
        int Password = input.nextInt ();
        
        //check password validity
        Transaction temp = new Transaction(Name, Password, 0, 0, 0); 
        temp.checkPassword(input); 
        
        //display account types for the user
        System.out.println ("Choose your account type: ");
        System.out.println ("1. Platinum Account \n (Minimum balance: 10,000)");
        System.out.println ("2. Standard Account \n (Minimum balance: 1,000)");

        //user input
        System.out.print ("Enter your account type (1 or 2): ");
        int AccountType = input.nextInt ();
        
        //user balance and transaction amount input
        System.out.print ("Enter your current balance: ");
        int balance = input.nextInt ();

        //create a user with user's inputs
        Transaction TransferAmount = new Transaction (Name, Password, AccountType, balance, 0);

        //toString override method
        //print user account details
        System.out.println ("----------");
        System.out.println ("User Details: ");
        System.out.println (TransferAmount);
        System.out.println ("----------");
        
        //operation menu for the user to choose from
        int choice = 0; 
        while (choice != 6) { 
        	System.out.println ("\n Choose an operation:");
        	System.out.println ("1. View Account Balance");
        	System.out.println ("2. View Minimum Transaction Limit");
        	System.out.println ("3. Deposit Money");
        	System.out.println ("4. Withdraw Money");
        	System.out.println ("5. Perform Transaction");
        	System.out.println ("6. Exit");
        	System.out.print ("Enter your choice: ");
            
        	choice = input.nextInt ();

            switch (choice) {
            
            	//show account balance
            	case 1: 
            		System.out.println ( TransferAmount.getBalance ()); 
            		//System.out.println ("Your account balance is: " + TransferAmount.getBalance());
            	    break;
            		
            	//show minimum limit based on account type	
            	case 2:
                    int minimumLimit = TransferAmount.minimumLimit ();
                    System.out.println ("The minimum balance for your account type is: " + minimumLimit);
                    
                    break;

                //deposit money
            	case 3:
            		System.out.print ("Enter the deposit amount: ");
                    int DepositAmount = input.nextInt ();
                    TransferAmount.getBalance ().depositMoney (DepositAmount);
               
                    break;
                    
                //withdraw money
            	case 4:
            		System.out.print ("Enter the withdraw amount: ");
            		int WithdrawAmount = input.nextInt ();
            		TransferAmount.getBalance ().withdrawMoney (WithdrawAmount);
                       
            		break;
            		
            	//perform transaction
            	case 5:
            		System.out.print ("Enter the transaction amount: ");
            		int TransactionAmount = input.nextInt ();
            		TransferAmount.setTransferAmount (TransactionAmount);

            		TransferAmount.performTransaction ();
            		
            		break;
                     
            	//exit the menu
            	case 6:
            		System.out.println ("Thank you for trusting Flower Bank!");
            		return; 

            	//error message in case user entered invalid input
            	default:
            		System.out.println ("Invalid choice! Please try again.");
            }
        } 
        
        //create new user to compare
        Transaction Maha = new Transaction ("Maha", 2019, 2, 4500, 600);

        //compare users
    	System.out.println ("Comparing Users: ");
        
        if (TransferAmount.equals (Maha)) {
            System.out.println ("The users are the same");
        } else {
            System.out.println ("The users are different");
        }
        
        //toString override method
        //display final balance details
        System.out.println ("\n Final Balance Details:");
        System.out.println (TransferAmount.getBalance ());
        
        input.close ();
	}
}
