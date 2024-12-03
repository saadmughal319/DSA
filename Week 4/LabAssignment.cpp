/*                              Lab Assignment(week 4)
Write a program to simulate a dictionary using linked list.
It should be a menu driven program with the options for adding a word
and its meanings, searching a word and displaying the dictionary.
Steps to develop the program are as given below:
1. Declare a structure with the fields as
    - a word,
    - meaning of a word
    - counter that holds the number of meanings
    - link to the next node.

Each word added to the list can have maximum 5 meaning(s).
Hence, variable used to store meaning(s) of a word would be a two dimensional character array.
2. The program should have following menu.
    - Add a word
    - Search for a word
    - Show dictionary
    - Exit
*/
#include <iostream>
#include <cstring> //becaue i have used strcpy ()fucntion
using namespace std;
struct node
{
    string word;
    char meaning[5][50]; // maximum 5 meaning each with maximum 49 word lenghth
    int counter;         // to track how many manings of a word are stored;
    node *next;
    node(); // defalult constructor for each node
};
class Dictionary
{
private:
    node *start;

public:
    Dictionary();                          // default constructor fro class
    void insert(string, char[5][50], int); // to insert a word into dictionary
    void search(string);                   // to search a word  and display it from the dictionary
    void display();                        // to display the entire dictionary
};
node::node() // default constructor for node
{
    next = NULL;
    int i;
    for (i = 0; i < 5; i++)
    {
        meaning[i][0] = '\0';
    }
}
Dictionary::Dictionary()
{
    start = NULL;
}
void Dictionary::insert(string word, char meaning[5][50], int counter)
{
    node *newNode = new node;
    newNode->next = NULL; // becaue it is going to be inserted at last of the list
    newNode->word = word;
    newNode->counter = counter;
    int i;
    for (i = 0; i < 5; ++i)
    {
        strcpy(newNode->meaning[i], meaning[i]);
    }
    newNode->counter = counter;
    // if node is empty
    if (start == NULL)
    {
        start = newNode;
        cout << "****|New Word inserted at the Last of the Dictionary|****" << endl;
        return;
    }
    node *ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    cout << "****|New Word inserted at the Last of the Dictionary|****" << endl;
}
void Dictionary::search(string word)

{
    if (start == NULL)
    {
        cout << "****|Dictionary is Empty|****" << endl;
        return;
    }
    node *ptr = start;
    bool flag = false; // to check if word is found or not after loop
    while (ptr != NULL)
    {
        if (ptr->word == word)
        {
            flag = true;
            cout << "(Word Found) Details of |" << word << " |:are below:" << endl;
            cout << "Word| " << word << endl;
            // loop to print all five meanings
            for (int i = 0; i < 5; i++)
            {
                if (ptr->meaning[i][0] == '\0') // Check if the char array is empty
                {
                    cout << "No more meanings. Moving on to display the next..." << endl;
                    break;
                }
                cout << "Meaning: " << i + 1 << " | " << ptr->meaning[i] << endl;
            }
        }
        ptr = ptr->next;
    }
    if (flag == false)
        cout << "Word NOt Found in the |Entire| dictionary" << endl;
    cout << "***************************************************************" << endl;
}
void Dictionary::display()
{
    if (start == NULL)
    {
        cout << "***************|Dictionary is Empty|***********" << endl;
        return;
    }
    node *ptr = start; // to travess the list
    while (ptr != NULL)
    {
        cout << "Word| " << ptr->word << endl;
        for (int i = 0; i < 5; i++)
        {
            if (ptr->meaning[i][0] == '\0') // Check if the char array is empty
            {
                cout << "No more meanings. Moving on to display the next..." << endl;
                break;
            }
            cout << "Meaning " << i + 1 << ": " << ptr->meaning[i] << endl;
        }
        cout << "***************************************" << endl;
        ptr = ptr->next;
    }
}
int main()
{
    Dictionary d1;
    int choice;
    do
    {
        // Display Menu
        cout << "\n**********| DICTIONARY |**********\n";
        cout << "1. Add a Word \n";
        cout << "2. Search for a Word\n";
        cout << "3. Show Whole Dictionary \n";
        cout << "4. Exit\n";
        cout << "**************************\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string word;
            char meaning[5][50];
            int counter = 0;
            cout << "Enter a Word and it's Meanings(upto 5,press ENTER if no Meaning)" << endl;
            cout << "Word: ";
            cin >> word;
            cin.ignore();
            for (int i = 0; i < 5; i++)
            {
                cout << "Meaning " << i + 1 << ": ";
                cin.getline(meaning[i], 50); // Read each meaning
                // If the user presses Enter without entering anything, break the loop
                if (meaning[i][0] == '\0')
                {
                    cout << "No more meanings entered. Moving on..." << endl;
                    break;
                }
            }
            d1.insert(word, meaning, counter); // function call to insert word in the list(dictoinary)
            break;
        }
        case 2:
        {
            string word;
            cout << "Enter Word to be searched " << endl;
            cin >> word;
            d1.search(word);
            break;
        }
        case 3:
        {
            d1.display();

            break;
        }
        case 4:
        {
            cout << "Exiting......" << endl;
            break;
        }
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}