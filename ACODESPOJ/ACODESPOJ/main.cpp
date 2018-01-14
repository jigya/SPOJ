//
//  main.cpp
//  ACODESPOJ
//
//  Created by Jigya Yadav on 05/06/15.
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
    int i, j, k, m, n, p, q, r;
    string str;
    while (1)
    {
        cin >> str;
        if (str == "0")
        {
            break;
        }
        ll arr[5010];
        memset(arr, 0, sizeof(arr));
        arr[0] = 1;
    for (i = 1; i < str.length(); i++)
    {
        if (str[i] != '0')
        {
            arr[i] = arr[i-1];
        }
        m = str[i]-'0';
        n = str[i-1]-'0';
        p = n*10+m;
        if (str[i-1] != '0')
        {
            if (p >= 1 && p <= 26 && i-2 >= 0)
            {
                arr[i] += arr[i-2];
            }
            else if(p >= 1 && p <= 26 && i-2 < 0)
            {
                arr[i] += 1;
            }
        }
    }
        printf("%lld\n", arr[str.length()-1]);
    }
    return 0;
}
