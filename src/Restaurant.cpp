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
#include "../include/general.h"

using namespace std;

Restaurant::Restaurant() {
    total_revenue = 0;
    m1->setStock(&s);
    
    // Tables :
    for (int i = 0; i < 15; i++)
        tableArray.push_back(Table(i + 1)); // i + 1 to start from 1 not 0

    tableArrSize = static_cast<int>(tableArray.size());
}

void Restaurant::makeOrder() {
    vector<Meal*> mealList;
    m1->display_all();
    int quantity;
    int option;
    int clientPlace; // takeAway || delivery || inRestaurant
    string option2 = "y";

    while (true) {
        cout << "Select a meal by its number: ";
        option = getInt();

        if (option >= m1->getMealsNumber()) {
            cout << "\n<<-- Please enter a valid number -->>\n\n";
            continue;
        }

        Meal* currentMeal = m1->getMeal(option);
        cout << "Enter quantity: ";
        quantity = getInt();

        if (quantity <= 0 || quantity > currentMeal->getQuantity()) {
            cout << "\n<<-- Invalid quantity. Available quantity for a '" << currentMeal->getName() << "' is " << currentMeal->getQuantity() << " -->>\n\n" << endl;
            continue;
        }

        currentMeal->updateQuantity(quantity);
        mealList.push_back(currentMeal);

        cout << "Want to add another meal? (y/n): ";
        cin >> option2;
        
        if (option2 == "y" || option2 == "Y") {
            continue;
        } else {
            cout << "Choose a location: \n";
            cout << "0: In Restaurant\n";
            cout << "1: Delivery\n";
            cout << "2: Take Away\n";
            cout << "Enter your choice: ";
            clientPlace = getInt();
            
            break;
        }
    } 

    switch (clientPlace) {
        case 0: {
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
        case 1: {
            Order* d1 = new Delivery(mealList);
            orderArray.push_back(d1);
            addToTotalRevenue(d1->getPrice());
            d1->printReciept();
            cout << "test\n";
            break;
        }
        case 2: {
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
    m1->display_all();
}

void Restaurant::getOrdersReports() {
    for(int i = 0; i < static_cast<int>(orderArray.size()); i++) {
        orderArray[i]->printReciept();
    }
}

void Restaurant::getMealsReports() {
    m1->display_all();
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
    } else {
        cout << "Invalid choice\n";
    }
}

void Restaurant::delete_ingredient() {
    s.delete_ingredient();
}

void Restaurant::addMeal() {
    Meal* newMeal = new Meal(&s);
    m1->add_meal(newMeal);
}

void Restaurant::addMeal(Meal* m) {
    m1->add_meal(m);
}

void Restaurant::deleteMeal() {
    int id;
    m1->display_all();

    while (true) {
        if (m1->getMealsNumber() == 0) {
            cout << "There's no meals right now.\n";
            break;
        }

        cout << "Choose the meal that you want to delete: "; cin >> id;
        if(id < m1->getMealsNumber() && id >= 0) {
            m1->deleteMeal(id);
            break;
        } else {
            cout << "Please enter a valid number.\n";
        }
    }
}

Restaurant::~Restaurant() {
    delete m1; 

    for (Order* order : orderArray) {
        delete order;
    }
}