#include <iostream>
#include "linked_list.h"


int main() {
    linked_list list;
    
    // Add sample employees
    std::cout << "Adding sample employees...\n";
    list.insert_employee("John", "Manager");
    list.insert_employee("Jane", "Developer");
    list.insert_employee("Bob", "Designer");
    list.display_employee();
    list.delete_employee(1);
    list.display_employee();
    list.delete_employee_by_name("Jane");
    list.display_employee();
    list.search_employee(2);
    list.search_employee_by_name("Bob");
    return 0;
}