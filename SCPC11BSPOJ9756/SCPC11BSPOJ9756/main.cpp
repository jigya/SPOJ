//
//  main.cpp
//  SCPC11BSPOJ9756
//
//  Created by Jigya Yadav on 04/09/14.
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
    int n, i, j, forwardDist;
    scanf("%d",&n);
    while (n!=0)
    {
        bool flag=true;
        vector<int> arr;
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            arr.push_back(j);
        }
        sort(arr.begin(), arr.end());
        for(i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]>200)
            {
                flag=false;
            }
        }
        if((2*(1422-arr[n-1]))>200)
        {
            flag=false;
        }
        if (flag)
        {
            printf("POSSIBLE\n");
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
        scanf("%d",&n);
    }
    return 0;
}

