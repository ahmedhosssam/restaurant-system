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
    vector<Ingredient> ingArray;
    double total_revenue;
    menu m1;
    int ingCount;
    int tableArrSize;

  public:
    Restaurant();
    void makeOrder();
    void addToTotalRevenue(double orderPrice);
    void showMenu();
    void getIngredientsReports();
    void addMeal();
    void addMeal(stock*);
    void updateMealIng();
    void updateMealPrice();
    void deleteMeal();
    void getOrdersReports();
    void getMealsReports();
    double getTotalRevenue();
    ~Restaurant();
};

#endif
