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

void GameTable::putCard(GameCard *card, int row, int column)
{
    this->table.at(row).at(column) = card;
}

vector<vector<GameCard *>> GameTable::getTable()
{
    return this->table;
}

bool GameTable::isCaseAvaileble(int row, int col)
{
    return (this->table[row][col] == 0);
}

bool GameTable::isMatchWithTop(GameCard *card, int row, int column)
{
    if (row == 0)
    {
        return true;
    }
    else
    {
        if (isCaseAvaileble(row - 1, column))
        {
            return true;
        }
        else
        {
            if (card->getTop() == this->table[row - 1][column]->getBottom())
            {
                // cout << "okok" << endl;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}