//
//  main.cpp
//  BUSYMANSPOJ11515
//
//  Created by Jigya Yadav on 04/11/14.
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

int main(int argc, const char * argv[])
{
    int i, j, k, n, t;
    int lastFinishingTime;
    scanf("%d", &t);
    pair<int, int> times[100010];
    while (t--)
    {
        int cnt = 0;
        lastFinishingTime = -1;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d %d", &j, &k);
            times[i] = make_pair(k, j);
        }
        sort(times, times+n);
        for (i = 0; i < n; i++)
        {
            if (times[i].second >= lastFinishingTime)
            {
                cnt++;
                lastFinishingTime = times[i].first;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

