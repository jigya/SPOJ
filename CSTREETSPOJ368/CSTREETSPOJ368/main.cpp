//
//  main.cpp
//  CSTREETSPOJ368
//
//  Created by Jigya Yadav on 04/09/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <queue>

using namespace std;

class Edge
{
public:
    int src;
    int dest;
    long long int wt;
    Edge()
    {}
    Edge(int x, int y, long long int z)
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
    int id[1010];
    int sz[1010];
    int count;
    UnionFind(int N)
    {
        count=N;
        int i;
        for(i=0;i<=N;i++)
        {
            id[i]=i;
            sz[i]=1;
        }
//        for (i=0; i<N; i++)
//        {
//            cout<<id[i]<<" "<<sz[i]<<endl;
//        }
    }
    int find(int p)
    {
        while(id[p]!=p)
        {
            p=id[p];
        }
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

int main(int argc, const char * argv[])
{
    int t, p, i, V, E, u, v, src, dest, wt;
    vector<Edge> rslt;
    priority_queue<Edge, vector<Edge>, CompareEdges> pq;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&p);
        scanf("%d",&V);
        scanf("%d",&E);
        for(i=0;i<E;i++)
        {
            cin>>src>>dest>>wt;
            Edge f(src,dest,(long long int)wt*p);
            pq.push(f);
        }
        Edge d;
        UnionFind uf(V);
        while (rslt.size()!=V-1) {
            d=pq.top();
            pq.pop();
            u=d.src;
            v=d.dest;
            if(!uf.connected(u,v))
            {
                uf.uniony(u,v);
                rslt.push_back(d);
            }
        }
        long long int ans=0;
        for(i=0;i<V-1;i++)
        {
            ans+=rslt[i].wt;
        }
        cout<<ans<<endl;
    }
    return 0;
}

