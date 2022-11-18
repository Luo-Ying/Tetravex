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
            for (int i = 0; i < int(line.length()); i++)
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
            for (int i = 0; i < int(line.length()); i++)
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