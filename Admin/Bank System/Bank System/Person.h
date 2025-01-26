#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
    string name;
    int id;
    string password;
public:
    Person() {
        id = 0;
        name = "";
        password = "";
    }
    Person(string name, int id, string password) {
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







