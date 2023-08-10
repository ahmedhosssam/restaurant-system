#ifndef TAKEAWAY_H
#define TAKEAWAY_H

#include <iostream>
#include <vector>
#include "Order.h"
#include "Meal.h"

class TakeAway : public Order {
    public:
        TakeAway(vector<Meal*> mealArr);
        void calcPrice();
        double getPrice();
        void printReciept();
};

#endif // TAKEAWAY_H
