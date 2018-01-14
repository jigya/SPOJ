//
//  main.cpp
//  VOCVSPOJ666
//
//  Created by Jigya Yadav on 04/02/15.
//  Copyright (c) 2015 Jigya Yadav. All rights reserved.
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
#include <sstream>
#include <cfloat>
#define ll long long int

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-6

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

using namespace std;

vector<int> edges[100015];
bool visited[100015];
int dp[100015][2];

void dfs(int node, int par)
{
    visited[node] = true;
    if (edges[node].size() <= 1 && par != -1)
    {
        dp[node][0] = 0;
        dp[node][1] = 1;
        return;
    }
    dp[node][0] = 0;
    dp[node][1] = 1;
    for(vector<int>::iterator itr = edges[node].begin(); itr != edges[node].end(); itr++)
    {
        if (!visited[*itr])
        {
            dfs(*itr, node);
            dp[node][0] += dp[*itr][1];
            dp[node][1] += min(dp[*itr][0], dp[*itr][1]);
        }
    }
}

int main(int argc, const char * argv[])
{
    int n, t, u, v;
    s(t);
    while (t--)
    {
        forall(i, 0, 100015)
        {
            edges[i].clear();
        }
        s(n);
        forall(i, 1, n)
        {
            s(u);
            s(v);
            edges[u].pb(v);
            edges[v].pb(u);
        }
        memset(visited, false, sizeof(visited));
        dfs(1, -1);
        int ans = min(dp[1][0], dp[1][1]);
        cout<<ans<<endl;
    }
    return 0;
}

