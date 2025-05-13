#include<iostream>
using namespace std;

class employee{
    public:
    string name;
    string role;
    int id;
    string arr[5];
    string *ptr=arr;
    static int emp_counter;

    employee(string name ,string role){
        this->name = name;
        this->role = role;
        emp_counter++;
        id = emp_counter;


    }

};
int employee::emp_counter=0;