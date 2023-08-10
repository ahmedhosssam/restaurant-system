#include <iostream>
#include <string>
#include <vector>

#include "../include/Restaurant.h"
#include "../include/Order.h"
#include "../include/TakeAway.h"
#include "../include/InRestaurant.h"
#include "../include/Delivery.h"
#include "../include/Meal.h"
#include "../include/Menu.h"
#include "../include/Ingredient.h"
#include "../include/Table.h"

using namespace std;

Restaurant::Restaurant() {
    total_revenue = 0;
    
    // Tables :
    for (int i = 0; i < 15; i++)
        tableArray.push_back(Table(i + 1)); // i + 1 to start from 1 not 0

    tableArrSize = static_cast<int>(tableArray.size());
}

void Restaurant::makeOrder() {
    vector<Meal*> mealList;
    m1.display_all();
    int quantity;
    int option;
    int mealCounter = 0;
    int clientPlace;    // takeAway || delivery || inRestaurant
    string option2;

    do
    {
        cout << "Select a meal by its number: ";
        cin >> option;
        if (option > m1.getMealsNumber()) {
            cout << "Please enter a valid number.\n";
            continue;
        }

        Meal* currentMeal = m1.getMeal(option);
        cout << "Enter quantity: ";
        cin >> quantity;

        if (quantity <= 0 || quantity > currentMeal->getQuantity())
        {
            cout << "Invalid quantity. Available quantity for a '" << currentMeal->getName() << "' is " << currentMeal->getQuantity() << endl;
            continue;
        }

        currentMeal->reduceQuantity(quantity);
        currentMeal->setOrderQuantity(quantity);

        mealList.push_back(currentMeal);

        mealCounter++;

        cout << "Want to add another meal? (y/n): ";
        cin >> option2;

        cout << "Choose a location: \n";
        cout << "0: In Restaurant\n";
        cout << "1: Delivery\n";
        cout << "2: Take Away\n";
        cout << "Enter your choice: ";
        cin >> clientPlace;
    } while (option2 == "y" || option2 == "Y");

        switch (clientPlace)
        {
            case 0:
            {
                for (int i = 0; i < tableArrSize; ++i) {
                    if (!tableArray[i].getStatus()) {
                        Order* r1 = new InRestaurant(mealList, tableArray[i].getId());
                        orderArray.push_back(r1);
                        addToTotalRevenue(r1->getPrice());
                        r1->printReciept();
                        tableArray[i].updateStatus();
                        break;
                    }
                }
                break;
            }
            case 1:
            {
                Order* d1 = new Delivery(mealList);
                orderArray.push_back(d1);
                addToTotalRevenue(d1->getPrice());
                d1->printReciept();
                cout << "test\n";
                break;
            }
            case 2:
            {
                Order* t1 = new TakeAway(mealList);
                orderArray.push_back(t1);
                addToTotalRevenue(t1->getPrice());
                t1->printReciept();
                break;
            }
            default:
                cout << "Invalid choice." << endl;
                break;
        }
}

void Restaurant::addToTotalRevenue(double orderPrice) {
    total_revenue += orderPrice;
}

double Restaurant::getTotalRevenue() {
    return Restaurant::total_revenue;
}

void Restaurant::showMenu() {
    m1.display_all();
}

void Restaurant::getOrdersReports() {
    for(int i = 0; i < static_cast<int>(orderArray.size()); i++) {
        orderArray[i]->printReciept();
    }
}

void Restaurant::getMealsReports() {
    m1.display_all();
}

void Restaurant::getIngredientsReports() {
    s.display_all();
}

void Restaurant::add_ingredient() {
    s.add_ingredient();
}

void Restaurant::update_ingredient(int i) {
    if (i == 1) {
        s.update_ingredient_quantity();
    } else if (i == 2) {
        s.update_ingredient_price();
    }
}

void Restaurant::addMeal(Stock* a) {
    m1.add_meal(a);
}

void Restaurant::updateMealPrice() {
    m1.updateMealPrice();
}

void Restaurant::deleteMeal() {
    m1.deleteMeal();
}

Restaurant::~Restaurant() {
}
