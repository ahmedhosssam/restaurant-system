#include <iostream>
#include <unistd.h>

#include "include/Manager.h"
#include "include/Restaurant.h"

using namespace std;

int main()
{
    int c = -1;
    Manager a;
    while(c != 0)
    {
        cout<<"\tRestaurants Application\n\n"
            <<"Main menu: \n\n"
            <<"  1. Kitchen\n"
            <<"  2. Make Order\n"
            <<"  3. Report\n"
            <<"  0. Exit\n"
            <<"\nEnter your choice: ";

        cin >> c;

        switch(c)
        {
        case 1:
            system("clear");
            a.kitchen();
            break;
        case 2:
            system("clear");
            a.makeOrder();
            break;
        case 3:
            system("clear");
            a.reports();
            break;
        case 0:
            system("clear");
            cout<<"Thanks!";
            return 0;
        default:
            cout<<"\nInvalid input! please try again...";
            sleep(3);

        }
    }

    return 0;
}
