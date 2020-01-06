#include "../include/account.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <random>
using namespace std;

int main(int argc, char** argv){
    ifstream infile;
    vector<Account> Bank;
    vector<Account>::iterator it;

    infile.open(argv[1]);

    if(!infile.is_open()){
        cout << "accounts.txt not found!" << endl;
        exit(EXIT_FAILURE);
    }

    int a, d;
    string b, c;

    while(infile >> a >> b >> c >> d){
        Account x(a, b, c, d);
        Bank.push_back(x);
    }

    infile.close();

    start:
        int choice = 0;

        system("clear");
        cout << "Welcome to Wheel's Bank!" << endl;
        cout << "1. Add new account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Admin mode" << endl;
        cout << "4. Quit" << endl;
        cin >> choice;
        cout << endl;

        string name, password;

        if(choice == 1){
            cout << "Please provide a username:" << endl;
            cin >> name;
            cout << endl;
            cout << "Please provide a secure password:" << endl;
            cin >> password;
            cout << endl;

            Account a(name, password);
            Bank.push_back(a);

            cout << "Your account is successfully created!" << endl;
            cout << a << endl;
            cout << "Returning to main menu!" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            goto start;
        }

        else if(choice == 2){
            cout << "Enter username:" << endl;
            cin >> name;
            cout << endl;

            int index = 0;
            bool found = 0;

            for(int i=0; i<Bank.size(); i++){
                if(Bank[i].get_name() == name){
                    found = 1;
                    index = i;
                    break;
                }
            }

            if(found){
                cout << "Enter password:" << endl;
                cin >> password;
                cout << endl;

                if(Bank[index].check_password(password)){
                    cout << "Successful login!" << endl << endl;
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    system("clear");

                    cout << Bank[index] << endl;

                    cout << "Choose an action to perform:" << endl;
                    cout << "1. Withdraw money" << endl;
                    cout << "2. Deposit money" << endl;
                    cout << "3. Change password" << endl;
                    cout << "4. Log off" << endl;
                    cin >> choice;
                    cout << endl;

                    int money;

                    if(choice == 1){
                        cout << "How much would you like to withdraw?" << endl;
                        cin >> money;
                        cout << endl;

                        if(money > Bank[index].get_balance()){
                            cout << "You do not have enough money!" << endl;
                            cout << "Logging off..." << endl;
                            this_thread::sleep_for(chrono::milliseconds(1500));
                            goto start;
                        }

                        Bank[index].withdraw(money);

                        cout << "$" << money << " was successfully withdrawn!" << endl << endl;
                        cout << "Account details:" << endl;
                        cout << Bank[index] << endl << endl;
                        cout << "Logging off..." << endl;
                        this_thread::sleep_for(chrono::milliseconds(1500));
                        goto start;

                    }

                    else if(choice == 2){
                        cout << "How much would you like to deposit?" << endl;
                        cin >> money;
                        cout << endl;

                        Bank[index].deposit(money);

                        cout << "$" << money << " was successfully deposited!" << endl << endl;
                        cout << "Account details:" << endl;
                        cout << Bank[index] << endl << endl;
                        cout << "Logging off..." << endl;
                        this_thread::sleep_for(chrono::milliseconds(1500));
                        goto start;
                    }

                    else if(choice == 3){
                        cout << "Enter new password:" << endl;
                        cin >> password;
                        cout << endl;

                        Bank[index].set_password(password);

                        cout << "Password successfully changed!" << endl << endl;
                        cout << "Logging off..." << endl;
                        this_thread::sleep_for(chrono::milliseconds(1500));
                        goto start;
                    }

                    else if(choice == 4){
                        cout << "Returning to main menu!" << endl;
                        this_thread::sleep_for(chrono::milliseconds(1500));
                        goto start;
                    }

                    else{
                        cout << "Invalid choice! Returning to main menu!" << endl;
                        this_thread::sleep_for(chrono::milliseconds(1500));
                        goto start;
                    }
                }

                else{
                    cout << "Wrong password! Returning to main menu!" << endl;
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    goto start;
                }
            }

            else{
                cout << "Username not found! Returning to main menu!" << endl;
                this_thread::sleep_for(chrono::milliseconds(1500));
                goto start;
            }
        }

        else if(choice == 3){
            int back;

            cout << "Enter admin password" << endl;
            cin >> password;
            cout << endl;

            if(password == "admin"){
                for(int i=0; i<Bank.size(); i++){
                    cout << "Account no.: " << Bank[i].get_accno() << endl << Bank[i] << endl;
                }

                cout << "Press 1 to return to main menu" << endl;
                cin >> back;
                cout << endl;

                if(back == 1){
                    cout << "Returning to main menu!" << endl;
                    this_thread::sleep_for(chrono::milliseconds(1500));
                    goto start;
                }
            }

            else{
                cout << "You do not have admin access! Returning to main menu!" << endl;
                this_thread::sleep_for(chrono::milliseconds(1500));
                goto start;
            }
        }

        else if(choice == 4){
            ofstream outfile;

            outfile.open(argv[1]);

            if(!outfile.is_open()){
                cout << "accounts.txt not found!" << endl;
                exit(EXIT_FAILURE);
            }

            for(int i=0; i<Bank.size(); i++){
                outfile << Bank[i].get_accno() << " " << Bank[i].get_password() << " " << Bank[i].get_name() << " " << Bank[i].get_balance() << endl;
            }

            outfile.close();

            cout << "Data successfully saved!" << endl;
            this_thread::sleep_for(chrono::milliseconds(1500));
            system("clear");
            exit(EXIT_SUCCESS);
        }

        else{
            cout << "Invalid selection! Please try again!" << endl << endl;
            this_thread::sleep_for(chrono::milliseconds(1500));
            goto start;
        }

    return 0;
}