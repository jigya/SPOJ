//
//  main.cpp
//  BOMARBLESPOJ6694
//
//  Created by Jigya Yadav on 25/12/14.
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
    ll numMarbles;
    ll count;
    int g, i, j, k, m, n, t;
    scanf("%d", &g);
    while (g != 0)
    {
        numMarbles = 5;
        count = 5;
        for (i = 2; i <= g; i++)
        {
            numMarbles += count + 2;
            count += 3;
        }
        printf("%lld\n", numMarbles);
        scanf("%d", &g);
    }
    return 0;
}

