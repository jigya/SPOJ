//
//  main.cpp
//  DIEHARDSPOJ12471
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

#define airy 0
#define watery 1
#define firey 2

using namespace std;


int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t, p, q;
    scanf("%d", &t);
    pair<int, int> air(3,2);
    pair<int, int> water(-5, -10);
    pair<int, int> fire(-20, 5);
    ll health, armor;
    ll cnt;
    while (t--)
    {
        scanf("%lld %lld", &health, &armor);
        cnt = 0;
        int currPlace = watery;
        while(1)
        {
            if(currPlace != airy)
            {
                health += air.first;
                armor += air.second;
                cnt++;
                currPlace = airy;
            }
            else
            {
                if (health+fire.first > 0)
                {
                    cnt++;
                    health += fire.first;
                    armor += fire.second;
                    currPlace = firey;
                }
                else if(health+water.first > 0 && armor+water.second > 0)
                {
                    cnt++;
                    health += water.first;
                    armor += water.second;
                    currPlace = watery;
                }
                else
                {
                    break;
                }
            }
        }
        printf("%lld\n", cnt);
    }
    return 0;
}

