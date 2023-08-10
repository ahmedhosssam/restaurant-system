#ifndef TABLE_H
#define TABLE_H

class Table
{
    public:
        Table();
        Table(int id);
        virtual ~Table();
        void updateStatus();
        bool getStatus();
        int getId();

    protected:

    private:
        bool status;
        int id;
};

#endif // TABLE_H
