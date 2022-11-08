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
            this->gameTable.putCard(this->listCard[itemCard], row, column);
            this->listCard[itemCard]->setIsUsed(true);
            return true;
        }
        else
        {
            cout << "position not available! ";
            return false;
        }
    }
}

GameTable Tetravex::getGameTable()
{
    return this->gameTable;
}

vector<GameCard *> Tetravex::getListCard()
{
    return this->listCard;
}