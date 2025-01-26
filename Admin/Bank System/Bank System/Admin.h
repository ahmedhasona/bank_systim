#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Employee.h"
using namespace std;
class Admin:public Employee
{
    string name;
    int id;
    string password;
public:
    Admin() {
        id = 0;
        name = "";
        password = "";
    }
	Admin(string name, int id, string password, double salary) :Employee(name, id, password, salary) {
        this->name = name;
        this->id = id;
        this->password = password;
        if (salary >= 5000) {
            this->salary = salary;
        }
        else {
            cout << "Error the minimum salary must be 5000. \n";
            this->salary = 5000;
        }
	}
    void setName(string name) {
        
            bool isValid = true;
            for (char ch : name) {
                if (!isalpha(ch) && ch != ' ') {
                    isValid = false;
                    break;
                }
            }
            if (isValid && name.length() >= 5 && name.length() <= 20) {
                this-> name = name;
            }
            else {
                cout << "Error: Name must be between 5 and 20 characters.\n";
            }
        }
    void setPassword(string newPassword) {
        if (newPassword.length() >= 8 && newPassword.length() <= 20) {
            password = newPassword;
        }
        else {
            cout << "Error: Password must be between 8 and 20 characters.\n";
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
        Person::displayInfo();
        cout << "Salary = " << salary << endl;
        cout << "========================================================\n";
    }
};

