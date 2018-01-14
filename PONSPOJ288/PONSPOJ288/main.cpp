//
//  main.cpp
//  PONSPOJ288
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

long long mulmod(long long a, long long b, long long c)
{
    ll x = 0, y = a%c;
    while (b > 0) {
        if (b%2) {
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

long long int modulo(ll a, ll b, ll c)
{
    ll x = 1, y = a;
    while (b > 0) {
        if (b%2) {
            x = mulmod(x, y, c);
        }
        y = mulmod(y, y, c);
        b /= 2;
    }
    return x%c;
}


bool MillerRabin(long long int p, int iteration)
{
    if (p <2) {
        return false;
    }
    if (p != 2 && p%2 == 0)
    {
        return false;
    }
    long long s = p-1;
    while (s%2 == 0) {
        s /= 2;
    }
    forall(i, 0, iteration)
    {
        long long a = rand()%(p-1)+1;
        long long temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p-1 && mod != 1 && mod!=p-1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p-1 && temp%2 == 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t;
    ll f;
    s(t);
    while (t--)
    {
        sl(f);
        bool flag = MillerRabin(f, 20);
        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

