#include <iostream>
#include "employee.h"
using namespace std;


int main() {
    
    employee emp("gaber", "manger");
    cout<<emp.name<<endl;
    cout<<emp.id<<endl;
    cout<<emp.emp_counter<<endl;
    emp.change_role("branch manger");
    emp.change_role("CEO");
    emp.change_role("CEO");
    emp.change_role("CEO");
    emp.display_emp_info();

    
    cout << "hello world"<<"\n";
    return 0;
    }