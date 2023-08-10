#include "../include/Table.h"

Table::Table() {}

Table::Table(int id) : id(id)
{
    status = false;
}

bool Table::getStatus()
{
    return status;
}

void Table::updateStatus()
{
    status = !status;
}

int Table::getId()
{
    return id;
}

Table::~Table()
{
    //dtor
}
