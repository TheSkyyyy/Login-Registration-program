#include<iostream>
#include<istream>
#include<fstream>
#include<cstdlib>
using namespace std;

bool logged_in() {
	string username,password,us,pa;
	
	cout<<"Enter Username: ";
	cin>>username;
	cout<<"Enter Password: ";
	cin>>password;
	cout<<endl;
	
	ifstream data("Account.txt");
	(data>>us>>pa);

	if(us==username && pa==password) {
		return true;
	} else {
		return false;
	}
}
int main() {
	
	int choice;
	string username,password,us,pa;
	
	cout<<"1. Register\n2. Login\nEnter Choice: ";
	cin>>choice;
	
	if (choice==1) {
		cout<<"Select a Username: ";
		cin>>username;
		cout<<"Select a Password: ";
		cin>>password;
		cout<<endl;
		
		ofstream data("Account.txt",ios::app); 
		data<<username<<" "<<password<<endl;
		cout<<"Registration Successful\n\n";
		main();
		data.close();
		}  else if (choice==2) {	
		bool a=logged_in();
		if (!a) {
			cout<<"Invalid username or password.";
			return 0;
		} else {
			cout<<"You have logged in successfully.";
			return 1;
		}
	} else {
		cout<<"Invalid entry. Please try again.";
		main();
	}
}
