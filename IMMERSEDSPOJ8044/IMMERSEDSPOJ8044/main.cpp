//
//  main.cpp
//  IMMERSEDSPOJ8044
//
//  Created by Jigya Yadav on 17/01/15.
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
int numCases = 0;

double bin_search(double lo, double hi, double val, int c)
{
    numCases = 0;
    double mid;
    double cal;
    while (numCases <= 50)
    {
        mid = lo+(hi-lo)/2;
        cal = pow(mid, c*mid+1);
        if (val < cal)
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
        numCases++;
    }
    return lo;
}

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t;
    double arr[6];
    arr[1] = 14.0;
    arr[2] = 8.0;
    arr[3] = 6.5;
    arr[4] = 5.5;
    arr[5] = 5.0;
    long long int p;
    s(t);
    while (t--)
    {
        numCases = 0;
        sl(p);
        s(m);
        printf("%.6lf\n", bin_search(1.0, arr[m], p*1.0, m));
    }
    return 0;
}

