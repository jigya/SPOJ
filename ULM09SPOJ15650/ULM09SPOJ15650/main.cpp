//
//  main.cpp
//  ULM09SPOJ15650
//
//  Created by Jigya Yadav on 30/01/15.
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

class Edge
{
public:
    int src;
    int dest;
    int wt;
    Edge()
    {}
    Edge(int x, int y, int z)
    {
        src=x;
        dest=y;
        wt=z;
    }
};

class CompareEdges {
public:
    bool operator()(Edge& t1, Edge& t2)
    {
        if(t1.wt>t2.wt)
            return true;
        return false;
    }
};

class UnionFind
{
public:
    int id[200010];
    int sz[200010];
    int count;
    UnionFind(int N)
    {
        count=N;
        int i;
        for(i=0;i<N;i++)
        {
            id[i]=i;
            sz[i]=1;
        }
    }
    int find(int p)
    {
        while(id[p]!=p)
            p=id[p];
        return p;
    }
    bool connected(int p, int q)
    {
        return find(p)==find(q);
    }
    void uniony(int p, int q)
    {
        int i=find(p);
        int j=find(q);
        if(i==j)
            return;
        if(sz[i]>sz[j])
        {
            id[j]=i;
            sz[i]+=sz[j];
        }
        else
        {
            id[i]=j;
            sz[j]+=sz[i];
        }
    }
};


int main()
{
    while(1)
    {
        int V,E,i,src,dest,wt,u,v;
        long long sum_len = 0;
        s(V);
        s(E);
        if (V == 0)
        {
            break;
        }
        priority_queue<Edge, vector<Edge>, CompareEdges> pq;
        UnionFind uf(V);
        for(i=0;i<E;i++)
        {
            s(src);
            s(dest);
            s(wt);
            sum_len += wt;
            Edge f(src,dest,wt);
            pq.push(f);
        }
        Edge d;
        int cnt = 0;
        ll sum_len2 = 0;
        while (cnt !=V-1)
        {
            d=pq.top();
            pq.pop();
            u=d.src;
            v=d.dest;
            if(!uf.connected(u,v))
            {
                uf.uniony(u,v);
                cnt++;
                sum_len2 += d.wt;
            }
        }
        printf("%lld\n", sum_len-sum_len2);
    }
    return 0;
}
