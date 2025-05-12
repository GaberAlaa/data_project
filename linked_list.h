#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <string> 
#include <iostream>
using namespace std ;
struct employee {
    int id ;
    string name ;
    string role ;
    employee* next ;
    employee* prev ;
};

class linked_list {
    employee* head ;
    
    ~linked_list() {
        employee* current = head ;
        while (current != NULL) {
            employee* temp = current ;
            current = current->next ;
            delete temp ;
        }
    }
public :
    linked_list() {
        head = NULL ;
    }
    
    employee* get_last_node() {
        if (head == NULL) {
            return NULL ;
        }
        employee* last = head ;
        while (last->next != NULL) {
            last = last->next ;
        }
        return last ;
    }

    void insert_employee(int id, string name, string role) {
        employee* new_employee = new employee ;
        new_employee->id = id ;
        new_employee->name = name ;
        new_employee->role = role ;
        new_employee->next = NULL ;
        
        if (head == NULL) {
            new_employee->prev = NULL ;
            head = new_employee ;
        } else {
            employee* last = get_last_node() ;
            last->next = new_employee ;
            new_employee->prev = last ;
        }
    }
    
    employee* search_employee(int id) {
        employee* current = head ;
        while (current != NULL && current->id != id) {
            current = current->next ;
        }
        if (current == NULL) {
            cout << "Employee with ID " << id << " not found\n" ;
            return NULL ;
        }
        return current ;
    }
    
    employee* search_employee_by_name(string name) {
        employee* current = head ;
        while (current != NULL && current->name != name) {
            current = current->next ;
        }
        if (current == NULL) {
            cout << "Employee with name " << name << " not found\n" ;
            return NULL ;
        }
        return current ;
    }
    
    void display_employee(){
        employee* current = head;
        while(current != NULL){
            cout<<current->id<<" "<<current->name<<" "<<current->role<<endl;
            current = current->next;
        }
    }
    
    void delete_employee(int id) {
        employee* current = head ;
        employee* prev = NULL ;
        
        if (head == NULL) {
            cout << "List is empty\n" ;
            return ;
        }
        
        // If head node needs to be deleted
        if (current != NULL && current->id == id) {
            head = current->next ;
            if (head != NULL) {
                head->prev = NULL ;
            }
            delete current ;
            return ;
        }
        
        // Find the node to be deleted
        while (current != NULL && current->id != id) {
            prev = current ;
            current = current->next ;
        }
        
        if (current == NULL) {
            cout << "Employee with ID " << id << " not found\n" ;
            return ;
        }
        
        // Update the next node's prev pointer
        if (current->next != NULL) {
            current->next->prev = prev ;
        }
        
        // Update the previous node's next pointer
        if (prev != NULL) {
            prev->next = current->next ;
        }
        
        delete current ;
    }
    
    void delete_employee_by_name(string name) {
        employee* current = head ;
        employee* prev = NULL ;
        
        if (head == NULL) {
            cout << "List is empty\n" ;
            return ;
        }
        
        // If head node needs to be deleted
        if (current != NULL && current->name == name) {
            head = current->next ;
            if (head != NULL) {
                head->prev = NULL ;
            }
            delete current ;
            return ;
        }
        
        // Find the node to be deleted
        while (current != NULL && current->name != name) {
            prev = current ;
            current = current->next ;
        }
        
        if (current == NULL) {
            cout << "Employee with name " << name << " not found\n" ;
            return ;
        }
        
        // Update the next node's prev pointer
        if (current->next != NULL) {
            current->next->prev = prev ;
        }
        
        // Update the previous node's next pointer
        if (prev != NULL) {
            prev->next = current->next ;
        }
        
        delete current ;
    }
};
#endif