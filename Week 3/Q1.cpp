/*Q. No. 1. Write a program to store student id, name and gpa using link-list
 Store data of 10 student and apply following operations.

•	Enter data of five students in the link list
•	Display data of students in list form
•	Enter new record at the end of list
•	Search for a particular student
•	Delete a particular student from the list
*/
#include <iostream>
#include <string>
using namespace std;
struct student
{
    int id;
    string name;
    float gpa;
    student *next; // pointer to next node
};
class List
{
private:
    student *start;

public:
    List(); // default constructor
    void insertlast(int, string, float);
    void display();
    void search(int);
    void deletestd(int);
};
List::List()
{
    start = NULL;
}
void List::insertlast(int id, string name, float gpa)
{
    student *newstd = new student;
    newstd->id = id;
    newstd->name = name;
    newstd->gpa = gpa;
    newstd->next = NULL; // as it is going to inserted at last so it's next is NULL
    if (start == NULL)
    {
        start = newstd;
        cout << "New Student inserted in the LIst Scuccesfully" << endl;
        return;
    }
    student *ptr = start; // ptr pointer to traverse the list
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newstd;
    cout << "New Student inserted in the List Successfully !" << endl;
}
void List::display()
{
    if (!start)
    {
        cout << "The List is Empty" << endl;
        return;
    }
    student *ptr = start; // ptr to travesrs the list
    while (ptr != NULL)
    {
        cout << "Id: " << ptr->id << "|Name: " << ptr->name << "|GPA: " << ptr->gpa << endl;
        ptr = ptr->next;
    }
}
void List::search(int id)
{
    if (start == NULL)
    {
        cout << "List is Empty:Can Not Search" << endl;
        return;
    }
    student *ptr = start;
    bool flag = false;
    while (ptr != NULL)
    {
        if (ptr->id == id)
        {
            flag = true;
            break;
        }
        ptr = ptr->next;
    }
    if (flag == false)
        cout << "Id Not Found in The LIst" << endl;
    else
    {
        cout << "******| Id is Found in the LIst |*****" << endl;
        cout << "Id: " << ptr->id << "|Name: " << ptr->name << "|GPA: " << ptr->gpa << endl;
    }
}
void List::deletestd(int id)
{
    if (start == NULL) // Empty LIst case
    {
        cout << "List is Empty: Can't Delete Student" << endl;
        return;
    }
    // if Node to be deleted is the first Node
    if (start->id == id)
    {
        student *temp = start; // Save the current start node
        start = start->next;   // Move start to the next node
        delete temp;           // Delete the old start node
        cout << "Student with Id: " << id << " deleted Successfully" << endl;
        return;
    }

    // ONly One NOde Case
    if (start->next == NULL)
    {
        if (start->id == id)
        {
            delete start;
            start = NULL;
            cout << "Student with Id: " << id << " deleted Successfully" << endl;
            return;
        }
        cout << "Id Not Found in The List" << endl;
        return;
    }
    student *ptr = start; // points too the node that is to be deleted
    student *prev = NULL; // points to exactly one behind the Node that is to be deleted
    bool flag = false;    // to chk after complete traversal that whether item is found or not
    while (ptr != NULL)
    {
        if (ptr->id == id)
        {
            prev->next = ptr->next;
            cout << "Student with Id: " << ptr->id << " deleted Successfully" << endl;
            delete ptr;
            flag = true;
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    if (flag == false)
    {
        cout << "Student with Id:" << id << " NOt Found in the List" << endl;
    }
}
int main()
{
    List studentList; // Create an instance of the List class
    int choice;
    do
    {
        // Display Menu
        cout << "\n********| STUDENTS LIST |********" << endl;
        cout << "1. Enter data of five students" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Add a new student at the end of the list" << endl;
        cout << "4. Search for a particular student by ID" << endl;
        cout << "5. Delete a student by ID" << endl;
        cout << "6. Exit" << endl;
        cout << "*******************************************" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform actions based on the choice
        switch (choice)
        {
        case 1:
        {
            cout << "\nEnter data for five students:\n";
            for (int i = 0; i < 5; i++)
            {
                int id;
                string name;
                float gpa;
                cout << "Enter ID for student " << i + 1 << ": ";
                cin >> id;
                cin.ignore(); // To ignore the newline character left in the input buffer
                cout << "Enter Name for student " << i + 1 << ": ";
                getline(cin, name);
                cout << "Enter GPA for student " << i + 1 << ": ";
                cin >> gpa;
                studentList.insertlast(id, name, gpa); // Add student to the list
            }
            break;
        }
        case 2:
            cout << "\nDisplaying all students:\n";
            studentList.display(); // Display all students
            break;

        case 3:
        {
            cout << "\nAdd a new student at the end of the list:\n";
            int id;
            string name;
            float gpa;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(); // To ignore the newline character left in the input buffer
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter GPA: ";
            cin >> gpa;
            studentList.insertlast(id, name, gpa); // Add new student
            break;
        }
        case 4:
        {
            cout << "\nSearch for a student by ID:\n";
            int id;
            cout << "Enter ID: ";
            cin >> id;
            studentList.search(id); // Search for a student
            break;
        }
        case 5:
        {
            cout << "\nDelete a student by ID:\n";
            int id;
            cout << "Enter ID: ";
            cin >> id;
            studentList.deletestd(id); // Delete a student
            break;
        }
        case 6:
            cout << "\nExiting the program. Goodbye!" << endl;
            break;

        default:
            cout << "\nInvalid choice. Please try again!" << endl;
        }

    } while (choice != 6); // Loop until the user chooses to exit

    return 0;
}
