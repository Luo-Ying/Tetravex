#include "Tetravex.h"

Tetravex::Tetravex(string fileName)
{
    string line;
    int numLine = 0;
    ifstream ReadFile("data.txt");
    while (getline(ReadFile, line))
    {
        numLine++;
        vector<int> lineData;
        if (numLine == 1)
        {
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] != ' ')
                {
                    lineData.push_back(line[i] - '0');
                }
            }
            this->gameTable = *new GameTable(lineData[0], lineData[1]);
        }
        else
        {
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] != ' ')
                {
                    lineData.push_back(line[i] - '0');
                }
            }
            GameCard *card = new GameCard(lineData);
            this->listCard.push_back(card);
        }
    }
    ReadFile.close();
}

bool Tetravex::putCard(int itemCard, int row, int column)
{
    if (this->listCard[itemCard]->getIsUsed())
    {
        cout << "card used! ";
        return false;
    }
    else
    {
        if (this->gameTable.isCaseAvaileble(row, column))
        {
            // cout << "coucou1" << endl;
            if (
                this->gameTable.isMatchWithTop(this->listCard[itemCard], row, column) &&
                this->gameTable.isMatchWithBottom(this->listCard[itemCard], row, column) &&
                this->gameTable.isMatchWithLeft(this->listCard[itemCard], row, column) &&
                this->gameTable.isMatchWithRight(this->listCard[itemCard], row, column))
            {
                // cout << "coucou" << endl;
                this->gameTable.putCard(this->listCard[itemCard], row, column);
                this->listCard[itemCard]->setIsUsed(true);
                return true;
            }
            else
            {
                // if (!this->gameTable.isMatchWithTop(this->listCard[itemCard], row, column))
                // {
                //     cout << "top of card is not matched! ";
                // }
                // if (!this->gameTable.isMatchWithBottom(this->listCard[itemCard], row, column))
                // {
                //     cout << "bottom of card is not matched! ";
                // }
                // if (!this->gameTable.isMatchWithLeft(this->listCard[itemCard], row, column))
                // {
                //     cout << "left of card is not matched! ";
                // }
                // if (!this->gameTable.isMatchWithRight(this->listCard[itemCard], row, column))
                // {
                //     cout << "right of card is not matched! ";
                // }
                return false;
            }
        }
        else
        {
            cout << "position not available! ";
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
    for (int i = 0; i < this->gameTable.getTable().size(); i++)
    {
        for (int j = 0; j < this->gameTable.getTable()[i].size(); j++)
        {
            if (this->gameTable.getTable()[i][j] != 0)
            {
                this->removeCard(i, j);
            }
        }
    }
}