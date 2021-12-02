/*Объявить структуру Сотрудник с различными полями.
Сделайте для нее побайтовое выравнивание с помощью
директивы pragma pack. Выделите динамически переменную
этого типа. Инициализируйте ее. Выведите ее на экран и ее
размер с помощью sizeof. Сохраните эту структуру в текстовый
файл.*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#pragma pack(push, 1)
struct Employee {
    string name;
    long id;
    unsigned short age;
    double salary;
};
#pragma pack(pop)

void print_Empoyee(string name,long id, short age, double salary)
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Age: " << age << endl;
    cout << "Salary: " << salary << endl;
    cout << sizeof(Employee);
    ofstream my_struct("Struct.txt");
    my_struct << "Name: " << name << endl;
    my_struct << "ID: " << id << endl;
    my_struct << "Age: " << age << endl;
    my_struct << "Salary: " << salary << endl;
    my_struct.close();
}

int main()
{
    Employee* nEmployee = new Employee;
    nEmployee->name = "Ivan";
    nEmployee->id = 15000234;
    nEmployee->age = 23;
    nEmployee->salary = 230'000;
    print_Empoyee(nEmployee->name,nEmployee->id, nEmployee->age, nEmployee->salary);
    delete nEmployee;
    return 0;
}

