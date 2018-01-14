//
//  main.cpp
//  HACKRNDMSPOJ9734
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
    long long int n, k, i, j;
    scanf("%lld%lld", &n, &k);
    vector<long long int> arr;
    map<long long int, long long int> hm;
    for (i = 1; i <= n; i++)
    {
        scanf("%lld", &j);
        arr.push_back(j);
        hm[j] = 1;
    }
    int cnt = 0;
    for (vector<long long int>::iterator itr = arr.begin(); itr!=arr.end(); itr++)
    {
        if(hm.count((*itr)+k) != 0)
        {
            cnt++;
        }
        if (hm.count((*itr)-k) != 0)
        {
            cnt++;
        }
    }
    printf("%d\n", cnt/2);
    return 0;
}

