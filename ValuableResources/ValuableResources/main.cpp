//
//  main.cpp
//  ValuableResources
//
//  Created by Jigya Yadav on 05/11/14.
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
    int i, j, k, m, n, xmin = INT_MAX, xmax = INT_MIN, ymin = INT_MAX, ymax = INT_MIN;
    long long int xlen, ylen, area, side;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &j, &k);
        xmin = min(xmin, j);
        xmax = max(xmax, j);
        ymin = min(ymin, k);
        ymax = max(ymax, k);
    }
    xlen = (ll)xmax - xmin;
    ylen = (ll)ymax - ymin;
    side = max(xlen, ylen);
    area = side*side;
    cout<<area<<endl;
    return 0;
}

