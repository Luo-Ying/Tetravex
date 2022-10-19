#include <iostream>
#include <vector>

using namespace std;

vector<int> addition2Vectors(vector<int> v1, vector<int> v2)
{
    vector<int> vResult = v1;
    int sum = 0;
    for (int i = 0; i < v2.size(); i++)
    {
        for (int j = 0; j < v2.size(); j++)
        {
            vResult[i][j] += v2[i][j];
        }
    }
    return vResult;
}

int main()
{
    vector<int> v1 = {{2, 2, 1}, {1, 5, 0}, {0, 0, 1}};
    vector<int> v2 = {{5, 7, 1}, {0, 3, 0}, {1, 0, 8}};
    vector<int> vResult = addition2Vectors(v1, v2);
    for (int i = 0; i < vResult.size(); i++)
    {
        for (int j = 0; j < vResult.size(); j++)
        {
            cout << vResult[i][j] << " ";
        }
        cout << endl;
    }
}