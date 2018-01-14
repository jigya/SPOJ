//
//  main.cpp
//  PEBBLESPOJ7668
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
    int i, j, k, m, n, p, q, t;
    t = 1;
    string str;
    while (cin >> str)
    {
        printf("Game #%d: ", t);
        int numOfOnes = 0;
        int numOfSwaps = 0;
        for (i = 0; i < str.length(); i++)
        {
            if (str[i] == '1' && (numOfSwaps&1) == 0)
            {
                numOfSwaps++;
            }
            else if (str[i] == '0' && (numOfSwaps&1))
            {
                numOfSwaps++;
            }
        }
        printf("%d\n", numOfSwaps);
        t++;
    }
    return 0;
}

