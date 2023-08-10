#include "Manager.h"
#include <unistd.h>

Manager::Manager() {}

void Manager::ingredients(){
    int c=-1;
    while(c!=0){
        system("cls");
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
            system("cls");
            a.add_ingrediant();
            cout<<"\nEnter any key to continue...";
            _getch();
            break;
        case 2:
            system("cls");
            a.update_ingrediant_quantity();
            break;
        case 3:
            system("cls");
            a.update_ingrediant_price();
            break;
        case 4:
            system("cls");
            a.delete_ingrediant();
            break;
        case 0:
            return;
        default:
            cout<<"\nInvalid input! please try again...";
            cout<<"\nEnter any key to continue...";
            _getch();
        }
    }
}

void Manager::meal(){
    int c=-1;
    while(c!=0){
        cout<<"Meal: \n\n"
            <<"  1.Add meal to the menu\n"
            <<"  2.Update meal price\n"
            <<"  3.Delete meal from menu\n"
            <<"  0.Return \n"
            <<"\nEnter your choice: ";
        cin >> c;
        switch(c){
        case 1:
            system("cls");
            r.addMeal(&a);
            cout<<"\nEnter any key to continue...";
            _getch();
            break;
        case 2:
            system("cls");
            r.updateMealPrice();
            break;
        case 3:
            system("cls");
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
    int c=-1;
    while(c!=0){
            system("cls");
        cout<<"Display: \n\n"
            <<"  1.Ingredients in stock\n"
            <<"  2.Menu\n"
            <<"  0.Return\n"
            <<"\nEnter your choice: ";
        cin >> c;
        switch(c){
        case 1:
            system("cls");
            r.getIngredientsReports();
            cout<<"\nEnter any key to continue...";
            _getch();
            break;
        case 2:
            system("cls");
            r.showMenu();
            cout<<"\nEnter any key to continue...";
            _getch();
            break;
        case 0:
            return;
        default:
            cout<<"\nInvalid input! please try again...";
            sleep(3);
        }
    }
}

void Manager::kitchen(){
    int c=-1;
    while(c!=0){
        cout<<"Kitchen: \n\n"
            <<"  1.Ingredients\n"
            <<"  2.Meal\n"
            <<"  3.Display\n"
            <<"  0.Return\n"
            <<"\nEnter your choice: ";
        cin >> c;
        switch(c){
        case 1:
            system("cls");
            ingredients();
            break;
        case 2:
            system("cls");
            meal();
            break;
        case 3:
            system("cls");
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

//***********************

void Manager::MakeOrder(){
    r.makeOrder();
}

//***********************
void Manager::reports(){
    int c=-1;
    while(c!=0){
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
