//
//  main.cpp
//  CADYDISTSPOJ10442
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
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    int n,i,j,k,m;
    scanf("%d",&n);
    while(n!=0)
    {
        vector<int> arr1,arr2;
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            arr1.push_back(j);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            arr2.push_back(j);
        }
        sort(arr1.begin(), arr1.end(), greater<int>());
        sort(arr2.begin(), arr2.end());
        long long int ans=0;
        for(i=0;i<n;i++)
        {
            ans+=arr1[i]*(long long int)arr2[i];
        }
        printf("%lld\n",ans);
        scanf("%d",&n);
    }
    return 0;
}

