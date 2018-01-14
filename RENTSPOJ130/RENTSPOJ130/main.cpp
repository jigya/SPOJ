//
//  main.cpp
//  RENTSPOJ130
//  Weighted Interval Scheduling
//  http://courses.cs.washington.edu/courses/cse521/13wi/slides/06dp-sched.pdf
//
//  Created by Jigya Yadav on 11/12/14.
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

bool comp(const pair< pair<int, int>, int> &a, const pair< pair<int, int>, int> &b)
{
    return (a.first.second < b.first.second) || (a.first.second == b.first.second && a.first.first < b.first.first);
}

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t, st, d, p;
    pair< pair<int, int>, int > arr[10100];
    int finishTimes[10100];
    int last[10100];
    int s[10100];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d%d%d", &st, &d, &p);
            arr[i] = make_pair(make_pair(st, st+d), p);
            finishTimes[i] = st+d;
        }
        sort(arr, arr+n, comp);
        sort(finishTimes, finishTimes+n);
        last[0] = 0;
        for (i = 1; i < n; i++)
        {
            last[i] = upper_bound(finishTimes, finishTimes+i, arr[i].first.first) - finishTimes-1;
        }
        s[0] = 0;
        s[1] = max(arr[0].second+s[0], s[0]);
        for (i = 2; i <= n; i++)
        {
            if (last[i-1] != -1)
            {
                s[i] = max(arr[i-1].second+s[last[i-1]+1], s[i-1]);
            }
            else
            {
                s[i] = max(s[i-1], arr[i-1].second);
            }
        }
        cout<<s[n]<<endl;
    }
    return 0;
}

