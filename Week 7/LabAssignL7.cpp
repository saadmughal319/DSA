/*                                  Lab Assignment

Above program does not include the concept of Queue ADT and also not using pointers-structure
so you are required to rewrite above using ‘struct’ data structure along with pointer.
You are also required to write the following operations on the queue using the concept
of Queue-ADT.

1.	Creating Queue
2.	Add/insert operation
3.	Display contents of the queue
4.	Delete some items from the queue
5.	check status of queue – empty or full

*/
#include <iostream>
#include <conio.h> //for getch used in menu
using namespace std;
struct node
{
    char data;
    node *next;
};
class Queue
{
private:
    node *front;
    node *rear;

public:
    Queue(); // default constructor
    void insert(char);
    void remove();
    void display();
    bool isEmpty();
    // bool isFull();   //Not Required in Linked list based implementation
};
Queue::Queue()
{
    front = NULL;
    rear = NULL;
}
void Queue::insert(char data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty()) // means queue is empty
    {
        front = rear = newNode;
        cout << "New Element inserted in Queue" << endl;
        return;
    }
    newNode->next = front;
    rear->next = newNode;
    rear = newNode;
    cout << "New Element insertd in the Queue" << endl;
}
void Queue::remove()
{
    if (isEmpty())
    {
        cout << "Queue is Empty: Nothing to Remove" << endl;
        return;
    }
    if (front == rear) // only one node case
    {
        delete front;        // delete memorey location pointed by front (it is also pointed by rear)
        front = rear = NULL; // makes queue empty
        cout << "Only Element is Deleted : Queue is Empty Now" << endl;
        return;
    }
    rear->next = front->next; // to maintain circular structure rear will now point to the node next to the node to be deleted
    delete front;             // delete the node that is pointed by front
    front = rear->next;       // move front to the next node
    cout << "Element is Deletd from the Queue" << endl;
}
void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is Empty: Nothing to Display" << endl;
        return;
    }
    node *ptr = front; // Start traversal from the front
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != front);
}
bool Queue::isEmpty()
{
    return front == NULL;
}
int main()
{
    Queue queue; // Create an instance of the Queue
    char choice;
    char data;

    do
    {
        // Display the menu
        cout << "\n=========================\n";
        cout << "       Queue Menu        \n";
        cout << "=========================\n";
        cout << "1. Insert an Element\n";
        cout << "2. Remove an Element\n";
        cout << "3. Display Queue\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Exit\n";
        cout << "=========================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Process the user's choice
        switch (choice)
        {
        case '1': // Insert an Element
            cout << "Enter the element to insert (single alphabet character): ";
            data = getch();       // Get a single character input
            cout << data << endl; // Display the entered character

            //checking enure that user has inputted a character
            if ((data >= 'A' && data <= 'Z') || (data >= 'a' && data <= 'z'))
            {
                queue.insert(data); 
            }
            else
            {
               cout <<"Invalid input! Please enter a valid alphabet character.\n";
            }
            break;
        case '2': // Remove an Element
            queue.remove();
            break;

        case '3': // Display Queue
            cout << "Queue Contents:\n";
            queue.display();
            break;

        case '4': // Check if Queue is Empty
            if (queue.isEmpty())
            {
                cout << "The Queue is EMPTY.\n";
            }
            else
            {
                cout << "The Queue is NOT EMPTY.\n";
            }
            break;

        case '5': // Exit
            cout << "Exiting the program. Thank you!\n";
            break;

        default: // Invalid Input
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != '5'); // Repeat until the user chooses to exit

    return 0;
}