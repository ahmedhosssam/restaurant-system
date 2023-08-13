#include <iostream>
#include <vector>

#include "../include/TakeAway.h"
#include "../include/Order.h"
#include "../include/Meal.h"

using namespace std;

TakeAway::TakeAway(vector<Meal*> mealArr) : Order(mealArr) {
}