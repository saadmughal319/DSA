/*                                          Lab Task
# include < iostream.h>
struct date
{
int day;
int month;
int year;
};
void main ( )
{
struct date today;
today.day=3;
today.month=10;
today.year=2000;
cout<<"\nToday\s day is : "<< today.day<<"/"<<today.month<<"/"<<today.year;
}

Rewrite the above program by adding two functions :
                         For entering date.
                         For displaying the date.*/
#include <iostream>
using namespace std;
struct date
{
private:
    int day;
    int month;
    int year;

public:
    void inputdate();
    void displaydate();
};
void date::inputdate()
{
    cout << "Enter Day:" << endl;
    cin >> day;
    cout << "Enter Month:" << endl;
    cin >> month;
    cout << "Enter year:" << endl;
    cin >> year;
}
void date::displaydate()
{
    cout << "Date is (dd,mm,yy):" << endl;
    cout << day << "|" << month << "|" << year << endl;
}
int main()
{
    date d;
    d.inputdate();
    d.displaydate();
    return 0;
}
