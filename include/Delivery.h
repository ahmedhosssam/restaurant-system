#ifndef DELIVERY_H
#define DELIVERY_H

#include <string>
#include "Order.h"

class Delivery : public Order
{
    public:
        Delivery(Meal** mealArr, int mealCount);
        void calcPrice();
        double getPrice();
        void printReciept();
        virtual ~Delivery();

    protected:
        string address;
};

#endif 
