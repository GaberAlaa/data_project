#include<iostream>
using namespace std;

class employee{
    public:
    string name;
    string role;
    string arr[5];
    string *ptr=arr;

    employee(string name ,string role){
        this->name = name;
        this->role = role;
    }
};