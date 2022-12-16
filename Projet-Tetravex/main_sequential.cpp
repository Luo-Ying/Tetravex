#include "Tetravex.h"

Tetravex tetravex;
vector<GameCard> cards;

// bool *isFinished = new bool;

int width, height;

vector<vector<int>> readFile()
{
    vector<vector<int>> data;
    int choix;
    string filename;
    string line;
    cout << "Entrez votre choix pour la taille de data: " << endl;
    cout << "1 - 5x5" << endl;
    cout << "2 - 6x6" << endl;
    cout << "3 - 7x7" << endl;
    cout << "4 - 8x8" << endl;
    cin >> choix;
    if (choix == 1)
    {
        filename = "data_5x5.txt";
        width = 5;
        height = 5;
    }
    else if (choix == 2)
    {
        filename = "data_6x6.txt";
        width = 6;
        height = 6;
    }
    else if (choix == 3)
    {
        filename = "data_7x7.txt";
        width = 7;
        height = 7;
    }
    else if (choix == 4)
    {
        filename = "data_8x8.txt";
        width = 8;
        height = 8;
    }
    ifstream ReadFile(filename);
    while (getline(ReadFile, line))
    {
        vector<int> lineData;
        for (int i = 0; i < int(line.length()); i++)
        {
            if (line[i] != ' ')
            {
                lineData.push_back(line[i] - '0');
            }
        }
        data.push_back(lineData);
    }
    ReadFile.close();
    return data;
}

bool playGame(int row, int col)
{
    for (int i = 0; i < int(cards.size()); i++)
    {
        if (tetravex.putCard(&cards[i], row, col))
        {
            if (col < width - 1)
            {
                bool isPlaced = playGame(row, col + 1);
                if (!isPlaced)
                {
                    tetravex.removeCard(row, col);
                }
                else
                {
                    return true;
                }
            }
            else
            {
                if (row < height - 1)
                {
                    bool isPlaced = playGame(row + 1, 0);
                    if (!isPlaced)
                    {
                        tetravex.removeCard(row, col);
                    }
                    else
                    {
                        return true;
                    }
                }
                else
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    // *isFinished = false;

    vector<vector<int>> data = readFile();

    tetravex = Tetravex(data);

    for (int i = 0; i < int(tetravex.getListCard().size()); i++)
    {
        cards.push_back(*tetravex.getListCard()[i]);
    }

    cout << "resultat en séquenciel: " << endl;

    auto start = high_resolution_clock::now();

    playGame(0, 0);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Le temps pris par la fonction: " << (double)duration.count() / (double)1000000 << " secondes" << endl;

    return 0;
}