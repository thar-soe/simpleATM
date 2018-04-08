//Programmer: Thar Soe
//Create an ATM account simulation with set limits and balance


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 


using namespace std; 


struct CreditCard {

	string CCN;
	string lastName;
	string firstName;
	double Balance;
    double creditLimit;



	CreditCard() {

		firstName = "First Name Not Set"; 
		lastName = "Last Name Not Set";
		CCN = "Credit Card not set";
		Balance = 0.0; 
		creditLimit = 1500.00; 
	}


	CreditCard(string first, string last, string creditNum) {

		firstName = first;
		lastName = last; 
		CCN = creditNum;
		Balance = 0.0; 
		creditLimit = 1500.00;

	}

	
	string getFirstName()
	{
		return firstName;
	}
	string getLastName()
	{
		return lastName;
	}
	string getFullName()
	{
		return firstName + ' ' + lastName;
	}
	string getCreditCardNumber()
	{
		return CCN;
	}
	double getBalance()	{
		return Balance;
	}
	double getCreditLimit()
	{
		return creditLimit;
	}


	void ChargetoCard(double money) {

		double availableCredit = creditLimit - Balance; 

		if (money <= availableCredit) {

			Balance += money;

		}

		else {

			cout << "Insufficient Funds." << endl;
		}


	}


	void makePaymentToCard(double money) {

	Balance -= money; 

	}

	void print(){

		cout << fixed << showpoint << setprecision(2);
		cout << "Name: " << firstName << ' ' << lastName << endl
			<< "Credit Card Number: " << CCN << endl
			<< "Amount owed: $" << Balance << endl;
		if (Balance == 0) {

			cout << "Charge Declined due to Insufficient Funds." << endl;

		}
			cout << "------------------------------" << endl; 
	}


};

const int MAX = 100; 
void bubbleSort(CreditCard ccArr[], int flag, int len);
void print(CreditCard ccArr[], size_t len); 
int LinearSearch(CreditCard ccArr[], CreditCard CC, int flag, int len); 



int main() {

	CreditCard CC1("JIM", "JONES", "56738");
	CC1.ChargetoCard(200.99);
	CreditCard CC2("ADAM", "ASHLEY", "12345");
	CC2.ChargetoCard(2000.00);
	CreditCard CC3("BERTHA", "MAPOS", "34567");
	CC3.ChargetoCard(800.91);
	CreditCard CC4("LISA", "BRAVE", "98765");
	CC4.ChargetoCard(1001.23);
	CreditCard CC5("WILLY", "NILLY", "23413");
	CC5.ChargetoCard(700.00);
	CreditCard CC6("JILL", "QUIRK", "67895");
	CC6.ChargetoCard(1400.91);

	CreditCard CardArray[MAX];
	CardArray[0] = CC1;
	CardArray[1] = CC2;
	CardArray[2] = CC3;
	CardArray[3] = CC4;
	CardArray[4] = CC5;
	CardArray[5] = CC6;

	bool done = false;
	CreditCard cc;

	while (!done) {

		cout << "Main Menu" << endl
			<< "Please select from the following:" << endl
			<< " 1. Print Current List of Credit Cards" << endl
			<< " 2. Sort Credit Cards Based on Last Name" << endl
			<< " 3. Sort Credit Cards Based on Credit Card Number" << endl
			<< " 4. Sort Credit Cards Based on Balance" << endl
			<< " 5. Search Credit Card Based on Customer's Last Name" << endl
			<< " 6. Search Credit Card Based on Credit Card Number" << endl
			<< " 7. Exit." << endl;

		int choice;
		cout << "Enter Your Desired Choice: ";
		cin >> choice;

		if (choice == 7) {

			done = true;

		}

		else if (choice == 1){

			print(CardArray, 6);

		}
		else if (choice == 2){
			bubbleSort(CardArray, 1, 6);

		}
		else if (choice == 3){
			bubbleSort(CardArray, 2, 6);

		}
		else if (choice == 4){

			bubbleSort(CardArray, 3, 6);

		}
		else if (choice == 5){

			int found;
			string person;

			cout << "Enter the Name of the Person You're Looking For: ";
			cin >> person;

			cc.lastName = person;

			found = LinearSearch(CardArray, cc, 1, 6);
			if (found >= 0) {
				cout << "That person is found at index: " << found << endl;
				cout << fixed << showpoint << setprecision(2);
				cout << "Name: " << CardArray[found].firstName << ' ' << CardArray[found].lastName << endl
					<< "Credit Card Number: " << CardArray[found].CCN << endl
					<< "Amount owed: $" << CardArray[found].Balance << endl;

				cout << "------------------------------" << endl;
			}
			else {
				cout << "There's no one by that Last Name." << endl;

			}
		}
	

		else if (choice == 6){
		
			int found;			
			string ccNum;

			cout << "Enter the Credit Card Number That You'd like to Find: ";
			cin >> ccNum;
			cc.CCN = ccNum; 
			found = LinearSearch(CardArray, cc, 2, 6);

	if (found >= 0) {
				cout << "That person is found at index: " << found << endl;
				cout << fixed << showpoint << setprecision(2);
				cout << "Name: " << CardArray[found].firstName << ' ' << CardArray[found].lastName << endl
					<< "Credit Card Number: " << CardArray[found].CCN << endl
					<< "Amount owed: $" << CardArray[found].Balance << endl;


				cout << "------------------------------" << endl;
			}
			else {
				cout << "There's no one by that Last Name." << endl;

			}

		
		}


	}



	return (0);
}




void bubbleSort(CreditCard ccArr[], int flag, int len){


	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (flag == 1)// sort based on Last Name
			{
				if (ccArr[j].lastName > ccArr[j + 1].lastName)
				{
					CreditCard Temp;
					Temp = ccArr[j];
					ccArr[j] = ccArr[j + 1];
					ccArr[j + 1] = Temp;
				}
			}
			else if (flag == 2)//sort based on CCN
			{
				if (ccArr[j].CCN > ccArr[j + 1].CCN)
				{
					CreditCard Temp;
					Temp = ccArr[j];
					ccArr[j] = ccArr[j + 1];
					ccArr[j + 1] = Temp;
				}
			}
			else if (flag == 3)// Sort based on balance
			{
				if (ccArr[j].Balance > ccArr[j + 1].Balance)
				{
					CreditCard Temp;
					Temp = ccArr[j];
					ccArr[j] = ccArr[j + 1];
					ccArr[j + 1] = Temp;
				}
			}
			
		}
	}
}
void print(CreditCard ccArr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		ccArr[i].print();
		cout << "--------------------------------\n";
	}
	cout << "--------------------------------\n";
}

int LinearSearch(CreditCard ccArr[], CreditCard CC, int flag, int len) {


	for (int i = 0; i < len; i++)
	{
		if (flag == 1)
		{
			if (ccArr[i].lastName == CC.lastName)

			{
				return i; 
			}
		}
		else if (flag == 2)
		{
			if (ccArr[i].CCN == CC.CCN)
			{
				return i;
				
			}
		}
		
	}
	return -1;
}
