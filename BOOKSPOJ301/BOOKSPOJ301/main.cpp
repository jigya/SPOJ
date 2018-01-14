//
//  main.cpp
//  BOOKSPOJ301
//
//  Created by Jigya Yadav on 02/01/15.
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

bool pairCompare(const std::pair<int, int>& firstElem, const std::pair<int, int>& secondElem) {
    return firstElem.second < secondElem.second;
    
}

int main(int argc, const char * argv[])
{
    int i, j, k, n, m, p, q, r, t;
    scanf("%d", &t);
    vector< pair<int, int> > arr[3500];
    int numBooklets[3500];
    pair<int, int> numPages[3500];
    while (t--)
    {
        //n is number of schools
        //m is number of booklets
        scanf("%d", &n);
        scanf("%d", &p);
        scanf("%d", &m);
        q = m/n;
        r = m%n;
        forall(i, 0, n)
        {
            numBooklets[i] = q;
        }
        i = 0;
        while (r > 0)
        {
            numBooklets[i]++;
            r--;
            i++;
        }
        forall(i, 0, m)
        {
            scanf("%d", &q);
            numPages[i]=mp(q, i);
        }
        sort(numPages, numPages+m);
        k = 0;
        forall(i, 0, n)
        {
            arr[i].clear();
            forall(j, 0, numBooklets[i])
            {
                arr[i].push_back(numPages[k]);
                k++;
            }
        }
        sort(arr[p].begin(), arr[p].end(), pairCompare);
        printf("%d\n", arr[p][0].first);
    }
    return 0;
}

