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
            // cout << "nique?" << endl;
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
            cout << "coucou" << endl;
        }
        // this->data.push_back(lineData);
    }
    ReadFile.close();
    // for (int i = 0; i < this->data.size(); i++)
    // {
    //     for (int j = 0; j < this->data[i].size(); j++)
    //     {
    //         cout << this->data[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // this->gameTable = GameTable(this->data[0]);
    // for (int i = 1; i < this->data.size(); i++)
    // {
    //     GameCard gameCard = GameCard(this->data[i]);
    //     this->listCard.push_back(gameCard);
    // }
    // for (int i = 1; i < this->data.size(); i++)
    // {
    //     cout << "left: " << this->listCard[i]->getLeft() << " ";
    //     cout << "right: " << this->listCard[i]->getRight() << " ";
    //     cout << "top: " << this->listCard[i]->getTop() << " ";
    //     cout << "bottom: " << this->listCard[i]->getBottom() << " ";
    // }
    // cout << endl;
}