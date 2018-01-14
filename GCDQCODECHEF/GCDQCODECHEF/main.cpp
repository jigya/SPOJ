//
//  main.cpp
//  GCDQCODECHEF
//
//  Created by Jigya Yadav on 07/01/15.
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

int segTree[300000];
int arr[100100];

int segNodeCount;
//Build the segment tree from given array
void initialize(int lo, int hi, int pos)
{
    if(lo==hi)
    {
        segTree[pos]=arr[lo];
        if(pos>segNodeCount)
            segNodeCount=pos;
    }
    else
    {
        int mid=lo+(hi-lo)/2;
        initialize(lo, mid, 2*pos+1);
        initialize(mid+1, hi, 2*pos+2);
        segTree[pos]=gcd(segTree[2*pos+1], segTree[2*pos+2]);
    }
}

//Get the minimum in the range "lowerLimit" to "upperLimit"
int getGcd(int node, int lo, int hi, int lowerLimit, int upperLimit)
{
    if((lowerLimit<=lo && hi<=upperLimit))
    {
        return segTree[node];
    }
    if(lowerLimit>hi || upperLimit<lo)
    {
        return -1;
    }
    int mid=lo+(hi-lo)/2;
    int j = getGcd(node*2+1, lo, mid, lowerLimit, upperLimit);
    int k = getGcd(2*node+2, mid+1, hi, lowerLimit, upperLimit);
    if (j == -1 && k == -1)
    {
        return -1;
    }
    else if(j == -1)
    {
        return k;
    }
    else if(k == -1)
    {
        return j;
    }
    else
    {
        return gcd(j, k);
    }
}

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t, q, l, r, ans;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &q);
        forall(i, 0, n)
        {
            scanf("%d", &arr[i]);
        }
        initialize(0, n-1, 0);
        while (q--)
        {
            scanf("%d%d", &l, &r);
            l--;
            r--;
            if (l-1 >= 0)
            {
                j = getGcd(0, 0, n-1, 0, l-1);
            }
            else
            {
                j = -1;
            }
            if (r+1 <= n-1)
            {
                k = getGcd(0, 0, n-1, r+1, n-1);
            }
            else
            {
                k = -1;
            }
            if (j == -1 && k == -1)
            {
                ans = -1;
            }
            else if(j == -1)
            {
                ans = k;
            }
            else if(k == -1)
            {
                ans = j;
            }
            else
            {
                ans = gcd(j, k);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

