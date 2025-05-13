#include <iostream>
#include "linked_list.h"
#include "menu.h"
#include "employee.h"
using namespace std;


int main() {
    linked_list list;
    
    // sample employees
    std::cout << "Adding sample employees...\n";
    list.insert_employee("John", "Manager");
    list.insert_employee("Jane", "Developer");
    list.insert_employee("Bob", "Designer");
        
    Menu menu(list);
    menu.run();
    

    employee emp("gaber", "manger");
    cout<<emp.name<<endl;
    cout<<emp.id<<endl;
    cout<<emp.emp_counter<<endl;

    
    cout << "hello world"<<"\n";
    return 0;
    }