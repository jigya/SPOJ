//
//  main.cpp
//  BYTESE2SPOJ3921
//
//  Created by Jigya Yadav on 07/11/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
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
    int i, j, k, m, n, t;
    pair<int, int> arr[500];
    scanf("%d", &t);
    while (t--)
    {
        s(n);
        m = 0;
        forall(i, 0, n)
        {
            s(j);
            arr[m] = make_pair(j, 1);
            m++;
            s(j);
            arr[m] = (make_pair(j, 0));
            m++;
        }
        sort(arr, arr+2*n);
        int cnt = 0;
        int maxcnt = -1;
        forall(i, 0, 2*n)
        {
//            cout<<arr[i].first<<" "<<arr[i].second<<endl;
            if (arr[i].second == 1)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            maxcnt = max(cnt, maxcnt);
        }
        printf("%d\n", maxcnt);
    }
    return 0;
}

