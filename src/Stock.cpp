#include "../include/Stock.h"

stock::stock()
{
    m_ingSize = 50;
    ingtList = new Ingredient[m_ingSize];
    m_ingCount = 0;
}

void stock::add_ingrediant(){
    Ingredient* a = new Ingredient();
    cin >> a;
    ingtList[m_ingCount++] = *a;
}

void stock::update_ingrediant_quantity(){
    int id;
    bool found = true;
    cout<<"Enter ingredient id: ";
    cin >> id;
    for(int i=0;i<m_ingCount;++i){
        if(ingtList[i].getID()==id){
            ingtList[i].update_quantity();
            found = false;
        }
    }
    if(found){
        cout<<"\nNo matching ingredient found!...\n";
        cout<<"\nEnter any key to continue...";
    }

}

void stock::update_ingrediant_price(){
    int id;
    bool found = true;
    cout<<"Enter ingredient id: ";
    cin >> id;
    for(int i=0;i<m_ingCount;++i){
        if(ingtList[i].getID()==id){
            ingtList[i].update_price();
            found = false;
        }
    }
    if(found){
        cout<<"\nNo matching ingredient found!...\n";
        cout<<"\nEnter any key to continue...";
    }
}

void stock::delete_ingrediant(){
    int id;
    bool found = true;
    cout<<"Enter ingredient id: ";
    cin >> id;
    for(int i=0;i<m_ingCount;++i){
        if(ingtList[i].getID()==id){
            if(i==m_ingCount-1){
                m_ingCount--;
            }
            else{
                ingtList[i]= ingtList[m_ingCount-1];
                m_ingCount--;
            }
            found = false;
        }
    }
    if(found){
        cout<<"\nNo matching ingredient found!...\n";
        cout<<"\nEnter any key to continue...";
    }
}

void stock::display_all(){
    if(m_ingCount!=0){
        cout<<"ingredient list: \n\n";
        for(int i=0; i<m_ingCount;++i){
            cout<<(i+1)<<" - "<< ingtList[i] <<endl;
        }
    }
    else{
        cout<<"There are not ingredients added yet!";
    }
}
Ingredient* stock :: search_ing(int id)
{
    for (int i = 0; i< m_ingCount ; ++i )
    {
        if (ingtList[i].getID() == id)
        {
            return &ingtList[i];
        }
    }
}

stock::~stock()
{
    delete [] ingtList;
}

