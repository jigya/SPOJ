//
//  main.cpp
//  RPLCSPOJ11373
//
//  Created by Jigya Yadav on 02/09/14.
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
    int t,n,i,j,s;
    scanf("%d",&t);
    long long int sum;
    long long int minSum=1;
    for(s=1;s<=t;s++)
    {
        sum=1;
        minSum=1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            sum+=j;
            cout<<sum<<endl;
            if(sum<=0)
            {
                minSum=max(1-sum,minSum);
            }
        }
        printf("Scenario #%d: %lld\n",s,minSum);
    }
    return 0;
}

