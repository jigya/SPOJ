//
//  main.cpp
//  CAM5SPOJ10380
//
//  Created by Jigya Yadav on 22/01/15.
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

class UnionFind
{
public:
    int id[100010];
    int sz[100010];
    int count;
    UnionFind(int n)
    {
        forall(i, 0, n)
        {
            id[i] = i;
            sz[i] = 1;
        }
        count = n;
    }
    
    int find(int p)
    {
        while (p != id[p])
        {
            p = id[p];
        }
        return p;
    }
    
    bool connected(int p, int q)
    {
        return (find(p) == find(q));
    }
    
    void uniony(int p, int q)
    {
        int q1 = find(p);
        int q2 = find(q);
        if (q1 == q2)
        {
            return;
        }
        if (sz[q1] < sz[q2])
        {
            id[q1] = q2;
            sz[q2] += sz[q1];
        }
        else
        {
            id[q2] = q1;
            sz[q1] += sz[q2];
        }
        count--;
    }
};

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t;
    s(t);
    while (t--)
    {
        s(n);
        s(m);
        UnionFind d(n);
        while (m--)
        {
            s(j);
            s(k);
            d.uniony(j, k);
        }
        printf("%d\n", d.count);
    }
    return 0;
}

