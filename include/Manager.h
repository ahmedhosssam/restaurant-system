#include <iostream>
#include "Stock.h"
#include "Menu.h"
#include "Restaurant.h"
#include <unistd.h>
using namespace std;
#ifndef MANAGER_H
#define MANAGER_H


class Manager
{
    public:
        Manager();
        void kitchen();
        void ingredients();
        void meal();
        void display();
        void MakeOrder();
        void reports();
        virtual ~Manager();

    protected:

    private:
        stock a;
        Restaurant r;

};

#endif // MANAGER_H
