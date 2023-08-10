#include <iostream>
#include <string>
using namespace std;
#ifndef INGREDIANT_H
#define INGREDIANT_H


class Ingredient
{
    public:
        Ingredient();
        Ingredient(string m_name, int m_id, double m_price, int quantity);
        void setData();
        void update_quantity();
        void update_price();
        double getPrice();
        int getID();
        string getData();
        void reduceQuantity();
        friend istream& operator >>(istream&,Ingredient*);
        friend ostream& operator <<(ostream&,Ingredient&);
        virtual ~Ingredient();

    protected:

    private:
        string m_name;
        int m_quantity, m_id;
        double m_price;
};

#endif // INGREDIANT_H
