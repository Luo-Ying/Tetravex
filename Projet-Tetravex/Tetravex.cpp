#include "Tetravex.h"

Tetravex::Tetravex(string nameFile)
{
    string line;
    ifstream ReadFile("data.txt");
    while (getline(ReadFile, line))
    {
        vector<int> lineData;
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != ' ')
            {
                lineData.push_back(line[i] - '0');
            }
        }
        this->data.push_back(lineData);
    }
    ReadFile.close();
    // for (int i = 0; i < this->data.size(); i++)
    // {
    //     for (int j = 0; j < this->data[i].size(); j++)
    //     {
    //         cout << data[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    this->gameTable = GameTable(this->data[0]);
    for (int i = 1; i < this.data.size(); i++)
    {
        GameCard gameCard = GameCard(this.data[i]);
        this->listCard.push_back(gameCard);
    }
    for (int i = 0; i < this->data.size(); i++)
    {
        cout << "left: " << listCard[i].getLeft() << " ";
        cout << "right: " << listCard[i].getRight() << " ";
        cout << "top: " << listCard[i].getTop() << " ";
        cout << "bottom: " << listCard[i].getBottom() << " ";
        cout << endl;
    }
}