#include <iostream>
#include <string>
#include <vector>
using namespace std;
void CheckIntInput(int& choice);
void FirstInterface();
void SecondInterface();
int Interface = 0;
class USER
{
private:
	vector<string> Name;
	vector<int> ID;
	vector<int> CodePass;
	vector<float> amount;
public:
	int CheckAmount = -1;
	void AddUser()
	{
		string nm;
		int id;
		int cp;
		cout << "Add a new account" << endl;
		cout << "Name :";
		cin.ignore();
		getline(cin, nm);
		Name.push_back(nm);
		cout << "\nID :";
		cin >> id;
		CheckIntInput(id);
		ID.push_back(id);
		cout << "\nCodePass :" << endl;
		cin >> cp;
		CheckIntInput(cp);
		CodePass.push_back(cp);
		amount.push_back(0.0f);
	}
	void LoginUser()
	{
		int bck;
		if (Name.size() == 0)
		{
			cout << "there is no accounts yet.\n=====Enter 1 to be back :";
			cin >> bck;
			if (bck == 1) { cout << "\nBack..."; }
			else if (bck != 1) {
				cout << "u didnt press number 1 but its okay.🥀💔";
			}
			Interface = 0;
		}
		else
		{
			bool CheckFound = false;
			string nm;
			int id;
			int CP;
			cout << "ID :";
			cin >> id;
			CheckIntInput(id);
			cout << "\nCodePass :";
			cin >> CP;
			CheckIntInput(CP);
			for (size_t i = 0; i < ID.size(); i++)
			{
				if (ID[i] == id && CodePass[i] == CP)
				{
					CheckFound = true;
					Interface++;
					CheckAmount = static_cast<int>(i);
					nm = Name[i];
				}
			}
			if (CheckFound)
			{
				cout << "Login successful." << endl;
				cout << "=========Welcome " << nm << " ============";
			}
			else
			{
				cout << "Incorrect ID or CodePass...." << endl;
				cout << "======================";
				Interface = 0;
			}
		}
	}
	void BalanceOfUser()
	{
		int bck;
		cout << "Balance = " << amount[CheckAmount] << endl;
		cout << "enter a key to be back :";
		cin >> bck;
		Interface = 1;
	}
	void WithdrawMoney()
	{
		if (amount[CheckAmount] >= 0)
		{
			int bck;
			cout << "1. 200DH" << endl;
			cout << "2. 500DH" << endl;
			cout << "3. 1000DH" << endl;
			cout << "4. 2000DH" << endl;
			cout << "enter a number:";
			bool test = true;
			cin >> bck;
			CheckIntInput(bck);
			while (test)
			{
				switch (bck)
				{
					
				case 1:
					if (amount[CheckAmount] >= 200) {
						amount[CheckAmount] -= 200;
						cout << "you withdraw $200 from atm." << endl;
						test = false;
						break;
					}
					else
					{
						cout << "u dont have enough." << endl;
						test = false;
						break;
					}
					
				case 2:
					if (amount[CheckAmount] >= 500) {
					amount[CheckAmount] -= 500;
					cout << "you withdraw $500 from atm." << endl;
					test = false;
					break;
					}
					else
					{
						cout << "u dont have enough." << endl;
						test = false;
						break;
					}
					
				case 3:
					if (amount[CheckAmount] >= 1000)
					{
						amount[CheckAmount] -= 1000;
						cout << "you withdraw $1000 from atm." << endl;
						test = false;
						break;
					}
					else
					{
						cout << "u dont have enough." << endl;
						test = false;
						break;
					}
					
				case 4:
					if (amount[CheckAmount] >= 2000)
					{
						amount[CheckAmount] -= 2000;
						cout << "you withdraw $2000 from atm." << endl;
						test = false;
						break;
					}
					else
					{
						cout << "u dont have enough." << endl;
						test = false;
						break;
					}
				default:
					if (bck > 4)
					{
						cout << "Not a valid number from the list ." << endl;
						cout << "enter a num :";
						cin>>bck;
						CheckIntInput(bck);
					}
					break;
				}
			}
		}
		else if (amount[CheckAmount] <= 0)
		{
			cout << "Brother u have nothing to withdraw bcz YOU ARE BROKE." << endl;
		}


	}
	void DepositMoney()
	{
		
			int bck;
			cout << "1. 200DH" << endl;
			cout << "2. 500DH" << endl;
			cout << "3. 1000DH" << endl;
			cout << "4. 2000DH" << endl;
			cout << "5. 5000DH" << endl;
			cout << "enter a number:";
			bool test = true;
			cin >> bck;
			CheckIntInput(bck);
			while (test)
			{
				switch (bck)
				{

				case 1:
					
						amount[CheckAmount] += 200;
						cout << "you deposited $200 in the bank" << endl;
						test = false;
						break;
					

				case 2:
					
						amount[CheckAmount] += 500;
						cout << "you deposited $500 in the bank" << endl;
						test = false;
						break;
					
					

				case 3:
					
						amount[CheckAmount] += 1000;
						cout << "you deposited $1000 in the bank" << endl;
						test = false;
						break;
					

				case 4:
				
						amount[CheckAmount] += 2000;
						cout << "you deposited $2000 in the bank" << endl;
						test = false;
						break;
					
				case 5:
					
						amount[CheckAmount] += 5000;
						cout << "you deposited $5000 in the bank" << endl;
						test = false;
						break;
				default:
					if (bck > 5)
					{
						cout << "Not a valid number from the list ." << endl;
						cout << "enter a num :";
						cin >> bck;
						CheckIntInput(bck);
					}
					break;
				}
			
		}
	}
};
void CheckIntInput(int& choice)
{
	while (cin.fail()) {
		cout << "Invalid input. Try again but only numbers: "<<endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "enter only numbers :";
		cin >> choice;
	}
}
int main()
{
	USER us;
	int choice ;
	
	while (true)
	{
		if (Interface == 0)
		{
			FirstInterface();
			CheckIntInput(choice);
			switch (choice)
			{
			case 1:

				us.AddUser();
				break;
			case 2:
				us.LoginUser();
				break;
			case 3:
				exit(0);

			default:
				if (choice > 3)
				{
					cout << "Not a valid number from the list ." << endl;
					break;
				}
				
			}
		}
		else if (Interface != 0)
		{
			SecondInterface();
			CheckIntInput(choice);
			switch (choice)
			{
			case 1:

				us.BalanceOfUser();
				break;
			case 2:
				us.WithdrawMoney();
				break;
			case 3:
				us.DepositMoney();
				break;
			case 4:
				cout << "LOOGGING OUT........" << endl;
				Interface = 0;
				break;
			case 5:
				exit(0);

			default:
				if (choice > 6)
				{
					cout << "Not a valid number from the list ." << endl;
					cout << "enter a num :";
					
				}
				break;
			}
		}
	}
	return 0;
}
void FirstInterface()
{
	cout << "\n============================" << endl;
	cout << "1.Sign up" << endl;
	cout << "2.Login" << endl;
	cout << "3.exit" << endl;
	cout << "Choose a num :";
}
void SecondInterface()
{
	cout << "\n1.Balance" << endl;
	cout << "2.withdraw" << endl;
	cout << "3.deposit" << endl;
	cout << "4.log out" << endl;
	cout << "5.exit" << endl;
	cout << "Choose a num :";
}