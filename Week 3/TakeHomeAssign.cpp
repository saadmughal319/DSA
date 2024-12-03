/*                          Take Home Assignment
Write a program to visit a singly linked list consisting of five nodes
 and having a data field of integer type. Calculate the factorial of each
  value stored in it. Create a new linked list and store the factorial in
   the newly created linked list, and display the results.
*/
#include <iostream>
using namespace std;
struct node

{
    int data;
    node
        *next;
};
class SLL
{
private:
    node
        *start;

public:
    SLL(); // default constructor
    void insertlast(int);
    void factorial(const SLL &);
    void display();
};
SLL::SLL()
{
    start = NULL;
}
void SLL::display()
{
    if (start==NULL)
    {
        cout<<"*****|List is Empty|******"<<endl;
        return;
    }
    node *ptr=start;
    while (ptr != NULL)
    {
        cout<<"|"<<ptr->data<<"|  ";
        ptr=ptr->next;;
    }
}
void SLL::insertlast(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL; // becaue it is goig to be inserted at the last
    if (start == NULL)    // empty list case
    {
        start = newNode;
        cout << "****|New Node Inserted at Last|****" << endl;
        return;
    }
    node *ptr = start; // to traverse the list
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    cout << "****|New Node inserted at Last|****" << endl;
}
void SLL::factorial(const SLL &list)
{
    node *ptr = list.start; // Start of the input list
    if (ptr == NULL) // Check for empty list
    {
        cout << "The input list is empty. No factorials to calculate." << endl;
        return;
    }

    while (ptr != NULL)
    {
        int fact = 1; // Reset factorial for each node
        for (int i = 1; i <= ptr->data; i++)
        {
            fact *= i; // Calculate factorial
        }
        this->insertlast(fact); // Add factorial to the new list
        ptr = ptr->next;        // Move to the next node
    }
}

int main()      //main function format is gnerated by chat gpt
{
    SLL originalList, factorialList; // Two lists: one for input, one for factorials
    int choice;

    do
    {
        // Display Menu
        cout << "\n********** MENU **********\n";
        cout << "1. Add a Node to the Original List\n";
        cout << "2. Calculate Factorials and Create New List\n";
        cout << "3. Display the Original List\n";
        cout << "4. Display the Factorial List\n";
        cout << "5. Exit\n";
        cout << "**************************\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter an integer value to add to the list: ";
            cin >> data;
            originalList.insertlast(data); // Add to the original list
            break;
        }
        case 2:
        {
            factorialList.factorial(originalList); // Calculate factorials
            cout << "Factorials calculated and stored in the new list.\n";
            break;
        }
        case 3:
        {
            cout << "Original List:\n";
            originalList.display(); // Display the original list
            break;
        }
        case 4:
        {
            cout << "Factorial List:\n";
            factorialList.display(); // Display the factorial list
            break;
        }
        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}