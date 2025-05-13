#include <iostream>
#include "employee.h"
#include "linked_list_s.h"
using namespace std;



int main() {
     linked_list emp_list;

    emp_list.add_employee("Alice", "Developer");
    emp_list.add_employee("Alice", "Developer");
    emp_list.add_employee("Alice", "Developer");
    
    cout << "All Employees:\n";
    emp_list.display_all();
    
    // Search and modify
    node* found = emp_list.search_by_id(1);
    if (found) {
        found->data.change_role("Senior Developer");
        cout << "\nAfter promotion:\n";
        emp_list.display_all();
    }
    
    // Remove employee
    if (emp_list.remove_employee(2)) {
        cout << "\nAfter removal:\n";
        emp_list.display_all();
    }
    
    cout << "\nTotal employees: " << emp_list.get_count() << endl;
    
    return 0;
    }