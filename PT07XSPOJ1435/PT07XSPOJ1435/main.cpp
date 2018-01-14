
//
//  main.cpp
//  PT07XSPOJ1435
//
//  Created by Jigya Yadav on 03/11/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
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

vector<int> edges[100010];
bool selected[100010] = {false};
bool visited[100010] = {false};
int dp[100010][2] = {{0}};
void minVertexCover(int node, int par)
{
    visited[node] = true;
    if (edges[node].size() <= 1 && par != -1)
    {
        //cout<<node<<endl;
        dp[node][1] = 1;
        dp[node][0] = 0;
        return;
    }
    dp[node][1] = 1;
    dp[node][0] = 0;
    //cout<<root<<endl;
    for (vector<int>::iterator itr = edges[node].begin(); itr != edges[node].end(); itr++)
    {
        if (!visited[*itr])
        {
            minVertexCover(*itr, node);
            
            dp[node][1] += min(dp[*itr][0], dp[*itr][1]);
            dp[node][0] += dp[*itr][1];
        }
    }
    
}

int main(int argc, const char * argv[])
{
    int i, j, k, n;
    scanf("%d", &n);
    for (i = 0; i < n-1 ; i++)
    {
        scanf("%d %d", &j, &k);
        edges[j].push_back(k);
        edges[k].push_back(j);
    }
    int cnt = 0;
    if(n == 1)
    {
        cnt = 0;
    }
    else
    {
        minVertexCover(1, -1);
        cnt = min(dp[1][0],dp[1][1]);
    }
    
    cout<<cnt<<endl;
    return 0;
}