#include <iostream>
#include <string>
#include <vector>
#include "Restaurant.h"
#include "Order.h"
#include "TakeAway.h"
#include "InRestaurant.h"
#include "Delivery.h"
#include "Meal.h"
#include "menu.h"
#include "Ingredient.h"
#include "Table.h"
using namespace std;

Restaurant::Restaurant()
{
    total_revenue = 0;
    orderCount = 0;
    tableCount = 10;
    ingCount = 7;

    // Tables :
    tableArray = new Table[tableCount];
    for (int i = 0; i < tableCount; i++)
        tableArray[i] = Table(i + 1);

    // test ingredients
    ingArray = new Ingredient[ingCount];
    ingArray[0] = Ingredient("Tomato", 0, 3, 15);
    ingArray[1] = Ingredient("Bread", 1, 4, 10);
    ingArray[2] = Ingredient("Beef", 2, 5, 12);
    ingArray[3] = Ingredient("Potato", 3, 3, 45);
    ingArray[4] = Ingredient("Spaghetti", 4, 6, 36);
    ingArray[5] = Ingredient("Chicken ", 5, 6, 24);
    ingArray[6] = Ingredient("Cheese", 6, 6, 17);

    // test meals
    Ingredient burgerIngredients[] = {ingArray[0], ingArray[1], ingArray[2]};
    Meal burger("Burger", 0, 6, burgerIngredients, 3);

    Ingredient spaghettiIngredients[] = {ingArray[4], ingArray[0]};
    Meal spaghettiBolognese("Spaghetti Bolognese", 1, 10, spaghettiIngredients, 2);

    Ingredient chickenBreastIngredients[] = {ingArray[5], ingArray[1]};
    Meal chickenBreast("Chicken Breast", 2, 15, chickenBreastIngredients, 2);

    // test menu
    m1.add_meal(burger);
    m1.add_meal(spaghettiBolognese);
    m1.add_meal(chickenBreast);
    orderArray = new Order*[orderCount];
}

void Restaurant::makeOrder()
{
    Meal** mealList = nullptr;  // Dynamic array of Meal pointers
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
        if (option > m1.getMealsNumber())
        {
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

        // Resize the dynamic array
        Meal** temp = new Meal*[mealCounter + 1];
        for (int i = 0; i < mealCounter; i++)
        {
            temp[i] = mealList[i];
        }
        temp[mealCounter] = currentMeal;

        delete[] mealList;
        mealList = temp;

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
                for (int i = 0; i < tableCount; ++i)
                {
                    if (!tableArray[i].getStatus())
                    {
                        Order* r1 = new InRestaurant(mealList, mealCounter ,tableArray[i].getId());
                        orderArray[orderCount] = r1;
                        orderCount++;
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
                Order* d1 = new Delivery(mealList, mealCounter);
                orderArray[orderCount] = d1;
                orderCount++;
                addToTotalRevenue(d1->getPrice());
                d1->printReciept();
                break;
            }
            case 2:
            {
                Order* t1 = new TakeAway(mealList, mealCounter);
                orderArray[orderCount] = t1;
                orderCount++;
                addToTotalRevenue(t1->getPrice());
                t1->printReciept();
                break;
            }
            default:
                cout << "Invalid choice." << endl;
                break;
        }
}

void Restaurant::addToTotalRevenue(double orderPrice)
{
    total_revenue += orderPrice;
}

double Restaurant::getTotalRevenue()
{
    return Restaurant::total_revenue;
}

void Restaurant::showMenu()
{
    m1.display_all();
}

void Restaurant::getOrdersReports()
{
    for(int i = 0; i < orderCount; i++)
    {
        orderArray[i]->printReciept();
    }
}

void Restaurant::getMealsReports()
{
    m1.display_all();
}

void Restaurant::getIngredientsReports()
{
    for(int i = 0; i < ingCount; i++)
        cout << ingArray[i].getData() << endl;
}

void Restaurant::addMeal(stock* a)
{
    m1.add_meal(a);

}

void Restaurant::updateMealPrice()
{
    m1.updateMealPrice();
}

void Restaurant::deleteMeal()
{
    m1.deleteMeal();
}

Restaurant::~Restaurant()
{
    delete[] orderArray;
    delete[] tableArray;
    delete[] ingArray;
}
