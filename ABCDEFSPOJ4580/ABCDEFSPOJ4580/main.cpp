//
//  main.cpp
//  ABCDEFSPOJ4580
//
//  Created by Jigya Yadav on 29/08/14.
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
    int i,j,k,m,n,t;
    vector<int> arr;
    vector<int> arr1, arr2;
    scanf("%d",&n);
    for (i=0; i<n; i++)
    {
        scanf("%d",&j);
        arr.push_back(j);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(arr[i]!=0)
                    arr1.push_back((arr[j]+arr[k])*arr[i]);
            }
        }
    }
    int cnt=0;
    sort(arr1.begin(), arr1.end());
    pair< vector<int>::iterator, vector<int>::iterator > bounds;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                m=arr[i]*arr[j]+arr[k];
                if(binary_search(arr1.begin(), arr1.end(), m))
                {
                    bounds=equal_range(arr1.begin(), arr1.end(), m);
                    cnt+=(bounds.second-bounds.first);
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}

