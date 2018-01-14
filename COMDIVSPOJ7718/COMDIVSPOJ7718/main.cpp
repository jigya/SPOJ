//
//  main.cpp
//  COMDIVSPOJ7718
//
//  Created by Jigya Yadav on 03/09/14.
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

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b, a%b);
}


int main(int argc, const char * argv[])
{
    int t,i,j,k,a,b;
    scanf("%d",&t);
    int numDiv, currDiv;
    while (t--)
    {
        scanf("%d%d",&a,&b);
        j=gcd(a, b);
        numDiv=1;
        for(i=2;i*i<=j;i++)
        {
            if(j%i==0)
            {
                currDiv=1;
                while(j%i==0)
                {
                    j/=i;
                    currDiv++;
                }
                numDiv*=currDiv;
            }
        }
        if(j!=1)
        {
            numDiv*=2;
        }
        printf("%d\n",numDiv);
    }
    return 0;
}

