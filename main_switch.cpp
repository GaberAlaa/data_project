#include <iostream>
#include <limits>
#include "employee.h"
#include "linked_list_s.h"
using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void searchEmployee(linked_list& emp_list) {
    int searchChoice;
    cout << "\nSearch by:";
    cout << "\n1. ID";
    cout << "\n2. Name";
    cout << "\nEnter your choice: ";
    
    while (!(cin >> searchChoice) || (searchChoice != 1 && searchChoice != 2)) {
        cout << "Invalid choice. Please enter 1 or 2: ";
        clearInput();
    }
    clearInput();

    if (searchChoice == 1) {
        int id;
        cout << "Enter employee ID: ";
        while (!(cin >> id)) {
            cout << "Invalid ID. Please enter a number: ";
            clearInput();
        }
        clearInput();
        
        node* found = emp_list.search_by_id(id);
        if (found) {
            cout << "\nEmployee found:" << endl;
            cout << "ID: " << found->data.id << ", Name: " << found->data.name 
                 << ", Role: " << found->data.role << endl;
            
            // Additional operations on found employee
            int opChoice;
            cout << "\nOperations:";
            cout << "\n1. Promote/Demote";
            cout << "\n2. View Role History";
            cout << "\n3. Back to main menu";
            cout << "\nEnter your choice: ";
            
            while (!(cin >> opChoice) || opChoice < 1 || opChoice > 3) {
                cout << "Invalid choice. Please enter a number between 1 and 3: ";
                clearInput();
            }
            clearInput();
            
            if (opChoice == 1) {
                string newRole;
                cout << "Enter new role: ";
                getline(cin, newRole);
                emp_list.change_role(id, newRole);
                cout << "Role updated successfully!" << endl;
            } else if (opChoice == 2) {
                found->data.display_role_history();
            }
        } else {
            cout << "Employee not found!" << endl;
        }
    } else {
        string name;
        cout << "Enter employee name: ";
        getline(cin, name);
        
        node* found = emp_list.search_by_name(name);
        if (found) {
            cout << "\nEmployee found:" << endl;
            cout << "ID: " << found->data.id << ", Name: " << found->data.name 
                 << ", Role: " << found->data.role << endl;
            
            // Additional operations on found employee
            int opChoice;
            cout << "\nOperations:";
            cout << "\n1. Promote/Demote";
            cout << "\n2. View Role History";
            cout << "\n3. Back to main menu";
            cout << "\nEnter your choice: ";
            
            while (!(cin >> opChoice) || opChoice < 1 || opChoice > 3) {
                cout << "Invalid choice. Please enter a number between 1 and 3: ";
                clearInput();
            }
            clearInput();
            
            if (opChoice == 1) {
                string newRole;
                cout << "Enter new role: ";
                getline(cin, newRole);
                emp_list.change_role(found->data.id, newRole);
                cout << "Role updated successfully!" << endl;
            } else if (opChoice == 2) {
                found->data.display_role_history();
            }
        } else {
            cout << "Employee not found!" << endl;
        }
    }
}

void deleteEmployee(linked_list& emp_list) {
    int deleteChoice;
    cout << "\nDelete by:";
    cout << "\n1. ID";
    cout << "\n2. Name";
    cout << "\nEnter your choice: ";
    
    while (!(cin >> deleteChoice) || (deleteChoice != 1 && deleteChoice != 2)) {
        cout << "Invalid choice. Please enter 1 or 2: ";
        clearInput();
    }
    clearInput();

    if (deleteChoice == 1) {
        int id;
        cout << "Enter employee ID to delete: ";
        while (!(cin >> id)) {
            cout << "Invalid ID. Please enter a number: ";
            clearInput();
        }
        clearInput();
        emp_list.remove_employee(id);
    } else {
        string name;
        cout << "Enter employee name to delete: ";
        getline(cin, name);
        
        node* found = emp_list.search_by_name(name);
        if (found) {
            emp_list.remove_employee(found->data.id);
        } else {
            cout << "Employee not found!" << endl;
        }
    }
}

