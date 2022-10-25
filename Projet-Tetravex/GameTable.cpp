#include "GameTable.h"

GameTable::GameTable() {}

GameTable::GameTable(int width, int height)
{
    this->width = width;
    this->height = height;
    this->table.resize(height);
    for (int i = 0; i < this->table.size(); i++)
    {
        this->table[i].resize(width);
    }
}