/******************************** Lab Assignment*******************************************
Write a program using struct for the following task:
1.	Student – name
2.	Student – Id
3.	DoB
4.	GPA
5.	Semester 

You are require to implement the following operation on the above student information: 
(your’ program should store at-least 10 or more student’s information) 

1.	Make a list of student with GPA less than 3.00
2.	Make a list of student with GPA more than 3
3.	Search for a particular student
4.	write a function which calculate student age
*/
#include <iostream>
#include <string>
using namespace std;
struct Student
{
private:
    string name;
    int id;
    int day, month, year; // datee of birth
    float GPA;
    int semester;

public:
    void getData();
    void GPAless3(Student std[], int size);
    void GPAgreat3(Student std[], int size);
    void search(Student[], int size);
    void CalculateAge(Student[], int size);
};
void Student::getData()
{
    static int count = 1;
    cout << endl
         << "Enter Student NO: " << count << " Details:" << endl;
    cout << "Enter Name: " << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Enter ID (without Dasehes): " << endl;
    cin >> id;
    cout << "Enter Date of birth (dd-mm-yy)" << endl;
    cout << "Day:" << endl;
    cin >> day;
    cout << "MOnth: " << endl;
    cin >> month;
    cout << "Year: " << endl;
    cin >> year;

    cout << "Enter GPA:" << endl;
    cin >> GPA;
    cout << "Enter Semester(1,2 etc): " << endl;
    cin >> semester;
    count++;
}
void Student::GPAless3(Student std[], int size)
{
    system("CLS");
    cout << "Students with GPA Less than 3" << endl;
    for (int i = 0; i < size; i++)
    {
        if (std[i].GPA < 3.0)
        {
            cout << "Name: " << std[i].name;
            cout << "  ||  ";
            cout << "GPA: " << std[i].GPA << endl;
        }
    }
}
void Student::GPAgreat3(Student std[], int size)
{
    system("CLS");
    cout << "Students with GPA Greater than 3" << endl;
    for (int i = 0; i < size; i++)
    {
        if (std[i].GPA > 3.0)
        {
            cout << "Name: " << std[i].name;
            cout << "  ||  ";
            cout << "GPA: " << std[i].GPA << endl;
        }
    }
}
void Student::search(Student std[], int size)
{
    int s_id;
    bool found = false;
    cout << endl
         << "Enter the Id of the Student you want to search:" << endl;
    cin >> s_id;
    for (int i = 0; i < size; i++)
    {
        if (std[i].id == s_id)
        {
            system("CLS");
            cout << "Student is Found!" << endl;
            cout << "Name: " << std[i].name << endl;
            cout << "ID: " << std[i].id << endl;
            cout << "DOB: " << std[i].day << "/" << std[i].month << "/" << std[i].year << endl;
            cout << "Semester: " << std[i].semester << endl;
            cout << "GPA: " << std[i].GPA << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << endl
             << "Student NOt found" << endl;
    }
}
void Student::CalculateAge(Student std[], int size)
{
    system("CLS");
    int s_id;
    cout << "Enter the ID of the Student of which you want to calculate Age: " << endl;
    cin >> s_id;
    for (int i = 0; i < size; i++)
    {
        if (s_id == std[i].id)
        {
            int c_year, age;
            cout << "Enter Current Year: " << endl;
            cin >> c_year;
            age = c_year - std[i].year;
            cout << "Age = " << age << endl;
            break;
        }
        cout << "Student ID not Found" << endl;
    }
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int length = 2; // Set the number of students
    Student s[length];

    // Input data for all students
    cout << "Enter details for " << length << " students.\n";
    for (int i = 0; i < length; i++)
    {
        s[i].getData();
    }
    // Menu-driven program
    int choice;
    do
    {
        system("CLS"); // Clear the screen for a clean menu display
        cout << "1. List Students with GPA Less than 3.00\n";
        cout << "2. List Students with GPA More than 3.00\n";
        cout << "3. Search for a Student by ID\n";
        cout << "4. Calculate a Student's Age\n";
        cout << "5. Exit\n";
        cout << "**********************************************************\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s[0].GPAless3(s, length); // Function call for GPA < 3
            system("PAUSE");
            break;
        case 2:
            s[0].GPAgreat3(s, length); // Function call for GPA > 3
            system("PAUSE");
            break;
        case 3:
            s[0].search(s, length); // Function call to search for a student
            system("PAUSE");
            break;
        case 4:
            s[0].CalculateAge(s, length); // Function call to calculate age
            system("PAUSE");
            break;
        case 5:
            cout << "Exiting the program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            system("PAUSE");
        }
    } while (choice != 5); // Exit when the user chooses option 5

    return 0;
}
