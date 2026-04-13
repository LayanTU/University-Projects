package project;
import java.util.Scanner;

public abstract class User {

	//instances 
	private String Name;
	private int Password;
	private int AccountType;
	
	//constructor
	public User(String name, int pass, int type) {
		Name = name;
		Password = pass;
		AccountType = type;
	}
	
	//set && get the user's info methods
	public void setName (String name) {
		Name = name;
	}
	
	public String getName () {
		return Name;
	}
	
	public void setPassword (int pass) {
		Password = pass;
	}
	
	public int getPassword () {
		return Password;
	}
	
	public void setAccountType (int type) {
		AccountType = type;
	}
	
	public int getAccountType () {
		return AccountType;
	}
	
	//check password validity
	public void checkPassword (Scanner input) {
		
		if (Password < 1000) {
			System.out.println ("Insufficient digits!");
		} else if (Password > 9999) {
			System.out.println ("Too many digits!");
		} else {
			System.out.println ("Password is valid!");
		}

	}
	
	//assign minimum transfer limit based on the user's account type
	public int minimumLimit () {
		if (AccountType == 1) {
			return 10000;  //Platinum account type
		} else if (AccountType == 2) {
			return 1000;  //Standard account type
		} else {
			return 0; 
		}
	}
	
	//print user's info
	//override method
	public String toString () {
		return "Name: " + Name + "\n" + "Password: " + Password + "\n" + "Account type: " + AccountType + "\n";
	}
	
	//abstract method
	public abstract void validateUserDetails (Scanner input);
	
}
