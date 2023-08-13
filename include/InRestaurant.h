#ifndef INRESTAURANT_H
#define INRESTAURANT_H

#include <vector>

#include "Order.h"

class InRestaurant : public Order {
    public:
        InRestaurant(vector<Meal*> mealArr, int tableId);
        void printReciept();
        virtual ~InRestaurant();

    protected:
        int tableId;

};

#endif
