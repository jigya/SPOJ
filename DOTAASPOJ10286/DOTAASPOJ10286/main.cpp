//
//  main.cpp
//  DOTAASPOJ10286
//
//  Created by Jigya Yadav on 28/08/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[])
{
    int i,j,k,m,n,t,d,cnt;
    scanf("%d",&t);
    while (t--)
    {
        cnt=0; 
        vector<int> health;
        scanf("%d%d%d",&n, &m, &d);
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            health.push_back(j);
        }
        sort(health.begin(), health.end());
        for(i=n-1;i>=0;i--)
        {
            while ((health[i]-d)>0)
            {
                health[i]-=d;
                cnt++;
            }
        }
        if(cnt>=m)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

