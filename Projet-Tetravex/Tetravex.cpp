#include "Tetravex.h"

Tetravex::Tetravex(vector<vector<int>> data)
{
    this->gameTable = *new GameTable(data[0][0], data[0][1]);
    for (int i=1; i<int(data.size()); i++){
        GameCard *card = new GameCard(data[i]);
        this->listCard.push_back(card);
    }
}

bool Tetravex::putCard(GameCard *card, int row, int column)
{
    if (card->getIsUsed())
    {
        return false;
    }
    else
    {
        if (this->gameTable.isCaseAvaileble(row, column))
        {
            if (!this->gameTable.isMatchWithTop(card, row, column))
            {
                return false;
            }
            else if (!this->gameTable.isMatchWithBottom(card, row, column))
            {
                return false;
            }
            else if (!this->gameTable.isMatchWithLeft(card, row, column))
            {
                return false;
            }
            else if (!this->gameTable.isMatchWithRight(card, row, column))
            {
                return false;
            }
            else
            {
                this->gameTable.putCard(card, row, column);
                card->setIsUsed(true);
                return true;
            }
        }
        else
        {
            cout << "row: " << row << " col: " << column << endl;
            cout << "position not available! " << endl;
            return false;
        }
    }
}

void Tetravex::removeCard(int row, int column)
{
    this->gameTable.getTable()[row][column]->setIsUsed(false);
    this->gameTable.removeCard(row, column);
}

GameTable Tetravex::getGameTable()
{
    return this->gameTable;
}

vector<GameCard *> Tetravex::getListCard()
{
    return this->listCard;
}

void Tetravex::resetGameTable()
{
    for (int i = 0; i < int(this->gameTable.getTable().size()); i++)
    {
        for (int j = 0; j < int(this->gameTable.getTable()[i].size()); j++)
        {
            if (this->gameTable.getTable()[i][j] != 0)
            {
                this->removeCard(i, j);
            }
        }
    }
}