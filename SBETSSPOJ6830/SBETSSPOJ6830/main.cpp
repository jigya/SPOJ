//
//  main.cpp
//  SBETSSPOJ6830
//
//  Created by Jigya Yadav on 24/12/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
#include<fstream>
#define ll long long int

using namespace std;

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t, p, q;
    string str1, str2;
    scanf("%d", &t);
    while (t--)
    {
        map<string, int> hm;
        for(i = 0 ;i < 16;i++)
        {
            cin >> str1 >> str2 >> p >> q;
            if (p > q)
            {
                if (hm.find(str1) == hm.end())
                {
                    hm[str1] = 1;
                }
                else
                {
                    hm[str1]++;
                }
            }
            else
            {
                if (hm.find(str2) == hm.end())
                {
                    hm[str2] = 1;
                }
                else
                {
                    hm[str2]++;
                }
            }
        }
        string winningTeam = "";
        for (map<string, int>::iterator itr = hm.begin(); itr != hm.end(); itr++)
        {
//            cout<<itr->first<<" "<<itr->second<<endl;
            if (itr -> second == 4)
            {
                winningTeam = itr->first;
            }
        }
        cout<<winningTeam<<endl;
    }
    return 0;
}

