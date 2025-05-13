#include<iostream>
#include "employee.h"
using namespace std;
class node {
    public:
    employee data ;
    node* next;
    node(employee& emp):data(emp),next(nullptr){}  
};

class linked_list{
private:
    node* head;
    node* tail;
    int count;

public:

    linked_list() : head(nullptr), tail(nullptr), count(0) {}


    void add_employee(string name, string role) {
        employee new_emp(name, role);
        node* new_node = new node(new_emp);

        if (head == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        count++;
        
        cout << "Added employee: " << name 
             << " (ID: " << new_emp.id 
             << ", Role: " << role << ")\n";
    }

    node* search_by_id(int id) {
        node* current = head;
        while (current != nullptr) {
            if (current->data.id == id) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }


    node* search_by_name(string& name) {
        node* current = head;
        while (current != nullptr) {
            if (current->data.name == name) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }


    int remove_employee(int id) {
        if (head == nullptr){
            cout<<"id is wrong pls try agian";
            return 0 ;
        }


        if (head->data.id == id) {
            node* temp = head;
            head = head->next;
            if (tail == temp) tail = nullptr;
            delete temp;
            count--;
            return 0;
        }


        node* current = head;
        while (current->next != nullptr && current->next->data.id != id) {
            current = current->next;
        }

        if (current->next != nullptr) {
            node* temp = current->next;
            current->next = temp->next;
            if (tail == temp) tail = current;
            delete temp;
            count--;
            return true;
        }

        return false;
    }
    

    int remove_employee_by_name(string& name) {
        if (head == nullptr) {
            cout << "Employee with name " << name << " not found." << endl;
            return 0;
        }

        // Handle case when the head node contains the employee to be removed
        if (head->data.name == name) {
            node* temp = head;
            head = head->next;
            if (tail == temp) tail = nullptr;  // If only one node existed
            cout << "Removed employee: " << temp->data.name << " (ID: " << temp->data.id << ")" << endl;
            delete temp;
            count--;
            return 1;
        }

        // Search for the node to be removed
        node* current = head;
        while (current->next != nullptr && current->next->data.name != name) {
            current = current->next;
        }

        // If employee found, remove the node
        if (current->next != nullptr) {
            node* temp = current->next;
            current->next = temp->next;
            if (tail == temp) tail = current;  // If removing the last node
            cout << "Removed employee: " << temp->data.name << " (ID: " << temp->data.id << ")" << endl;
            delete temp;
            count--;
            return 1;
        }

        cout << "Employee with name " << name << " not found." << endl;
        return 0;
    }

    void change_role(int id,string new_role ){
        node* current =search_by_id(id);
        current->data.change_role(new_role);
    }

    void demote(int id ){
        node* current =search_by_id(id);
        current->data.demote();
    }

    void display_role_history(int id){
        node* current=search_by_id(id);
        current->data.display_role_history();
    }

    void display_emp_info(int id){
    node* current=search_by_id(id);
    current->data.display_emp_info();
    }

    void display_all() const {
        node* current = head;
        cout<<"all employees:"<<endl;
        while (current != nullptr) {
            cout << "ID: " << current->data.id 
                 << ", Name: " << current->data.name
                 << ", Role: " << current->data.role << endl;
            current = current->next;
        }
    }
    int get_count() const {
        return count;
    }
};