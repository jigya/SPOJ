//
//  main.cpp
//  M3TILESPOJ3883
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
    int n, i;
    scanf("%d", &n);
    int d[35], a[35];
    d[0] = 1;
    d[1] = 0;
    d[2] = 3;
    a[0] = 1;
    a[1] = 1;
    a[2] = 0;
    for (i = 3; i <= 31; i++)
    {
        d[i] = d[i-2]+2*a[i-1];
        a[i] = d[i-1]+a[i-2];
    }
    while (n != -1)
    {
        printf("%d\n", d[n]);
        scanf("%d", &n);
    }
    return 0;
}

