#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>

#include "Stock.h"
#include "Menu.h"
#include "Restaurant.h"

using namespace std;

// this class just for layout
class Manager {
    public:
        Manager();
        void kitchen();
        void ingredients();
        void meal();
        void display();
        void makeOrder();
        void reports();
        void showMenu();
        virtual ~Manager();

    private:
        Restaurant r;

};

#endif // MANAGER_H
