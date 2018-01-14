//
//  main.cpp
//  MRECAMANSPOJ3934
//
//  Created by Jigya Yadav on 24/08/14.
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
    int i,j,k,n,t;
    long long int m;
    map<long long int,int> hm;
    vector<long long int> arr;
    arr.push_back(0);
    for(i=1;i<=500005;i++)
    {
        m=arr[i-1]-i;
        if(m>0)
        {
            if(hm.find(m)!=hm.end())
            {
                m=arr[i-1]+i;
            }
        }
        else
        {
            m=arr[i-1]+i;
        }
        hm[m]=1;
        arr.push_back(m);
    }
    scanf("%d",&t);
    while(t!=-1)
    {
        printf("%lld\n",arr[t]);
        scanf("%d",&t);
    }
    return 0;
}

