//
//  main.cpp
//  TRAFFICNSPOJ3643
//
//  Created by Jigya Yadav on 03/01/15.
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
#define ll long long int

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
//#define INF                         (int)1e9
#define EPS                         1e-9

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

const int INF = 1000000000;
typedef pair<int,int> PII;

void djikstra( vector<PII> edges[], int source, int dist[])
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    Q.push (make_pair (0, source));
    dist[source] = 0;
    while (!Q.empty())
    {
        PII p = Q.top();
        Q.pop();
        
        int here = p.second;
        for (vector<PII>::iterator it=edges[here].begin(); it!=edges[here].end(); it++){
            if (dist[here] + it->first < dist[it->second]){
                dist[it->second] = dist[here] + it->first;
                Q.push (make_pair (dist[it->second], it->second));
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t, src, dest, di, ci, li;
    scanf("%d", &t);
    vector< pair<int, int> > edges[10100];
    vector< pair<int, int> > transposeEdges[10100];
    int srcDist[10100];
    int destDist[10100];
    while (t--)
    {
        forall(i, 0, 10100)
        {
            edges[i].clear();
            transposeEdges[i].clear();
            srcDist[i] = INF;
            destDist[i] = INF;
        }
        scanf("%d%d%d%d%d", &n, &m, &k, &src, &dest);
        while (m--)
        {
            scanf("%d%d%d", &di, &ci, &li);
            edges[di].push_back(make_pair(li, ci));
            transposeEdges[ci].push_back(mp(li, di));
            djikstra(edges, src, srcDist);
            djikstra(transposeEdges, dest, destDist);
        }
        forall(i, 1, n+1)
        {
            cout<<srcDist[i]<<" "<<destDist[i]<<endl;
        }
        int minDistance = srcDist[dest];
        while (k--)
        {
            scanf("%d%d%d", &di, &ci, &li);
            minDistance = min(srcDist[di]+li+destDist[ci], minDistance);
            minDistance = min(srcDist[ci]+li+destDist[di], minDistance);
        }
        if (minDistance >= INF)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", minDistance);
        }
    }
    return 0;
}

