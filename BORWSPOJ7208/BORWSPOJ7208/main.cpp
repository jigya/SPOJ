//
//  main.cpp
//  BORWSPOJ7208
//
//  Created by Jigya Yadav on 04/02/15.
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

#define MAXN 202

int arr[MAXN];
int dp[MAXN][MAXN][MAXN];
int n;

int calculateMinUnpainted(int inc, int dec, int idx)
{
    if (dp[inc][dec][idx] != -1)
    {
        return dp[inc][dec][idx];
    }
    if (idx == n)
    {
        return 0;
    }
    if (arr[idx] < arr[dec])
    {
        dp[inc][dec][idx] = calculateMinUnpainted(inc, idx, idx+1);
    }
    if (arr[idx] > arr[inc])
    {
        if (dp[inc][dec][idx] == -1)
        {
            dp[inc][dec][idx] = calculateMinUnpainted(idx, dec, idx+1);
        }
        else
        {
            dp[inc][dec][idx] = min(calculateMinUnpainted(idx, dec, idx+1), dp[inc][dec][idx]);
        }
    }
    if (dp[inc][dec][idx] == -1)
    {
        dp[inc][dec][idx] = 1+calculateMinUnpainted(inc, dec, idx+1);
    }
    else
    {
        dp[inc][dec][idx] = min(1+calculateMinUnpainted(inc, dec, idx+1), dp[inc][dec][idx]);
    }
    return dp[inc][dec][idx];
}

int main(int argc, const char * argv[])
{
    arr[MAXN-1] = -INF;
    arr[MAXN-2] = INF;
    while (1)
    {
        s(n);
        if (n == -1)
        {
            break;
        }
        forall(i, 0, n)
        {
            s(arr[i]);
        }
        int sol = calculateMinUnpainted(MAXN-1, MAXN-2, 0);
        
        printf("%d\n", sol);
    }
    return 0;
}

