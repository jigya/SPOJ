//
//  main.cpp
//  MNEREDSPOJ4035
//
//  Created by Jigya Yadav on 14/01/15.
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


int arr[110][110] = {0};
int sumarr[110][110] = {0};

//find sum of array from x1, y1 to x2, y2
int findSum(int x1, int y1, int x2, int y2)
{
    int ans = sumarr[x2][y2] - sumarr[x2][y1-1] - sumarr[x1-1][y2] + sumarr[x1-1][y1-1];
    return ans;
}


int main(int argc, const char * argv[])
{
    int i, j, k, t, m, n, r, c;
    vector< pair<int, int> > factors;
    scanf("%d %d", &n, &m);
    forall(i, 0, m)
    {
        scanf("%d %d", &r, &c);
        arr[r][c] = 1;
    }
//    sumarr[1][1] = arr[1][1];
//    forall(i, 2, n+1)
//    {
//        sumarr[1][i] = sumarr[1][i-1]+arr[1][i];
//        sumarr[i][1] = sumarr[i-1][1]+arr[i][1];
//    }
    forall(i, 1, n+1)
    {
        forall(j, 1, n+1)
        {
            sumarr[i][j] = sumarr[i-1][j]+sumarr[i][j-1]-sumarr[i-1][j-1]+arr[i][j];
        }
    }
    for (i = 1; i * i <= m; i++)
    {
        if(m%i == 0)
        {
            factors.pb(mp(i, m/i));
            if (i != m/i)
            {
                factors.pb(mp(m/i, i));
            }
//            cout<<i<<" "<<m/i<<endl;
        }
    }
    int minMoves =INT_MAX;
    forall(i, 1, n+1)
    {
        forall(j, 1, n+1)
        {
            forall(k, 0, factors.size())
            {
                if(i+factors[k].first <= n+1 && j+factors[k].second <= n+1)
                {
                    minMoves = min(m-findSum(i, j, i+factors[k].first-1, j+factors[k].second-1), minMoves);
                }
            }
        }
    }
    printf("%d\n", minMoves);
    return 0;
}

