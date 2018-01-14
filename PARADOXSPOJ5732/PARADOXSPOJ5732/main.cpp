//
//  main.cpp
//  PARADOXSPOJ5732
//
//  http://www.quora.com/What-is-the-algorithmic-approach-to-solving-the-problem-Paradox-on-SPOJ
//  Created by Jigya Yadav on 26/01/15.
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

bool visited[110];
bool tf[110];
vector< pair<int, bool> > edges[110];
bool flag = true;

void dfs(int node, bool val)
{
    visited[node] = true;
    tf[node] = val;
    for (vector< pair<int, bool> > :: iterator itr = edges[node].begin(); itr != edges[node].end(); itr++)
    {
        if (!visited[itr->first])
        {
            if(val == true)
                dfs(itr->first, itr->second);
            else
                dfs(itr->first, !itr->second);
        }
        else if(visited[itr->first])
        {
            if (val == true && tf[itr->first] != itr->second)
            {
                flag = false;
            }
            else if(val == false && tf[itr->first] != !itr->second)
            {
                flag = false;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, p, q, r, t;
    char str[50];
    while (1)
    {
        s(n);
        if (n == 0)
        {
            break;
        }
        forall(i, 0, 110)
        {
            edges[i].clear();
        }
        forall(i, 1, n+1)
        {
            s(j);
            ss(str);
            if (str[0] == 't')
            {
                edges[i].pb(mp(j, 1));
            }
            else
            {
                edges[i].pb(mp(j, 0));
            }
        }
        flag = true;
        memset(visited, false, sizeof(visited));
        forall(i, 1, n+1)
        {
            if(!visited[i])
            {
                dfs(i, true);
            }
        }
        
        if (flag == false)
        {
            printf("PARADOX\n");
        }
        else
        {
            printf("NOT PARADOX\n");
        }
    }
    
    return 0;
}

