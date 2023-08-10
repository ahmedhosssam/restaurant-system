#include "../include/Manager.h"
#include <unistd.h>

Manager::Manager() {}

void Manager::ingredients(){
    int c = -1;
    while(c != 0){
        system("clear");
        cout<<"Ingredients: \n\n"
            <<"  1.Add ingredient to stock\n"
            <<"  2.Update ingredient quantity\n"
            <<"  3.Update ingredient price\n"
            <<"  4.Delete ingredient from stock\n"
            <<"  0.Return\n"
            <<"\nEnter your choice: ";

        cin >> c;

        switch(c){
        case 1:
            system("clear");
            a.add_ingrediant();
            cout<<"\nEnter any key to continue...";
            break;
        case 2:
            system("clear");
            a.update_ingrediant_quantity();
            break;
        case 3:
            system("clear");
            a.update_ingrediant_price();
            break;
        case 4:
            system("clear");
            a.delete_ingrediant();
            break;
        case 0:
            return;
        default:
            cout<<"\nInvalid input! please try again...";
        }
    }
}

void Manager::meal(){
    int c = -1;
    while(c != 0){
        cout<<"Meal: \n\n"
            <<"  1.Add meal to the menu\n"
            <<"  2.Update meal price\n"
            <<"  3.Delete meal from menu\n"
            <<"  0.Return \n"
            <<"\nEnter your choice: ";

        cin >> c;

        switch(c){
        case 1:
            system("clear");
            r.addMeal(&a);
            break;
        case 2:
            system("clear");
            r.updateMealPrice();
            break;
        case 3:
            system("clear");
            r.deleteMeal();
            break;
        case 0:
            return;
        default:
            cout<<"\nInvalid input! please try again...";
            sleep(3);
        }
    }
}

void Manager::display(){
    int c = -1;
    while(c != 0){
        system("clear");
        cout<<"Display: \n\n"
            <<"  1.Ingredients in stock\n"
            <<"  2.Menu\n"
            <<"  0.Return\n"
            <<"\nEnter your choice: ";

        cin >> c;

        switch(c){
        case 1:
            system("clear");
            r.getIngredientsReports();
            break;
        case 2:
            system("clear");
            r.showMenu();
            break;
        case 0:
            return;
        default:
            cout << "\nInvalid input! please try again...\n";
            sleep(3);
        }
    }
}

void Manager::kitchen(){
    int c = -1;

    while(c != 0){
        cout<<"Kitchen: \n\n"
            << "  1.Ingredients\n"
            << "  2.Meal\n"
            << "  3.Display\n"
            << "  0.Return\n"
            << "\nEnter your choice: ";

        cin >> c;

        switch(c){
        case 1:
            system("clear");
            ingredients();
            break;
        case 2:
            system("clear");
            meal();
            break;
        case 3:
            system("clear");
            display();
            break;
        case 0:
            return;
        default:
            cout<<"\nInvalid input! please try again...";
            sleep(3);

        }
    }
}

void Manager::makeOrder(){
    r.makeOrder();
}

void Manager::reports(){
    int c = -1;

    while(c != 0){
        cout<<"Reports: \n\n"
            <<"  1.Ingredients report\n"
            <<"  2.Meals report\n"
            <<"  3.Orders report\n"
            <<"  4.Total revenue\n"
            <<"  0.return\n"
            <<"\nEnter your choice: ";
        cin >> c;
        switch(c){
        case 1:
            r.getIngredientsReports();
            break;
        case 2:
            r.getMealsReports();
            break;
        case 3:
            r.getOrdersReports();
            break;
        case 4:
            cout << "$" << r.getTotalRevenue() << endl;
            break;
        case 0:
            return;
        default:
            cout<<"\nInvalid input! please try again...";
            sleep(3);

        }
    }
}

Manager::~Manager(){}