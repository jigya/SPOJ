//
//  main.cpp
//  AMBMSPOJ1673
//
//  http://apps.topcoder.com/forums/?module=Thread&threadID=659424&start=0&mc=8#1179457
//  Created by Jigya Yadav on 05/01/15.
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


int main(int argc, const char * argv[])
{
    int i, k, t;
    ll n;
    scanf("%d", &t);
    int a[70];
    ll b[70];
    while (t--)
    {
        vector<int> ans;
        scanf("%lld %d", &n, &k);
        forall(i, 0, k)
        {
            scanf("%d", &a[i]);
        }
        b[0] = a[0];
        forall(i, 1, k)
        {
            b[i] = (ll)a[i] + 2*b[i-1];
        }
        for (i = k-1; i >= 0 && n > 0; i--)
        {
            if (n >= b[i])
            {
                n -= b[i];
                ans.pb(i+1);
            }
        }
        if (n == 0)
        {
            for (vector<int>::reverse_iterator itr = ans.rbegin(); itr != ans.rend(); itr++)
            {
                printf("%d ", *itr);
            }
        }
        else
        {
            printf("-1");
        }
        printf("\n");
    }
    return 0;
}

