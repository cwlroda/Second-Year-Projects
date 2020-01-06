#include "../include/account.hpp"
#include <iostream>

Account::Account(string m, string n){
    srand(time(0));
    accno = rand() % 100000;
    name = m;
    password = n;
}

Account::Account(int a, string b, string c, int d){
    accno = a;
    password = b;
    name = c;
    balance = d;
}

void Account::withdraw(int x){
    balance -= x;
}

void Account::deposit(int x){
    balance += x;
}

bool Account::check_password(string n){
    return (password == n);
}

ostream& Account::print(ostream& out) const{
    out << "Name: " << get_name() << endl << "Balance: $" << get_balance() << endl;

    return out;
}

ostream& operator<<(ostream& out, const Account& a){
    return a.print(out);
}