#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <queue>
#include <condition_variable>
#include <mutex>

using namespace std;

// atomic<string> output;
string output;
mutex m;
queue<function<void()>> job_queue1;
queue<function<void()>> job_queue2;
queue<function<void()>> job_queue3;
queue<function<void()>> job_queue4;
condition_variable cv;
condition_variable cv1;
condition_variable cv2;
condition_variable cv3;
condition_variable cv4;
vector<thread> thread_pool1;
vector<thread> thread_pool2;
vector<thread> thread_pool3;
vector<thread> thread_pool4;

string switchCharacter(int num)
{
    switch (num)
    {
    case 0: return "zéro";
    case 1: return "un";
    case 2: return "deux";
    case 3: return "trois";
    case 4: return "quatre";
    case 5: return "cinq";
    case 6: return "six";
    case 7: return "sept";
    case 8: return "huit";
    case 9: return "neuf";
    case 10: return "dix";
    case 11: return "onze";
    case 12: return "douze";
    case 13: return "treize";
    case 14: return "quatorze";
    case 15: return "quinze";
    case 16: return "seize";
    case 20: return "vingt";
    case 30: return "trente";
    case 40: return "quarante";
    case 50: return "cinquant";
    case 60: return "soixante";
    case 100: return "cent";
    case 1000: return "mille";
    default: return "";
    }
}

vector<string> stringToVector(string input)
{
    vector<string> tokens;
    string token = "";
    for (int i = 0; i < input.length(); i++)
    {
        job_queue1.push([input, i, &token, &tokens](){
            if (input[i] != ' ')
            {
                token += input[i];
            }
            else
            {
                tokens.push_back(token);
                token = "";
            }
        });
        cv1.notify_one();
    }
    return tokens;
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

string int10(int num) {
    string strNum = "";
    if (num < 17) { strNum += switchCharacter(num); }
    else { 
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
    strNum += int10(num-60);
    return strNum;
}

string int80(int num)
{
    string strNum = "";
    strNum += switchCharacter(4);
    strNum += "-";
    strNum += switchCharacter(20);
    if (num - 80 != 0) {
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
        if (num % 10 != 0) { 
            strNum += switchCharacter(num/10);
            strNum += "-";
            strNum += switchCharacter(num % 10);
        }
    }
    return strNum;
}

string len3(int num)
{
    // int num = stoi(str);
    string strNum = "";
    if (num / 100 == 1) {
        strNum += switchCharacter(100);
    } else {
        strNum += switchCharacter(num / 100);
        strNum += ' ';
        strNum += switchCharacter(100);
    }
    strNum += ' ';
    int rest = num - ((num / 100) * 100);
    if (rest > 0 && rest <= 9) { strNum += switchCharacter(rest); }
    else if (rest > 9) { strNum += len2(rest); }
    return strNum;
}

string len4(int num) {
    string strNum = "";
    if (num / 1000 == 1) {
        strNum += switchCharacter(1000);
    } else {
        strNum += switchCharacter(num / 1000);
        strNum += ' ';
        strNum += switchCharacter(1000);
    }
    strNum += ' ';
    int rest = num - (num / 1000) * 1000;
    if ( rest > 0 && rest <= 99 ) { strNum += len2(rest); }
    else if ( rest > 99) { strNum += len3(rest); }
    return strNum;
}

string numToCharacter(string num)
{
    int len = num.length();
    string strNum = "";
    if (len == 1) { strNum += switchCharacter(stoi(num)); }
    else if (len == 2) { strNum += len2(stoi(num)); }
    else if (len == 3) { strNum += len3(stoi(num)); }
    else if (len == 4) { strNum += len4(stoi(num)); }
    return strNum;
}

void normalization(string input)
{
    vector<string> tokens = stringToVector(input);
    // string output = "";
    for (int i = 0; i < tokens.size(); i++)
    {
        for (int j = 0; j < tokens[i].length(); j++)
        {
            if (!islower(tokens[i][j]))
            {
                job_queue2.push([&tokens, i, j](){
                    if (isupper(tokens[i][j]))
                    {
                        tokens[i][j] = tolower(tokens[i][j]);
                    }
                });
                cv2.notify_one();
                job_queue3.push([&tokens, i, j](){
                    if (!isalnum(tokens[i][j]) && int(tokens[i][j]) > 0)
                    {
                        tokens[i].erase(remove(tokens[i].begin(), tokens[i].end(), tokens[i][j]), tokens[i].end());
                    }
                });
                cv3.notify_one();
            }
        }
        // for (int j = 0; j < tokens[i].length(); j++) {
        //     if (!isalnum(tokens[i][j]) && int(tokens[i][j]) > 0)
        //     {
        //         tokens[i].erase(remove(tokens[i].begin(), tokens[i].end(), tokens[i][j]), tokens[i].end());
        //     }
        // }
        job_queue4.push([&tokens, i](){
            if (isNumber(tokens[i]))
            {
                // cout << numToCharacter(tokens[i]) << endl;
                tokens[i] = numToCharacter(tokens[i]);
            }
        });
        cv4.notify_one();
        output += tokens[i];
        output += " ";
        cout << "output: " << output << endl;
        cout << "token[" << i << "]: " << tokens[i] << endl; 
    }
    for (int i = 0; i < tokens.size(); i++)
    {
        output += tokens[i];
        output += " ";
    }
    // return output;
}

void execute(int k) {
    for (int i=0; i<k; i++) {
        thread_pool1.push_back(
            thread([](){
                while(true) {
                    unique_lock<mutex> lk1(m);
                    cv1.wait(lk1, [&]{ return !job_queue1.empty(); });
                    function<void()> f = job_queue1.front();
                    job_queue1.pop();
                    lk1.lock();
                    f();
                    lk1.unlock();
                    cv.notify_one();
                }
            })
        );
        thread_pool2.push_back(
            thread([](){
                while(true) {
                    unique_lock<mutex> lk2(m);
                    cv2.wait(lk2, [&]{ return !job_queue2.empty(); });
                    function<void()> f = job_queue2.front();
                    job_queue2.pop();
                    lk2.lock();
                    f();
                    lk2.unlock();
                    cv.notify_one();
                }
            })
        );
        thread_pool3.push_back(
            thread([](){
                while(true) {
                    unique_lock<mutex> lk3(m);
                    cv3.wait(lk3, [&]{ return !job_queue3.empty(); });
                    function<void()> f = job_queue3.front();
                    job_queue3.pop();
                    lk3.lock();
                    f();
                    lk3.unlock();
                    cv.notify_one();
                }
            })
        );
        thread_pool4.push_back(
            thread([](){
                while(true) {
                    unique_lock<mutex> lk4(m);
                    cv4.wait(lk4, [&]{ return !job_queue4.empty(); });
                    function<void()> f = job_queue4.front();
                    job_queue4.pop();
                    lk4.lock();
                    f();
                    lk4.unlock();
                    cv.notify_one();
                }
            })
        );
    }
}

int main()
{
    string input = " INFOS: le tournage du film les 101 dalmatiens a été fait à Avignon🙂️ ";
    execute(2);
    normalization(input);
    cout << output << endl;
    unique_lock<mutex> lk(m);
    cv.wait(lk, [&]{ return job_queue1.empty() || job_queue2.empty() || job_queue3.empty() || job_queue4.empty(); });
}