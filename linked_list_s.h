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
    // Constructor
    linked_list() : head(nullptr), tail(nullptr), count(0) {}

    // Destructor
    ~linked_list() {
        node* current = head;
        while (current != nullptr) {
            node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Add employee to the end of the list
    void add_employee(string name, string role) {
        // 1. Take name and role (id is auto-assigned)
        // 2. Make new employee object
        employee new_emp(name, role);
        
        // 3. Link to a new node
        node* new_node = new node(new_emp);
        
        // 4. Link node to the linked list
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
    // Search by employee ID
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

    // Search by employee name
    node* search_by_name(const string& name) {
        node* current = head;
        while (current != nullptr) {
            if (current->data.name == name) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Remove employee by ID
    bool remove_employee(int id) {
        if (head == nullptr) return false;

        // Special case: removing head
        if (head->data.id == id) {
            node* temp = head;
            head = head->next;
            if (tail == temp) tail = nullptr;
            delete temp;
            count--;
            return true;
        }

        // Find the node to remove
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

    // Display all employees
    void display_all() const {
        node* current = head;
        while (current != nullptr) {
            cout << "ID: " << current->data.id 
                 << ", Name: " << current->data.name
                 << ", Role: " << current->data.role << endl;
            current = current->next;
        }
    }

    // Get number of employees
    int get_count() const {
        return count;
    }
};