// Bank Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class person {
protected:
    string name;
    int id;
    string password;
public:
    person() {
        id = 0;
        name = "";
        password = "";

    }
    person(string name, int id, string password) {
        this->name = name;
        this->id = id;
        this->password = password;


    }
    void setname(string name) {
        bool isValid = true;
        for (char ch : name) {
            if (!isalpha(ch) && ch != ' ') {
                isValid = false;
                break;
            }
        }
        if (isValid && name.length() >= 5 && name.length() <= 20) {
            this->name = name;
        }
        else {
            cout << "Error: Name must be between 5 and 20 characters.\n";
        }

    }

    void setid(int id) {

        this->id = id;

    }

    void setPassword(string newPassword) {
        if (newPassword.length() >= 8 && newPassword.length() <= 20) {
            password = newPassword;
        }
        else {
            cout << "Error: Password must be between 8 and 20 characters.\n";
        }
    }

    string getname() {
        return this->name;
    }


    int getid() {
        return this->id;
    }

    string getpassword() {
        return this->password;
    }






    void displayInfo() {
        cout << "name = " << name << endl;
        cout << "id = " << id << endl;
        cout << "password  = " << password << endl;




    }


};


class client : public person {

private:
    double balance;
public:
    client() {
        this->balance = 0;

    }
    client(string name, int id, string password, double balance) :person(name, id, password) {

        this->balance = balance;


    }
    void setbalance(double balance) {
        this->balance = balance;

    }
    double getbalance() {
        return balance;
    }
    void minbalance(double balance) {
        if (balance >= 1500) {
            cout << "ok" << endl;
        }
        else
            cout << "min balance is 1500" << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << balance << endl;;
    }


    void withdrow(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << balance << endl;
        }
        else
            cout << "The balance is not enough" << endl;
    }
    void transferto(double amount, client& b) {
        if (balance >= amount) {


            b.deposit(amount);
            balance -= amount;
            cout << balance << endl;
        }
        else
            cout << "The balance is not enough to transfer" << endl;
    }
    void checkBalance() {
        cout << "balance =  " << balance << endl;

    }


    void displayInfo() {
        person::displayInfo();
        cout << "balance   =" << balance << endl << "========================================================\n";




    }



};
class Employee : public person {
private:
    double salary;
public:
    Employee() : salary(5000) {
    }
    Employee(string name, int id, string password, double salary) :person(name, id, password)
    {
        if (salary >= 5000) {
            this->salary = salary;
        }
        else {
            cout << "Error the minimum salary must be 5000. \n";
            this->salary = 5000;
        }
    }
    void setSalary(double newSlaray) {
        if (newSlaray >= 5000) {
            salary = newSlaray;
        }
        else {
            cout << "Error the minimum salary must be 5000. \n";

        }
    }
    double getSalary() {
        return salary;
    }
    void displayInfo() {
        person::displayInfo();
        cout << "Salary = " << salary << endl;
        cout << "========================================================\n";
    }
};




int main()
{
    client a("omar", 3223, "as1234", 900), b("ahmed", 33100, "0900ah", 500);
    b.displayInfo();
    a.displayInfo();

    a.transferto(500, b);
    b.displayInfo();
    a.displayInfo();
    Employee e("Aya", 23016, "Aya@pass", 7000);
    cout << "Display information of employee\n";
    e.setSalary(4000);
    e.setSalary(8000);
    e.displayInfo();

}
