//
//  main.cpp
//  AMR10GSPOJ8061
//
//  Created by Jigya Yadav on 26/08/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    int t,i,j,k,n;
    scanf("%d",&t);
    while(t--)
    {
        vector<int> arr;
        scanf("%d",&n);
        scanf("%d",&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            arr.push_back(j);
        }
        sort(arr.begin(), arr.end());
        int minDiff=INT_MAX;
        for(i=0;i<=n-k;i++)
        {
            minDiff=min(arr[i+k-1]-arr[i],minDiff);
        }
        printf("%d\n",minDiff);
    }
    return 0;
}

