#include <iostream>
#include <string>
#include "LinkList.h"
#include "employee.h"
#include "department.h"
#include "department_runner.h"
using namespace std;

void help1();
void help2();
void EmployeeManage(Department &department);
void DepartmentManage(LinkList<Department> &departments);

string ByName = "";
double ByBudget = 0.0;
int ByEmployeesNumber = 0;
int ByEmployeeId = 0;
double BySalary = 0.0;

int main()
{
    LinkList<Department> departments;
    char choice;

    //test data
    Department new_department; //Create new department
    departments.Append(new_department);
    Employee new_employee;
    departments.CurData().add_employee(new_employee);
    //end

    while (true)
    {
        cout << "Load from the data base (Y/N)";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            //Load();
            break;
        }
        else if (choice == 'n' || choice == 'N')
            break;
    }
    DepartmentManage(departments); //main part
    while (true)
    {
        cout << "Save to the data base (Y/N)";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            Save(departments);
            break;
        }
        else if (choice == 'n' || choice == 'N')
            break;
    }
}

void help1()
{ //ABCDEFGHIGKLMNOPQRSTUVWXYZ
    system("cls");
    cout << "A - Add a new department" << endl;
    cout << "C (name) (newname) (budget) - Change department infomation" << endl;
    cout << "D (name) - Delete department" << endl;
    cout << "M (id) (from) (to) - Move employee" << endl;     //没有完成函数定义
    cout << "O - Check which department over budget" << endl; //没有函数声明与定义
    cout << "Q - Quit" << endl;
    cout << "S (method) - Sort department by certain rule" << endl; //没有声明与定义
    cout << "V (name) - View further details of department" << endl;
    cout << endl;
}

void help2()
{
    system("cls");
    cout << "A - Add new employee" << endl;
    cout << "D (identity) - Delete a specific employee" << endl;
    cout << "S (method) - Sort employee by certain rule" << endl;
    cout << "Q - Quit" << endl;
    cout << "type A see further detail or press ENTER to quit help" << endl;
    char further_command;
    further_command = getchar();
    if (further_command == 'A')
        cout << "A (id) (name) (salary) (work_hour) (position) (rate)" << endl;
    cout << endl;
}

void EmployeeManage(Department &department)
{
    while (true)
    {
        system("cls");
        department.ShowEmployees();
        cout << "Command(H for help): ";
        char command;
        cin >> command;
        if ( command == 'H' || command == 'h')
            help2();
        else if ( command == 'A' || command == 'a')
        {
            int employee_identity;
            cin >> employee_identity;
            Node<Employee> *p = employee.Locate(employee_identity, true);
            if (p == NULL)
            {
                string name;
                double salary;
                int work_hour;
                string position;
                double rate;
                cin >> employee_identity>> name>> salary>> work_hour>> position>> rate;
                Employee new_employee(employee_identity, name, salary, work_hour. position, rate);
                departments.CurData().add_employee(new_employee);
            }
            else
            {
                double temp;
                cin >> temp;
                cout << "There are already duplicated employees!" << endl
                     << endl;
        }
        else if (command == 'D' || command == 'd')
        {
            int employee_identity;
            cin >> employee_identity;
            Node<Employee> *p = employee.Locate(employee_identity, true);
            if (p == NULL)
            {
                cout << "Not found!" << endl
                     << endl;
            }
            else
            {
                int method;
                cin >> method;
                switch (method)
                {
                case 1:
                    delete_employee(ByID);
                    break;
                case 2:
                    delete_employee(ByName);
                case 3:
                    delete_employee(BySalary);
                case 4:
                    delete_employee(ByWork_hour);
                case 5:
                    delete_employee(ByPosition);
                case 6:
                    delete_employee(ByRate);
                default:
                    break;
                }
            }
        }
        else if (command == 'S' || command == 's')
        {
            int method;
                cin >> method;
                switch (method)
                {
                case 1:
                    SortEmployees(ByID);
                    break;
                case 2:
                    SortEmployees(ByName);
                case 3:
                    SortEmployees(BySalary);
                case 4:
                    SortEmployees(ByWork_hour);
                case 5:
                    SortEmployees(ByPosition);
                case 6:
                    SortEmployees(ByRate);
                default:
                    break;
                }
        }
        else if (command == 'Q' || command == 'q')
            return;
        system("pause");
        system("cls");
    }
}

void DepartmentManage(LinkList<Department> &departments)
{
    while (true)
    {
        ShowDepartments(departments);
        cout << "Command(H for help): ";
        char command;
        cin >> command;
        if (command == 'H' || command == 'h')
            help1();
        else if (command == 'V' || command == 'v')
        {
            string name;
            cin >> name;
            Node<Department> *p = departments.Locate(name, true);
            if (p == NULL)
            {
                cout << "Not found!" << endl
                     << endl;
            }
            else
            {
                departments.CurData().ShowEmployees();
                EmployeeManage(departments.CurData());
            }
        }
        else if (command == 'C' || command == 'c')
        {
            string name;
            cin >> name;
            Node<Department> *p = departments.Locate(name, true);
            if (p == NULL)
            {
                string temp1;
                int temp2;
                cin >> temp1 >> temp2;
                cout << "Not found!" << endl
                     << endl;
            }
            else
            {
                string new_name;
                int new_budget;
                cin >> new_name >> new_budget;
                departments.CurData().set_department_info(new_name, new_budget);
            }
        }
        else if (command == 'A' || command == 'a')
        {
            string name;
            cin >> name;
            Node<Department> *p = departments.Locate(name, true);
            if (p == NULL)
            {
                double budget;
                cin >> budget;
                Department new_department(name, budget);
                departments.Append(new_department);
            }
            else
            {
                double temp;
                cin >> temp;
                cout << "There are already duplicated departments!" << endl
                     << endl;
            }
        }
        else if (command == 'D' || command == 'd')
        {
            string name;
            cin >> name;
            Node<Department> *p = departments.Locate(name, true);
            if (p == NULL)
            {
                cout << "Not found!" << endl
                     << endl;
            }
            else
            {
                int method;
                cin >> method;
                switch (method)
                {
                case 1:
                    delete_department(ByName);
                    break;
                case 2:
                    delete_department(ByEmployeesNumber);
                case 3:
                    delete_department(ByBudget);
                default:
                    break;
                }
            }
        }
        else if (command == 'M' || command == 'm')
        {
            string name;
            cin >> name;
            Node<Department> *p = departments.Locate(name, true);
            if (p == NULL)
            {
                cout << "Not found!" << endl
                     << endl;
            }
            else
            {
                //MoveEmployee();
            }
        }
        else if (command == 'O' || command == 'o')
        {
            //departments.CurData().CheckOverBudget();
        }
        else if (command == 'S' || command == 's')
        {
            int method;
            cin >> method;
            switch (method)
            {
            case 1:
                SortDepartment(ByName);
                break;
            case 2:
                SortDepartment(ByEmployeesNumber);
                break;
            case 3:
                SortDepartment(ByBudget);
            default:
                break;
            }
        }
        else if (command == 'Q' || command == 'q')
            return;
        system("pause");
        system("cls");
    }
}
