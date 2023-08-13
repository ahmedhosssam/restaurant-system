#ifndef TAKEAWAY_H
#define TAKEAWAY_H

#include <iostream>
#include <vector>

#include "Order.h"
#include "Meal.h"

class TakeAway : public Order {
    public:
        TakeAway(vector<Meal*> mealArr);
};

#endif 
