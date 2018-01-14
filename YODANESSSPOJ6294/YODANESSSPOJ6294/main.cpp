//
//  main.cpp
//  YODANESSSPOJ6294
//  http://www.quora.com/How-can-I-efficiently-compute-the-number-of-swaps-required-by-slow-sorting-methods-like-insertion-sort-and-bubble-sort-to-sort-a-given-array
//
//  Created by Jigya Yadav on 19/12/14.
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
char str[30];
char arr[30015][30];
int dr[30015];
int tree[30015] = {0};

void update(int idx ,int val, int maxVal)
{
	while (idx <= maxVal)
    {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int sum(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
	}
	return sum;
}



int countInversions(int n)
{
    int inv_cnt = 0;
    int i;
    memset(tree, 0, sizeof(tree));
    for (i = 0; i < n; i++)
    {
        inv_cnt += i-sum(dr[i] - 1);
        update(dr[i], 1, n+9);
    }
    return inv_cnt;
}

int main(int argc, const char * argv[])
{
    int t, i, k, m, n;
    scanf("%d", &t);
    map<string, int> hm;
    while (t--)
    {
        hm.clear();
        scanf("%d", &n);
        k = 1;
        for (i = 0; i < n; i++)
        {
            scanf("%s", arr[i]);
        }
        for (i = 1; i <= n; i++)
        {
            scanf("%s", str);
            hm.insert(make_pair(str, i));
        }
        for (i = 0; i < n; i++)
        {
            m = hm.find(arr[i])->second;
            dr[i] = m;
        }
        cout<<countInversions(n)<<endl;
    }
    return 0;
}

