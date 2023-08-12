#include <iostream>
#include <unistd.h>

#include "include/Manager.h"
#include "include/Restaurant.h"

using namespace std;

int main() {
    int c = -1;
    Manager a; // for layout
    while (c != 0) {
        cout << "Main menu: " << endl << endl
             << "  1. Kitchen" << endl
             << "  2. Make Order" << endl
             << "  3. Display Menu" << endl
             << "  4. Report" << endl
             << "  0. Exit" << endl
             << "Enter your choice: ";

        cin >> c;

        switch (c) {
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
            a.showMenu();
            break;
        case 4:
            system("clear");
            a.reports();
            break;
        case 0:
            break;
        default:
            cout << "Invalid input! please try again...";
        }
    }

    return 0;
}
