#ifndef SWITCH_METHODS_H
#define SWITCH_METHODS_H
#include <iostream>
#include "employee.h"
#include "linked_list_s.h"

using namespace std;

void add_emp_switch(linked_list& emp_list){
    string role;
    string name;
    cout <<"enter emp name\n";
    cin >>name;
    cout <<"enter emp role\n";
    cin>>role;
    emp_list.add_employee(name,role);
}
void search_by_id_swtich(linked_list& emp_list){
    int id ; 
    cout <<"enter emp id\n";
    cin >>id;

    emp_list.display_emp_info_by_id(id);
}
void search_by_name_switch(linked_list& emp_list){
    string name;
    cout <<"enter emp name\n";
    cin >>name;

    emp_list.display_emp_info_by_name(name);
}
void change_role_switch(linked_list& emp_list){
    int id;
    string new_role;
    cout <<"enter emp id\n";
    cin >>id;
    cout<<"enter emp new_role\n";
    cin >> new_role;

    emp_list.change_role(id,new_role);
}
void demote_switch(linked_list& emp_list){
    int id;
    cout <<"enter emp id\n";
    cin >>id;

    emp_list.demote(id);
}

void remove_emp_switch(linked_list& emp_list){
    int id;
    cout <<"enter emp id\n";
    cin >> id;
    emp_list.remove_employee(id);
}
void display_all_emp_switch(linked_list& emp_list){
    emp_list.display_all();
}


int linked_list_swtich(linked_list& emp_list){
    int choice;
    do
    {
    cout<<endl<<"=========== employee mangment system ================"<<endl;
    cout<< "add emp:1        "<<"\t\t"<<"search by id:2"<<endl;
    cout<< "search by name:3 "<<"\t\t"<<"change role by id:4"<<endl;
    cout<< "demote by id:5   "<<"\t\t"<<"remove emp:6"<<endl;
    cout<< "display all emp:7"<<"\t\t"<<"exit:8"<<endl<<endl;
    cin>>choice;
    if (choice<0||choice>8){
        cout <<"invalid input"<<endl;
    }

    else{
    switch (choice)
    {
    case 1:
    add_emp_switch(emp_list);
        break;
    case 2:
    search_by_id_swtich(emp_list);
        break;
    case 3:
    search_by_name_switch(emp_list);
        break;
    case 4:
    change_role_switch(emp_list);
        break;
    case 5:
    demote_switch(emp_list);
        break;
    case 6:
    remove_emp_switch(emp_list);
        break;
    case 7:
    display_all_emp_switch(emp_list);
        break;
    case 8:
    return 0;
        break;
    default:
        break;
    }
    }
}while (choice != 8);

}
#endif;