#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <limits>
#include "linked_list.h"

class Menu {
private:
    linked_list& empList;
    
    void displayMenu() const {
        std::cout << "\nEmployee Management System\n";
        std::cout << "1. Add Employee\n";
        std::cout << "2. Display All Employees\n";
        std::cout << "3. Delete Employee by ID\n";
        std::cout << "4. Delete Employee by Name\n";
        std::cout << "5. Search Employee by ID\n";
        std::cout << "6. Search Employee by Name\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
    }
    
    void addEmployee() {
        std::string name, role;
        
        std::cout << "Enter Employee Name: ";
        std::getline(std::cin, name);
        
        std::cout << "Enter Employee Role: ";
        std::getline(std::cin, role);
        
        empList.insert_employee(name, role);
        std::cout << "Employee added successfully with auto-generated ID!\n";
    }
    
    void deleteById() {
        int id;
        std::cout << "Enter Employee ID to delete: ";
        std::cin >> id;
        empList.delete_employee(id);
        std::cout << "Employee deleted successfully!\n";
    }
    
    void deleteByName() {
        std::string name;
        std::cout << "Enter Employee Name to delete: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, name);
        empList.delete_employee_by_name(name);
        std::cout << "Employee deleted successfully!\n";
    }
    
    void searchById() const {
        int id;
        std::cout << "Enter Employee ID to search: ";
        std::cin >> id;
        try {
            employee* emp = empList.search_employee(id);
            std::cout << "Employee found: " << emp->id << " " 
                     << emp->name << " " << emp->role << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    
    void searchByName() const {
        std::string name;
        std::cout << "Enter Employee Name to search: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, name);
        try {
            employee* emp = empList.search_employee_by_name(name);
            std::cout << "Employee found: " << emp->id << " " 
                     << emp->name << " " << emp->role << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

public:
    Menu(linked_list& list) : empList(list) {}
    
    void run() {
        int choice;
        
        do {
            displayMenu();
            
            // Clear any previous errors and check for valid input
            std::cin.clear();
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input! Please enter a number.\n";
                continue;
            }
            
            // Clear the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            switch(choice) {
                case 1:
                    addEmployee();
                    break;
                case 2:
                    std::cout << "\nAll Employees:\n";
                    empList.display_employee();
                    break;
                case 3:
                    deleteById();
                    break;
                case 4:
                    deleteByName();
                    break;
                case 5:
                    searchById();
                    break;
                case 6:
                    searchByName();
                    break;
                case 7:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice! Please enter a number between 1 and 7.\n";
                    continue; // Skip the pause for invalid input
            }
            
            if (choice != 7) {  // Don't pause if user chose to exit
                std::cout << "\nPress Enter to continue...";
                std::cin.get();
            }
            
        } while (choice != 7);
    }
};

#endif // MENU_H
