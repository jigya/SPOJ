//
//  main.cpp
//  BINSTIRLSPOJ106
//
//  Created by Jigya Yadav on 24/09/14.
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
#include <queue>

using namespace std;

int main(int argc, const char * argv[])
{
    int d, i;
    long long int n, m, q;
    scanf("%d",&d);
    while (d--)
    {
        scanf("%lld%lld", &n, &m);
        q=(n-m)&((m-1)/2);
        if(q==0)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}

