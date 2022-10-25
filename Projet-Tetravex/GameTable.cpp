#include "GameTable.h"

GameTable::GameTable() {}

GameTable::GameTable(int width, int height)
{
    this->width = width;
    this->height = height;
    // for (int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
    //         cout << "put" << endl;
    //         this->table[i][j] = NULL;
    //     }
    // }
    this->table.resize(height);
    for (int i = 0; i < this->table.size(); i++)
    {
        this->table[i].resize(width);
    }
    // cout << this->table.size() << endl;
    // cout << this->table[0].size() << endl;
    // for (int i = 0; i < this->table.size(); i++)
    // {
    //     for (int j = 0; j < this->table[i].size(); j++)
    //     {
    //         cout << this->table[i][j] << endl;
    //     }
    // }
}