//
//  main.cpp
//  MATSUMSPOJ1029
//
//  Created by Jigya Yadav on 17/12/14.
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

int n;

int tree[1100][1100];

void update(int x, int y, int num, int m)
{
    int y1;
    while (x <= m)
    {
        y1 = y;
        while (y1 <= m)
        {
            tree[x][y1] += num;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}


long long int sum(int x, int y)
{
    if (x <= 0 || y <= 0)
    {
        return 0;
    }
    int y1;
    long long int s = 0;
    while (x > 0)
    {
        y1 = y;
        while (y1 > 0)
        {
            s += tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return s;
}

int main()
{
    int t, x1, y1, x2, y2, num;
    int currValues[1100][1100];
    scanf("%d", &t);
    while (t!=3)
    {
        if (t == 0)
        {
            scanf("%d", &n);
            memset(currValues, 0, sizeof(currValues));
            memset(tree, 0, sizeof(tree));
        }
        else if(t == 1)
        {
            scanf("%d%d%d", &x1, &y1, &num);
            currValues[x1+1][y1+1] += num;
            update(x1+1, y1+1, num, n+9);
        }
        else if (t == 2)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            long long int val1 = sum(x1,y1);
            long long int val2 = sum(x2+1,y2+1);
            long long int val3 = sum(x1, y2+1);
            long long int val4 = sum(x2+1, y1);
            printf("%lld\n", val2+val1-val3-val4);
        }
        scanf("%d", &t);
    }
    return 0;
}

