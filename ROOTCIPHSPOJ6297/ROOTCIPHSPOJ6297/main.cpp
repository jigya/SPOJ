//
//  main.cpp
//  ROOTCIPHSPOJ6297
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
    int t;
    long long int rslt,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        rslt=a*a-2*b;
        printf("%lld\n",rslt);
    }
    return 0;
}

