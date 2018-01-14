//
//  main.cpp
//  CHOCOLASPOJ247
//
//  Created by Jigya Yadav on 05/09/14.
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
#include <queue>

using namespace std;

int main(int argc, const char * argv[])
{
    int i,j,m,n,t, horizontalParts, verticalParts;
    scanf("%d",&t);
    while (t--)
    {
        horizontalParts=verticalParts=1;
        // 1 is vertical, 2 is horizontal
        priority_queue< pair<int, int> > pq;
        scanf("%d%d",&m, &n);
        for(i=1;i<=m-1;i++)
        {
            scanf("%d",&j);
            pq.push(make_pair(j, 1));
        }
        for(i=1;i<=n-1;i++)
        {
            scanf("%d",&j);
            pq.push(make_pair(j, 2));
        }
        long long int cost=0;
        while(!pq.empty())
        {
            pair<int, int> a=pq.top();
            pq.pop();
            if(a.second==1)
            {
                verticalParts++;
                cost+=(horizontalParts*a.first);
            }
            else
            {
                horizontalParts++;
                cost+=(verticalParts*a.first);
            }
        }
        printf("%lld\n",cost);
    }
    return 0;
}

