//
//  main.cpp
//  ETFSPOJ4141
//
//  Created by Jigya Yadav on 25/08/14.
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
    int t,n,i,rslt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        rslt=n;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                rslt-=rslt/i;
            }
            while(n%i==0)
                n/=i;
        }
        if(n>1)
            rslt-=rslt/n;
        printf("%d\n",rslt);
    }
    return 0;
}

