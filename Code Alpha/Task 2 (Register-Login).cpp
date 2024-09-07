#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

string hide_password() {
    string temp_pass;
    char ch;
    while (true) {
        ch = getch();
        if (ch == '\r' || ch == '\n') {
            cout << endl;
            break;
        } else if (ch == '\b') {
            if (!temp_pass.empty()) {
                cout << "\b \b";
                temp_pass.pop_back();
            }
        } else {
            temp_pass.push_back(ch);
            cout << '*';
        }
    }
    return temp_pass;
}

void Register(){
	string username;
	string password;
	
	cout << "Welcome To Registration Page:" << endl;
	
	cout << "Enter Your Username: ";
	cin >> username;
	
	cout << endl;
	
	cout << "Enter Your Password: ";
	password = hide_password();
	
	ofstream outfile("database.txt", ios::app);

    if (outfile.is_open()) {
        outfile << username << " " << password << endl;
        outfile.close();
        cout << "Registration successful!" << endl;
    } else {
        cout << "Error: Unable to open file for registration." << endl;
    }
}

void Login(){
	
	string username;
	string password;
		
	cout << "Welcome To Login Page:" << endl;
	
	cout << "Enter Your Username: ";
	cin >> username;
	
	cout << endl;
	
	cout << "Enter Your Password: ";
	password = hide_password();
	
	ifstream infile("database.txt");
	
	string storedusername;
	string storedpassword;
	
	bool flag = false;
	
	if (infile.is_open()) {
		flag = true;
        while (infile >> storedusername >> storedpassword) {
            if (storedusername == username && storedpassword == password) {
                cout << "Login successful!" << endl << endl;
                flag = false;
                infile.close();
            }
        }
    }else if(flag){
        infile.close();
        cout << "Invalid username or password!" << endl;
        
    } else {
        cout << "Error: Unable to open file for login." << endl;
    }
}	

int main(){
	
	int choice = 0;
	do{
		do{
		cout << "Press 1. for Registration: " << endl << "Press 2. for Login: "<< endl << "Press 3. to Exit: " << endl;
		cin >> choice;
		
		if(choice !=1 && choice != 2 && choice != 3){
			cout << "Invalid choice!" << endl;
		}
		
		}while(choice != 1 && choice !=2 && choice != 3);
		cout << endl;
		switch(choice){
			case 1:
				Register();
				break;
			case 2:
				Login();
				break;
			case 3:
				break;
		}
		cout << endl << endl;
	}while(choice != 3);
	
	return 0;
}
