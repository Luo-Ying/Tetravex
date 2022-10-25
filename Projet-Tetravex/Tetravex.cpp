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
            // cout << "coucou" << endl;
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] != ' ')
                {
                    lineData.push_back(line[i] - '0');
                }
            }
            GameCard *card = new GameCard(lineData);
            // cout << card->GetBottom() << endl;
            // cout << card->GetLeft() << endl;
            // cout << card->GetRight() << endl;
            // cout << card->GetTop() << endl;
            this->listCard.push_back(*card);
        }
        // for (int i = 0; i < lineData.size(); i++)
        // {
        //     cout << lineData[i] << ' ';
        // }
        // cout << "next line" << endl;
    }
    ReadFile.close();
    // for (int i = 0; i < this->listCard.size(); i++)
    // {
    //     cout << this->listCard[i].GetBottom() << ' '
    //          << this->listCard[i].GetLeft() << ' '
    //          << this->listCard[i].GetRight() << ' '
    //          << this->listCard[i].GetTop() << endl;
    // }
}