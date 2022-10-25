#include "Tetravex.h"

Tetravex::Tetravex(string nameFile)
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
            this->listCard.push_back(*card);
        }
    }
    ReadFile.close();
    // for (int i = 0; i < line.length(); i++)
    // {
    //     cout << this->listCard[i].getBottom() << ' '
    //          << this->listCard[i].getLeft() << ' '
    //          << this->listCard[i].getRight() << ' '
    //          << this->listCard[i].getTop() << ' '
    //          << "is used? " << this->listCard[i].getIsUsed() << endl;
    // }
}