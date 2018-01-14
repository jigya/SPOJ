//
//  main.cpp
//  HOMOSPOJ7691
//
//  Created by Jigya Yadav on 15/01/15.
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

map< int, queue<int> > hm;
set<int> homo;
set<int> hetero;

void ans()
{
    if (homo.size() == 0 && hetero.size() < 2)
    {
        printf("neither\n");
    }
    else if(homo.size() > 0 && hetero.size() >= 2)
    {
        printf("both\n");
    }
    else if (homo.size() > 0)
    {
        printf("homo\n");
    }
    else
    {
        printf("hetero\n");
    }
}

int main(int argc, const char * argv[])
{
    int i, j, k, n, m;
    char str[20];
    scanf("%d", &n);
    int cnt = 0;
    while (n--)
    {
        scanf("%s", str);
        scanf("%d", &k);
        if (str[0] == 'i')
        {
            cnt++;
            hm[k].push(cnt);
            if (hm[k].size() == 1)
            {
                hetero.insert(k);
            }
            if (hm[k].size() == 2)
            {
                homo.insert(k);
            }
        }
        else if(str[0] == 'd' && hm[k].size() > 0)
        {
            hm[k].pop();
            if (hm[k].size() == 0)
            {
                hetero.erase(k);
            }
            if (hm[k].size() == 1)
            {
                homo.erase(k);
            }
        }
        ans();
    }
    return 0;
}

