#include <iostream>
#include <vector>
#include <thread>

using namespace std;

vector<int> initTab(int n)
{
    vector<int> T;
    cout << "Enter " << n << " chiffre into the tab: " << endl;
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        T.push_back(e);
    }
    return T;
}

int sumTab(vector<int> T)
{
    int sum = 0;
    for (int i = 0; i < T.size(); i++)
    {
        sum += T[i];
    }
    return sum;
}

vector<vector<int>> divideSubTab(int m, vector<int> T)
{
    vector<vector<int>> tab;
    int size = T.size() / m;
    int rest = T.size() % m;
    vector<int> tSize;
    for (int i = 0; i < m; i++)
    {
        tSize.push_back(size);
    }
    if (rest != 0)
    {
        int s = 0;
        for (int i = 0; i < rest; i++)
        {
            tSize[s] += 1;
            s++;
        }
    }
    int index = 0, s = 0;
    for (int i = 0; i < m; i++)
    {
        vector<int> t;
        for (int j = 0; j < tSize[s]; j++)
        {
            t.push_back(T[index]);
            index++;
        }
        tab.push_back(t);
        s++;
    }
    return tab;
}

int main()
{
    int n, m, somme = 0;
    cout << "Give the size of tab: ";
    cin >> n;
    vector<int> T = initTab(n);
    cout << "tab T: ";
    for (int i = 0; i < n; i++)
    {
        cout << T[i] << " ";
    }
    cout << endl;
    int sum = sumTab(T);
    cout << "The sum of all elements of tab is: " << sum << endl;
    cout << "Enter the number of tabs you want divide to: ";
    cin >> m;
    vector<vector<int>> tab = divideSubTab(m, T);
    for (int i = 0; i < tab.size(); i++)
    {
        for (int j = 0; j < tab[i].size(); j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;

    /** en utilisant variable locale */
    cout << "en utilisant variable locale ----------- " << endl;
    vector<thread> pool1;
    for (int i = 0; i < tab.size(); i++)
    {
        pool1.push_back(thread([tab, i]()
                               {
                                   int sommeSubtab = 0;
                                   sommeSubtab += sumTab(tab[i]);
                                   cout << "resultat sous tab " << i << ": " << sommeSubtab << endl;
                               }));
    }
    for (thread &t : pool1)
    {
        t.join();
    }
    cout << endl
         << endl;

    /**en utilisant variable partagé*/
    cout << "en utilisant variable partagé ----------- " << endl;
    vector<thread> pool2;
    for (int i = 0; i < tab.size(); i++)
    {
        pool2.push_back(thread([tab, i, &somme]()
                               { somme += sumTab(tab[i]); }));
    }
    for (thread &t : pool2)
    {
        t.join();
    }
    cout << "resultat = " << somme << endl;
}