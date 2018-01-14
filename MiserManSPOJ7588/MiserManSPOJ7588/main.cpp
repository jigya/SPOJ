//
//  main.cpp
//  MiserManSPOJ7588
//
//  Created by Jigya Yadav on 13/08/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <sstream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    int n,m,i,j,k,a,b,c;
    scanf("%d%d",&n,&m);
    vector< vector<int> > arr(n+1, vector<int>(m+1, 0));
    for(i=0;i<m;i++)
    {
        scanf("%d",&arr[0][i]);
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&k);
            a=b=c=INT_MAX;
            if(j-1>=0)
                a=k+arr[i-1][j-1];
            b=k+arr[i-1][j];
            if(j+1<m)
                c=k+arr[i-1][j+1];
            arr[i][j]=min(a,min(b,c));
        }
    }
    int minCost=INT_MAX;
    for(i=0;i<m;i++)
    {
        minCost=min(minCost, arr[n-1][i]);
    }
    printf("%d\n",minCost);
    return 0;
}

