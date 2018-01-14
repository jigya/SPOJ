//
//  main.cpp
//  AE1BSPOJ4301
//
//  Created by Jigya Yadav on 07/11/14.
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

using namespace std;

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t, s;
    int arr[1010];
    scanf("%d %d %d", &n, &k, &s);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n, greater<int>());
    int screwsneeded = k*s;
    i = 0;
    m = 0;
    while (screwsneeded > 0)
    {
        screwsneeded -= arr[i];
        m++;
        i++;
    }
    printf("%d\n", m);
    return 0;
}

