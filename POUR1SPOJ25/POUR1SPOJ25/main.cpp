//
//  main.cpp
//  POUR1SPOJ25
//
//  Created by Jigya Yadav on 25/09/14.
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
    int t, i, j, k, a, b, c;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &a, &b, &c);
        int ans;
        if(a < c && b < c)
        {
            ans = -1;
        }
        else if(a == c || b == c)
        {
            ans = 1;
        }
        else if(abs(a-b) > c)
        {
            ans = -1;
        }
        else if(abs(a-b) == c)
        {
            ans = 2;
        }
        else if(c%abs(a-b)==0)
        {
            ans = 3*(c/abs(a-b));
        }
        else
        {
            ans = -1;
        }
        printf("%d\n", ans);
    }
    return 0;
}

