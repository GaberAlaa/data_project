#include<iostream>
#include "employee.h"

class node {
    public:
    employee data ;
    node* next;
    node(employee& emp):data(emp),next(nullptr){}  
};

class linked_list{

};