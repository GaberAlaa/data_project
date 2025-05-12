#include <iostream>
#include "linked_list.h"
#include "menu.h"

int main() {
    linked_list list;
    
    // sample employees
    std::cout << "Adding sample employees...\n";
    list.insert_employee("John", "Manager");
    list.insert_employee("Jane", "Developer");
    list.insert_employee("Bob", "Designer"
        
    Menu menu(list);
    menu.run();
    
    return 0;
}