//
//  main.cpp
//  AMR10CSPOJ
//
//  Created by Jigya Yadav on 09/06/15.
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

vector< pair<int, int> > arr[1000100];

vector< pair<int, int> > primeFactors(int x)
{
    int i;
    int p = x;
    vector< pair<int, int> > pr;
    for (i = 2; i * i <= x; i == 2?(i++):(i=i+2))
    {
        int cnt = 0;
        while (x%i == 0)
        {
            x = x/i;
            cnt++;
        }
        if (cnt > 0)
        {
            arr[p].pb(make_pair(i, cnt));
            pr.pb(make_pair(cnt, i));
        }
    }
    if (x > 1)
    {
        pr.pb(make_pair(1, x));
    }
    return pr;
}

int main(int argc, const char * argv[])
{
    int n, p, q, r, t;
    s(t);
    while (t--)
    {
        s(n);
        vector< pair<int, int> > pr = primeFactors(n);
        sort(pr.begin(), pr.end());
        printf("%d\n", pr[pr.size()-1].first);
    }
    return 0;
}
