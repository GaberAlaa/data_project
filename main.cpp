#include <iostream>
#include <limits>
#include "linked_list.h"
using namespace std;

void displayMenu() {
    cout << "\nEmployee Management System\n";
    cout << "1. Add Employee\n";
    cout << "2. Display All Employees\n";
    cout << "3. Delete Employee by ID\n";
    cout << "4. Delete Employee by Name\n";
    cout << "5. Search Employee by ID\n";
    cout << "6. Search Employee by Name\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

void addEmployee(linked_list& list) {
    int id;
    string name, role;
    
    cout << "Enter Employee ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Enter Employee Name: ";
    getline(cin, name);
    
    cout << "Enter Employee Role: ";
    getline(cin, role);
    
    list.insert_employee(id, name, role);
    cout << "Employee added successfully!\n";
}

void deleteById(linked_list& list) {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;
    list.delete_employee(id);
    cout << "Employee deleted successfully!\n";
}

void deleteByName(linked_list& list) {
    string name;
    cout << "Enter Employee Name to delete: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    list.delete_employee_by_name(name);
    cout << "Employee deleted successfully!\n";
}

void searchById(linked_list& list) {
    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;
    try {
        employee* emp = list.search_employee(id);
        cout << "Employee found: " << emp->id << " " 
             << emp->name << " " << emp->role << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void searchByName(linked_list& list) {
    string name;
    cout << "Enter Employee Name to search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    try {
        employee* emp = list.search_employee_by_name(name);
        cout << "Employee found: " << emp->id << " " 
             << emp->name << " " << emp->role << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

int main() {
    linked_list list;
    int choice;
    
    // Add some sample data
    list.insert_employee(1, "John", "Manager");
    list.insert_employee(2, "Jane", "Developer");
    list.insert_employee(3, "Bob", "Designer");
    
    do {
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                addEmployee(list);
                break;
            case 2:
                cout << "\nAll Employees:\n";
                list.display_employee();
                break;
            case 3:
                deleteById(list);
                break;
            case 4:
                deleteByName(list);
                break;
            case 5:
                searchById(list);
                break;
            case 6:
                searchByName(list);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        
        // Clear input buffer and wait for user to press Enter
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        
    } while (choice != 7);
    
    return 0;
}