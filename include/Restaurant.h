#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include <string>
#include "Order.h"
#include "Menu.h"
#include "Table.h"
#include "Stock.h"

using namespace std;

class Restaurant {
  private:
    vector<Order*> orderArray; // for all orders that had been made
    vector<Table> tableArray;
    double total_revenue;
    Menu m1;
    Stock s;
    int tableArrSize;

  public:
    Restaurant();
    void makeOrder();
    void addToTotalRevenue(double orderPrice);
    void showMenu();
    void getIngredientsReports();
    void addMeal();
    void add_ingredient();
    void update_ingredient(int i);
    void addMeal(Stock*);
    void updateMealIng();
    void updateMealPrice();
    void deleteMeal();
    void getOrdersReports();
    void getMealsReports();
    double getTotalRevenue();
    ~Restaurant();
};

#endif
