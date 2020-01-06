#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <string>
using namespace std;

class Account{
    public:
        Account(){}
        Account(string m, string n);
        Account(int a, string b, string c, int d);

        int get_accno() const{return accno;}
        string get_password() const{return password;}
        void set_password(string n){password = n;}
        string get_name() const{return name;}
        int get_balance() const{return balance;}
        bool check_password(string n);

        void withdraw(int x);
        void deposit(int x);

    protected:
        ostream& print(ostream& out) const;
        friend ostream& operator<<(ostream& out, const Account& a);

    private:
        int accno;
        string password;
        string name;
        int balance = 0;
};

#endif