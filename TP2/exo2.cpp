#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <functional>

using namespace std;

mutex m;
queue<string> job0;
queue<string> job1;
queue<vector<string>> job2;
queue<vector<string>> job3;
vector<string> jobFinal;
condition_variable cv;
condition_variable cv0;
condition_variable cv1;
condition_variable cv2;
condition_variable cv3;
vector<thread> thread_pool1;
vector<thread> thread_pool2;
vector<thread> thread_pool3;
vector<thread> thread_pool4;

string switchCharacter(int num)
{
    switch (num)
    {
    case 0:
        return "zéro";
    case 1:
        return "un";
    case 2:
        return "deux";
    case 3:
        return "trois";
    case 4:
        return "quatre";
    case 5:
        return "cinq";
    case 6:
        return "six";
    case 7:
        return "sept";
    case 8:
        return "huit";
    case 9:
        return "neuf";
    case 10:
        return "dix";
    case 11:
        return "onze";
    case 12:
        return "douze";
    case 13:
        return "treize";
    case 14:
        return "quatorze";
    case 15:
        return "quinze";
    case 16:
        return "seize";
    case 20:
        return "vingt";
    case 30:
        return "trente";
    case 40:
        return "quarante";
    case 50:
        return "cinquant";
    case 60:
        return "soixante";
    case 100:
        return "cent";
    case 1000:
        return "mille";
    default:
        return "";
    }
}

