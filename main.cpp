#include <iostream>
#include "employee.h"
#include "linked_list_s.h"
#include "switch_methods.h"
using namespace std;



int main() {
     linked_list emp_list;

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

     linked_list_swtich(emp_list);
     return 0;
}