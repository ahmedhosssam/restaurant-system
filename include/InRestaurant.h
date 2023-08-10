#ifndef INRESTAURANT_H
#define INRESTAURANT_H

#include "Order.h"

class InRestaurant : public Order
{
public:
    InRestaurant(Meal** mealArr, int mealCount, int tableId);
    void calcPrice();
    double getPrice();
    void printReciept();
    virtual ~InRestaurant();

protected:
    int tableId;

private:
};

#endif
