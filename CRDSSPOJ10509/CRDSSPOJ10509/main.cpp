//
//  main.cpp
//  CRDSSPOJ10509
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
#include <cmath>
#include <stack>

using namespace std;

#define MOD 1000007

class ExtendedGCDVals
{
public:
    int d,a,b;
};


ExtendedGCDVals extendedGCD(int x, int y)
{
    ExtendedGCDVals p;
    if(y==0)
    {
        p.d=x;
        p.a=1;
        p.b=0;
    }
    else
    {
        ExtendedGCDVals t=extendedGCD(y, x%y);
        p.d=t.d;
        p.a=t.b;
        p.b=t.a-(x/y)*t.b;
    }
    return p;
}

long long int int_mod(long long int a, long long int b)
{
    return (a % b + b) % b;
}

int main(int argc, const char * argv[])
{
    int t,i,j,k,n;
    long long int rslt;
    int inverseMod2=extendedGCD(2, MOD).a+MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        rslt=int_mod(((long long int)n*n),MOD);
        rslt=int_mod((int_mod(rslt,MOD)+int_mod(n,MOD)),MOD);
        rslt=int_mod((3*rslt),MOD);
        rslt=int_mod((inverseMod2*rslt),MOD);
        rslt=int_mod((rslt-n),MOD);
        printf("%lld\n",rslt);
    }
    return 0;
}

