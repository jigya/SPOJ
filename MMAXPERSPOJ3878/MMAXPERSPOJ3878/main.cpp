//
//  main.cpp
//  MMAXPERSPOJ3878
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

using namespace std;

int main(int argc, const char * argv[])
{
    int i, n, a, b, j;
    scanf("%d", &n);
    pair<int, int> edges[1010];
    int maxPerimeter[2][1010];
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        edges[i]= make_pair(a, b);
    }
    maxPerimeter[0][0] = edges[0].second;
    maxPerimeter[1][0] = edges[0].first;
    for (i = 1; i < n; i++)
    {
        maxPerimeter[0][i] = max(maxPerimeter[0][i-1]+edges[i].second+abs(edges[i].first - edges[i-1].first), maxPerimeter[1][i-1]+edges[i].second+abs(edges[i].first - edges[i-1].second));
        maxPerimeter[1][i] = max(maxPerimeter[0][i-1]+edges[i].first+abs(edges[i].second - edges[i-1].first), maxPerimeter[1][i-1]+edges[i].first+abs(edges[i].second - edges[i-1].second));
    }
//    for(i = 0; i < 2; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            cout << maxPerimeter[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<max(maxPerimeter[0][n-1], maxPerimeter[1][n-1])<<endl;
    return 0;
}

