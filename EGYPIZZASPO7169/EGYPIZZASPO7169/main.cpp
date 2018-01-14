//
//  main.cpp
//  EGYPIZZASPO7169
//
//  Created by Jigya Yadav on 17/08/14.
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
    int n,i,j,k;
    string str;
    int pizza=1, num14=0, num12=0, num34=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cin>>str;
        if(str=="1/4")
        {
            num14++;
        }
        else if(str=="1/2")
        {
            num12++;
        }
        else
        {
            num34++;
        }
    }
    pizza+=num34;
    num14-=min(num34, num14);
    pizza+=num12/2;
    num12=num12%2;
    if(num12==0)
    {
        pizza+=num14/4;
        if(num14%4!=0)
        {
            pizza++;
        }
    }
    else if (num12==1)
    {
        if(num14>=2)
        {
            num12=0;
            num14-=2;
            pizza++;
            pizza+=num14/4;
            if(num14%4!=0)
            {
                pizza++;
            }
        }
        else
        {
            num12=0;
            num14=0;
            pizza++;
        }
    }
    printf("%d\n",pizza);
    return 0;
}

