#ifndef DELIVERY_H
#define DELIVERY_H

#include <string>
#include <vector>
#include "Order.h"

class Delivery : public Order {
    public:
        Delivery(vector<Meal*> mealArr);
        void calcPrice();
        double getPrice();
        void printReciept();
        virtual ~Delivery();

    protected:
        string address;
};

#endif 