bool isNumber(string str)
{
    for (char &c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

string int10(int num)
{
    string strNum = "";
    if (num < 17)
    {
        strNum += switchCharacter(num);
    }
    else
    {
        strNum += switchCharacter(10);
        strNum += "-";
        strNum += switchCharacter(num - 10);
    }
    return strNum;
}

string int70(int num)
{
    string strNum = "";
    strNum += switchCharacter(60);
    strNum += "-";
    strNum += int10(num - 60);
    return strNum;
}

string int80(int num)
{
    string strNum = "";
    strNum += switchCharacter(4);
    strNum += "-";
    strNum += switchCharacter(20);
    if (num - 80 != 0)
    {
        strNum += "-";
        strNum += switchCharacter(num - 80);
    }
    return strNum;
}

string int90(int num)
{
    string strNum = "";
    strNum += switchCharacter(4);
    strNum += "-";
    strNum += switchCharacter(20);
    strNum += "-";
    strNum += int10(num - 80);
    return strNum;
}

string len2(int num)
{
    string strNum = "";
    if (num / 10 == 1)
    {
        strNum += int10(num);
    }
    else if (num / 10 == 7)
    {
        strNum += int70(num);
    }
    else if (num / 10 == 8)
    {
        strNum += int80(num);
    }
    else if (num / 10 == 9)
    {
        strNum += int90(num);
    }
    else
    {
        if (num % 10 != 0)
        {
            strNum += switchCharacter(num / 10);
            strNum += "-";
            strNum += switchCharacter(num % 10);
        }
    }
    return strNum;
}

string len3(int num)
{
    string strNum = "";
    if (num / 100 == 1)
    {
        strNum += switchCharacter(100);
    }
    else
    {
        strNum += switchCharacter(num / 100);
        strNum += ' ';
        strNum += switchCharacter(100);
    }
    strNum += ' ';
    int rest = num - ((num / 100) * 100);
    if (rest > 0 && rest <= 9)
    {
        strNum += switchCharacter(rest);
    }
    else if (rest > 9)
    {
        strNum += len2(rest);
    }
    return strNum;
}

string len4(int num)
{
    string strNum = "";
    if (num / 1000 == 1)
    {
        strNum += switchCharacter(1000);
    }
    else
    {
        strNum += switchCharacter(num / 1000);
        strNum += ' ';
        strNum += switchCharacter(1000);
    }
    strNum += ' ';
    int rest = num - (num / 1000) * 1000;
    if (rest > 0 && rest <= 99)
    {
        strNum += len2(rest);
    }
    else if (rest > 99)
    {
        strNum += len3(rest);
    }
    return strNum;
}

string numToCharacter(string num)
{
    int len = num.length();
    string strNum = "";
    if (len == 1)
    {
        strNum += switchCharacter(stoi(num));
    }
    else if (len == 2)
    {
        strNum += len2(stoi(num));
    }
    else if (len == 3)
    {
        strNum += len3(stoi(num));
    }
    else if (len == 4)
    {
        strNum += len4(stoi(num));
    }
    return strNum;
}

void transformTolower()
{
    for (int i = 0; i < job0.size(); i++)
    {
        thread_pool1.push_back(thread([]()
                                      {
                                          unique_lock<mutex> lk(m);
                                          cv.wait(lk, [&]
                                                  { return !job0.empty(); });
                                          string job = job0.front();
                                          job0.pop();
                                          for (int ind = 0; ind < job.length(); ind++)
                                          {
                                              if (!islower(job[ind]))
                                              {
                                                  job[ind] = tolower(job[ind]);
                                              }
                                          }
                                          job1.push(job);
                                          cv.notify_one();
                                      }));
    }
}

void tokenizeText()
{
    for (int i = 0; i < job1.size(); i++)
    {
        // int c = 0;
        thread_pool2.push_back(thread([]()
                                      {
                                          unique_lock<mutex> lk(m);
                                          cv.wait(lk, [&]
                                                  { return !job1.empty(); });
                                          string tokens = job1.front();
                                          job1.pop();
                                          lk.unlock();
                                          vector<string> job;
                                          string token = "";
                                          for (int ind = 0; ind < tokens.length(); ind++)
                                          {
                                              if (tokens[ind] != ' ')
                                              {
                                                  token += tokens[ind];
                                              }
                                              else
                                              {
                                                  job.push_back(token);
                                                  token = "";
                                              }
                                          }
                                          job2.push(job);
                                          lk.lock();
                                          cv.notify_one();
                                      }));
    }
}

void eraseSpecialCharacter()
{
    for (int i = 0; i < job2.size(); i++)
    {
        thread_pool3.push_back(thread([]()
                                      {
                                          unique_lock<mutex> lk(m);
                                          cv.wait(lk, [&]
                                                  { return !job2.empty(); });
                                          vector<string> job = job2.front();
                                          for (int ind = 0; ind < job.size(); ind++)
                                          {
                                              for (int k = 0; k < job[ind].length(); k++)
                                              {
                                                  job[ind].erase(remove_if(job[ind].begin(), job[ind].end(),
                                                                           [](char c)
                                                                           { return ispunct(c); }),
                                                                 job[ind].end());
                                              }
                                          }
                                          job2.pop();
                                          job3.push(job);
                                          cv.notify_one();
                                      }));
    }
}

void changeNumToCharacter()
{
    for (int i = 0; i < job3.size(); i++)
    {
        thread_pool4.push_back(thread([]()
                                      {
                                          unique_lock<mutex> lk(m);
                                          cv.wait(lk, [&]
                                                  { return !job3.empty(); });
                                          vector<string> job = job3.front();
                                          job3.pop();
                                          for (int ind = 0; ind < job.size(); ind++)
                                          {
                                              if (isNumber(job[ind]))
                                              {
                                                  job[ind] = numToCharacter(job[ind]);
                                              }
                                          }
                                          string token = "";
                                          for (int k = 0; k < job.size(); k++)
                                          {
                                              token += job[k];
                                              token += " ";
                                          }
                                          jobFinal.push_back(token);
                                          cv.notify_one();
                                      }));
    }
}

void normalisation(int n)
{
    for (int i = 0; i < n; i++)
    {
        // cout << "couocu1" << endl;
        job0.push(" INFOS: le tournage du film les 101 dalmatiens a été fait à Avignon🙂️ ");
    }
    transformTolower();
    tokenizeText();
    eraseSpecialCharacter();
    changeNumToCharacter();
}

int main()
{
    int n = 4;
    normalisation(n);
    for (thread &t : thread_pool1)
    {
        t.join();
    }
    for (thread &t : thread_pool2)
    {
        t.join();
    }
    for (thread &t : thread_pool3)
    {
        t.join();
    }
    for (thread &t : thread_pool4)
    {
        t.join();
    }
    // unique_lock<mutex> lk2(m);
    // cv0.wait(lk2, [&]
    //          { return job0.empty() || job1.empty() || job2.empty() || job3.empty(); });
    for (int i = 0; i < jobFinal.size(); i++)
    {
        cout << jobFinal[i] << endl;
    }
}