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
    Table* tableArray;// for all tables
    Ingredient* ingArray;
    double total_revenue;
    menu m1;
    int tableCount;
    int ingCount;

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
