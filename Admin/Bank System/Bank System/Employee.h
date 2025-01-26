#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
class Employee:public Person
{
protected:
    double salary;
public:
    Employee() : salary(5000) {
    }
    Employee(string name, int id, string password, double salary) :Person(name, id, password)
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
        Person::displayInfo();
        cout << "Salary = " << salary << endl;
        cout << "========================================================\n";
    }
};


