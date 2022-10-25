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
    // for (int i = 0; i < this->gameTable.getTable().size(); i++)
    // {
    //     for (int j = 0; j < this->gameTable.getTable()[i].size(); j++)
    //     {
    //         cout << this->gameTable.getTable()[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << this->gameTable.isCaseAvaileble(0, 0) << endl;
}