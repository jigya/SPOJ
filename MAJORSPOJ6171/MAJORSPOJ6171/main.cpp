//
//  main.cpp
//  MAJORSPOJ6171
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
#include <map>
#include <sstream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    int t,i,j,k,n,half;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        scanf("%d",&n);
        map<int, int> hm;
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            if(hm.find(k)==hm.end())
            {
                hm[k]=1;
            }
            else
            {
                hm[k]++;
            }
        }
        map<int, int>::iterator it;
        half=n/2;
        for(it=hm.begin();it!=hm.end();it++)
        {
            if(it->second>half)
            {
                printf("YES %d\n", it->first);
                break;
            }
        }
        if(it==hm.end())
        {
            printf("NO\n");
        }
    }
    return 0;
}