void displayEmployees(linked_list& emp_list) {
    int displayChoice;
    cout << "\nDisplay:";
    cout << "\n1. All employees";
    cout << "\n2. Specific employee";
    cout << "\nEnter your choice: ";
    
    while (!(cin >> displayChoice) || (displayChoice != 1 && displayChoice != 2)) {
        cout << "Invalid choice. Please enter 1 or 2: ";
        clearInput();
    }
    clearInput();

    if (displayChoice == 1) {
        emp_list.display_all();
    } else {
        int searchChoice;
        cout << "\nSearch by:";
        cout << "\n1. ID";
        cout << "\n2. Name";
        cout << "\nEnter your choice: ";
        
        while (!(cin >> searchChoice) || (searchChoice != 1 && searchChoice != 2)) {
            cout << "Invalid choice. Please enter 1 or 2: ";
            clearInput();
        }
        clearInput();

        if (searchChoice == 1) {
            int id;
            cout << "Enter employee ID: ";
            while (!(cin >> id)) {
                cout << "Invalid ID. Please enter a number: ";
                clearInput();
            }
            clearInput();
            
            node* found = emp_list.search_by_id(id);
            if (found) {
                cout << "\nEmployee Details:" << endl;
                cout << "ID: " << found->data.id << ", Name: " << found->data.name 
                     << ", Role: " << found->data.role << endl;
            } else {
                cout << "Employee not found!" << endl;
            }
        } else {
            string name;
            cout << "Enter employee name: ";
            getline(cin, name);
            
            node* found = emp_list.search_by_name(name);
            if (found) {
                cout << "\nEmployee Details:" << endl;
                cout << "ID: " << found->data.id << ", Name: " << found->data.name 
                     << ", Role: " << found->data.role << endl;
            } else {
                cout << "Employee not found!" << endl;
            }
        }
    }
}

int main() {
    linked_list emp_list;
    int choice;
    
    // Add some sample employees
    emp_list.add_employee("Bob", "Manager");
    emp_list.add_employee("Charlie", "Designer");
    emp_list.add_employee("David", "Engineer");
    emp_list.add_employee("Eve", "QA Tester");
    emp_list.add_employee("Frank", "DevOps");
    emp_list.add_employee("Grace", "Product Owner");
    emp_list.add_employee("Henry", "Scrum Master");
    emp_list.add_employee("Ivy", "Frontend Dev");
    emp_list.add_employee("Jack", "Backend Dev");
    emp_list.add_employee("Katie", "Data Scientist");
    emp_list.add_employee("Liam", "UX Designer");
    emp_list.add_employee("Mia", "System Admin");
    emp_list.add_employee("Noah", "Security Analyst");
    emp_list.add_employee("Olivia", "Tech Lead");
    emp_list.add_employee("Paul", "Intern");

    do {
        cout << "\n===== Employee Management System =====" << endl;
        cout << "1. Add New Employee" << endl;
        cout << "2. Manage Current Employees" << endl;
        cout << "3. Display Employee(s)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Invalid choice. Please enter a number between 1 and 4: ";
            clearInput();
        }
        clearInput();

        switch (choice) {
            case 1: {
                string name, role;
                cout << "\nEnter employee name: ";
                getline(cin, name);
                cout << "Enter employee role: ";
                getline(cin, role);
                emp_list.add_employee(name, role);
                break;
            }
            case 2: {
                int manageChoice;
                cout << "\n1. Search Employee" << endl;
                cout << "2. Delete Employee" << endl;
                cout << "3. Back to main menu" << endl;
                cout << "Enter your choice: ";
                
                while (!(cin >> manageChoice) || manageChoice < 1 || manageChoice > 3) {
                    cout << "Invalid choice. Please enter a number between 1 and 3: ";
                    clearInput();
                }
                clearInput();
                
                if (manageChoice == 1) {
                    searchEmployee(emp_list);
                } else if (manageChoice == 2) {
                    deleteEmployee(emp_list);
                }
                break;
            }
            case 3: {
                displayEmployees(emp_list);
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;
        }
    } while (choice != 4);
    
    return 0;
}