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

void GameTable::removeCard(int row, int column)
{
    this->table.at(row).at(column) = 0;
}

vector<vector<GameCard *>> GameTable::getTable()
{
    return this->table;
}

bool GameTable::isCaseAvaileble(int row, int col)
{
    return (this->table[row][col] == 0);
}

/**
 * The functions following works only when the condition isCaseAvailable is true
*/
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
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

bool GameTable::isMatchWithBottom(GameCard *card, int row, int column)
{
    if (row == this->table.size() - 1)
    {
        return true;
    }
    else
    {
        if (isCaseAvaileble(row + 1, column))
        {
            return true;
        }
        else
        {
            if (card->getBottom() == this->table[row + 1][column]->getTop())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

bool GameTable::isMatchWithLeft(GameCard *card, int row, int column)
{
    if (column == 0)
    {
        return true;
    }
    else
    {
        if (isCaseAvaileble(row, column - 1))
        {
            return true;
        }
        else
        {
            if (card->getLeft() == this->table[row][column - 1]->getRight())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

bool GameTable::isMatchWithRight(GameCard *card, int row, int column)
{
    if (column == this->table[0].size() - 1)
    {
        return true;
    }
    else
    {
        if (isCaseAvaileble(row, column + 1))
        {
            return true;
        }
        else
        {
            if (card->getRight() == this->table[row][column + 1]->getLeft())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

void GameTable::displayTable()
{
    for (int i = 0; i < this->table.size(); i++)
    {
        for (int j = 0; j < this->table[i].size(); j++)
        {
            cout << this->table[i][j] << ' ';
        }
        cout << endl;
    }
}