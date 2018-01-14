//
//  main.cpp
//  SUMFOURSPOJ1296
//
//  Created by Jigya Yadav on 28/08/14.
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
    int n,i,j,a1,a2,a3,a4,cnt=0;
    scanf("%d",&n);
    vector<int> arr1,arr2,arr3,arr4;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
        arr1.push_back(a1);
        arr2.push_back(a2);
        arr3.push_back(a3);
        arr4.push_back(a4);
    }
    vector<int> w1, w2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            w1.push_back(arr1[i]+arr2[j]);
            w2.push_back(arr3[i]+arr4[j]);
        }
    }
    sort(w2.begin(), w2.end());
    for(i=0;i<w1.size();i++)
    {
        if(binary_search(w2.begin(), w2.end(), -1*w1[i]))
           {
               cnt+=(upper_bound(w2.begin(), w2.end(), -1*w1[i]))-lower_bound(w2.begin(),w2.end(),-1*w1[i]);
           }
    }
    printf("%d\n",cnt);
    return 0;
}

