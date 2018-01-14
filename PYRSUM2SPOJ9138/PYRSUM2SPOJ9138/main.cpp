//
//  main.cpp
//  PYRSUM2SPOJ9138
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
#define ll long long int
#define maxcol 1000010

using namespace std;

long long int b1[1000100];
long long int b2[1000100];


void updateb1(int p, ll val, int maxval)
{
    for (; p <= maxval; p += (p & -p))
    {
        b1[p] += val;
    }
}

void updateb2(int p, ll val, int maxval)
{
    for (; p <= maxval; p += (p & -p))
    {
        b2[p] += val;
    }
}

void update(int a, int b, ll val, int maxval)
{
    updateb1(a, val, maxval);
    updateb1(b+1, -val, maxval);
    updateb2(a, val*(a-1), maxval);
    updateb2(b+1, -val * b, maxval);
}

long long int query1(int b, int choice)
{
    long long int sum = 0;
    for (; b > 0; b -= (b & -b))
    {
        if (choice == 1)
        {
            sum += b1[b];
        }
        else
        {
            sum += b2[b];
        }
    }
    return sum;
}

ll query2(int b)
{
    return (query1(b, 1)*b - query1(b, 2));
}

ll query(int a, int b)
{
    return query2(b)-query2(a-1);
}


int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t, l, r, center;
    scanf("%d", &n);
    char str[100];
    while (n--)
    {
        scanf("%s", str);
        scanf("%d", &l);
        scanf("%d", &r);
        if (strcmp(str, "build") == 0)
        {
            ll w = ((ll)(r+1)/2)*((ll)(r+1)/2);
            i = l - w/2;
            j = l + w/2;
            update(i, j, w, maxcol);
        }
        else
        {
            printf("%lld\n", query(l, r));
        }
    }
    return 0;
}

