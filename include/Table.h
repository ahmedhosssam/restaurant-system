#ifndef TABLE_H
#define TABLE_H

class Table {
    public:
        Table();
        Table(int id);
        virtual ~Table();
        void updateStatus();
        bool getStatus();
        int getId();

    private:
        bool status;
        int id;
};

#endif 
