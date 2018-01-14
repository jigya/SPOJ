//
//  main.cpp
//  ACPC11BSPOJ10239
//
//  Created by Jigya Yadav on 18/08/14.
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
#include <sstream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    int t,i,j,k, n1, n2;
    scanf("%d",&t);
    while(t--)
    {
        vector<int> arr1, arr2;
        scanf("%d",&n1);
        for(i=0;i<n1;i++)
        {
            scanf("%d",&k);
            arr1.push_back(k);
        }
        scanf("%d",&n2);
        for(i=0;i<n2;i++)
        {
            scanf("%d",&k);
            arr2.push_back(k);
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        i=j=0;
        int minDiff=INT_MAX;
        while(1)
        {
            if(i==n1 || j==n2)
                break;
            if(arr1[i]==arr2[j])
            {
                minDiff=0;
                break;
            }
            else if(arr1[i]<arr2[j])
            {
                minDiff=min(minDiff, arr2[j]-arr1[i]);
                i++;
            }
            else
            {
                minDiff=min(minDiff, arr1[i]-arr2[j]);
                j++;
            }
        }
        printf("%d\n",minDiff);
    }
    return 0;
}

