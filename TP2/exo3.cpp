#include <iostream>
#include "md5.h"
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

using namespace std;

int main()
{
    vector<thread> pool;
    mutex m;
    condition_variable cv;

    string secret = md5("salut");

    for (int i = 0; i < 26; i++)
    {
        pool.push_back(thread([secret, i]()
                              {
                                  string result = "";

                                  for (int j = 0; j < 26; j++)
                                  {
                                      for (int k = 0; k < 26; k++)
                                      {
                                          for (int l = 0; l < 26; l++)
                                          {
                                              for (int m = 0; m < 26; m++)
                                              {
                                                  result += i + 97;
                                                  result += j + 97;
                                                  result += k + 97;
                                                  result += l + 97;
                                                  result += m + 97;

                                                  if (md5(result) == secret)
                                                  {
                                                      cout << result << endl;
                                                      // break;
                                                      exit(0);
                                                  }
                                                  else
                                                  {
                                                      // cout << result << endl;
                                                      result = "";
                                                  }
                                              }
                                          }
                                      }
                                  }
                              }));
    }

    for (int i = 0; i < pool.size(); i++)
    {
        pool[i].join();
    }
    return 0;
}