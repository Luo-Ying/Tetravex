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
    for (int i = 0; i < this->table.size(); i++)
    {
        for (int j = 0; j < this->table[i].size(); j++)
        {
            cout << this->table[i][j] << ' ';
        }
        cout << endl;
    }
    cout << (this->table[0][0] == 0) << endl;
}

vector<vector<GameCard *>> GameTable::getTable()
{
    return this->table;
}

bool GameTable::isCaseAvaileble(int row, int col)
{
    return (this->table[row][col] == 0);
}