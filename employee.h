#ifndef EMPLOYEE_H  
#define EMPLOYEE_H
#include<iostream>
#include<string>
using namespace std;

class employee{
    public:
    string name;
    string role;
    int id;

    string role_stack[5];
    int stack_top=-1;

    static int emp_counter;

    employee(string name ,string role):
    name(name),role(role),id(emp_counter)
    {
        emp_counter++;
    }

    //stack methods
    void push(string old_role){
        if(stack_top<4){
            stack_top++;
            role_stack[stack_top] = old_role;
        }
    }
    void pop(){
        if (stack_top>=0){
            stack_top--;
        }else{cout<<"stack empty";}
    }
    string peek(){
        if (stack_top==-1){
            return "stack is empty";
        }
        return role_stack[stack_top];
    }
    void display_role_history(){
        cout<< "current role:"<<role<<endl;
        cout<<"history:"<<endl;
        for (int i=stack_top;i>=0;i--){
            cout <<"--" <<role_stack[i]<<endl;
        }
    }

    //employee methods
    void change_role(string new_role){
        if (new_role!=role){
        push(role);
        role = new_role;
    }}

    void demote(){
        if(stack_top>=0){
        role = peek();
        pop();
    }else {cout<<"cant demote stack is empty"<<endl;}
    }

    void display_num_of_emp(){
        cout<< emp_counter<<endl;
    }
    void display_emp_info(){
        cout<< "employe:"<<name<<"  id:"<< id<<endl;
        display_role_history();
    }
};
int employee::emp_counter=0;
#endif