//
//  main.cpp
//  UPDATEITSPOJ16487
//
//  Created by Jigya Yadav on 21/12/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
#include<fstream>

using namespace std;

long long int arr[10100];

void update(int p, int val, int maxval)
{
    for (; p <= maxval; p+=(p & -p))
    {
        arr[p] += val;
    }
}

void updateRange(int a, int b, int val, int maxval)
{
    update(a, val, maxval);
    update(b+1, -val, maxval);
}

long long int query(int b)
{
    long long int sum = 0;
    for (; b > 0; b -= (b & -b))
    {
        sum += arr[b];
    }
    return  sum;
}

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t, u, l, r, val, q;
    scanf("%d", &t);
    while (t--)
    {
        memset(arr, 0, sizeof(arr));
        scanf("%d%d", &n, &u);
        while (u--)
        {
            scanf("%d %d %d", &l, &r, &val);
            updateRange(l+1, r+1, val, n+9);
        }
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d", &k);
            printf("%lld\n", query(k+1));
        }
    }
    return 0;
}

