#include "GameTable.h"

GameTable::GameTable(vector<int> data)
{
    this->width = data[0];
    this->height = data[1];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            this->table[i][j] = NULL;
        }
    }
}