
/* ID BLOCK:
Name: Thar Soe
Bank Account Simulator

*/

#include <iostream>
#include <iomanip>
#include <string> 
#include <fstream> 


using namespace std;


struct BankAccount {

	int ActNum;
	string LastName;
	string FirstName;
	double Balance; 

	
	//default constructor 
	BankAccount(){

		LastName = "Last Name is Not Set.";
		FirstName = "First Name is Not Set.";
		Balance = 0.0; 
		ActNum = 0; 

	}

	//explicit constructor 

	BankAccount(int act, string first, string last, double bal) {

		ActNum = act;
		FirstName = first; 
		LastName = last;
		Balance = bal;

	}
	
	//struct functions


	void print(){

		cout << fixed << showpoint << setprecision(2)
			<< "Account Number: " << ActNum << endl
			<< "First Name: " << FirstName << endl
			<< "Last Name: " << LastName << endl
			<< "Balance: $" << Balance << endl; 
	}


	void deposit(double Money){

		Balance = Balance + Money; 
	}

	void outprint(ofstream & out) {

		out << fixed << showpoint << setprecision(2)
			<< "Account Number: " << ActNum << endl
			<< "First Name: " << FirstName << endl
			<< "Last Name: " << LastName << endl
			<< "Balance: " << Balance << endl;


	}

	void withdraw(double Money) {

		if (Money <= Balance) {

			Balance = Balance - Money; 
		}

		else {

			cout << "Insufficient Funds." << endl; 
		}


	}

	//get functions


	int getAccountNumber() {

		 return ActNum; 
	}

	string getFirst() {
		return FirstName;
	}

	string getLast(){
		return LastName;
	}

	double getBalance() {
		return Balance; 
	}

	string getFullName() {
		string fullName = FirstName + ' ' + LastName;
		return fullName; 
	}

	//set function

	void setLastName(const string &newLastName) {

		LastName = newLastName; 

	} 

};


//int getAccountNumber();
//string getFirst();
//string getLast();
//double getBalance();
//string getFullName();
//void print();
//void print(ofstream &out); 


int main() {
	BankAccount bank; 
	bool done = false; 
	cout << showpoint << setprecision(2) << fixed << left;

	while (!done) {

		cout << "  Main Menu " << endl
			<< "1. Create An Account." << endl
			<< "2. Print Details to Console." << endl
			<< "3. Print Details to an Output File." << endl
			<< "4. Make a Deposit" << endl
			<< "5. Make a Withdrawal:" << endl
			<< "6. Print Current Balance: " << endl
			<< "7. Print Account Holder's Full Name: " << endl
			<< "8. Exit." << endl;



		int choice;
		cin >> choice;

		if (choice == 8) {

			done = true;
		}
		else if (choice == 1){

			int act = 0;
			string first, last;
			double bal = 0.0;


			cout << "Enter Your Account Number: ";
			cin >> act;
			cout << "Enter Your First and Last Name in that order: ";
			cin >> first >> last;
			cout << "Enter Your Balance Amount: ";
			cin >> bal;

			bank = BankAccount(act, first, last, bal);
		}

		else if (choice == 2) {
			bank.print();
		}
		else if (choice == 3) {

			string outFile;
			cout << "Please Enter the Full Output Path File Name: ";
			cin.ignore();
			getline(cin, outFile);
			ofstream out(outFile);

			if (out.is_open()) {

				bank.outprint(out); 
			}

			else {

				cout << "Unable to Create Output File." << endl;

			}
			out.close();

		}

		else if (choice == 4) {
			double money = 0.0;
			cout << "Enter the Amount to Deposit: ";
			cin >> money;
			bank.deposit(money);
		}
		else if (choice == 5) {
			double money = 0.0;
			cout << "Enter the Amount to Withdraw: "; 
			cin >> money; 
			bank.withdraw(money);

		}
		else if (choice == 6) {
			bank.print();
		}

		else if (choice == 7) {
			bank.getFullName();

		}


	}



	return (0);
}