//
//  main.cpp
//  BAT3SPOJ13643
//
//  Created by Jigya Yadav on 31/01/15.
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



int main(int argc, const char * argv[])
{
    int i, j, m, n, t;
    int arr[1010];
    int lis[1010];
    s(t);
    while (t--)
    {
        s(n);
        s(m);
        forall(i, 0, n)
        {
            s(arr[i]);
            lis[i] = 1;
        }
        for ( i = 1; i < n; i++ )
            for ( j = 0; j < i; j++ )
                if ( (arr[i] < arr[j] || i == m) && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
        
        int max_strength = lis[0];
        forall(i, 1, n)
        {
            max_strength =  max(max_strength, lis[i]);
        }
        printf("%d\n", max_strength);
    }
    return 0;
}

