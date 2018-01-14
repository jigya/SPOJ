//
//  main.cpp
//  ARBITRAGSPOJ9340
//
//  Floyd Warshall
//  Created by Jigya Yadav on 18/01/15.
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

bool visited[35];



int main(int argc, const char * argv[])
{
    int i, j, k, m, n;
    j = 0;
    double t;
    double arr[35][35];
    char str[150], str1[150];
    while (1)
    {
        j++;
        map<string, int> hm;
        memset(arr, 0.0, sizeof(arr));
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        forall(i, 1, n+1)
        {
            scanf("%s", str);
            hm[str] = i;
        }
        s(m);
        forall(i, 0, m)
        {
            ss(str);
            sf(t);
            ss(str1);
            arr[hm[str]][hm[str1]] = t;
        }
        bool flag = false;
        forall(k, 1, n+1)
        {
            forall(i, 1, n+1)
            {
                forall(j, 1, n+1)
                {
                    if (arr[i][j]<arr[i][k]*arr[k][j])
                    {
                        arr[i][j] = arr[i][k]*arr[k][j];
                    }
                }
            }
        }
        forall(i, 1, n+1)
        {
            if (arr[i][i] > 1.0)
            {
                flag= true;
                break;
            }
        }
        if (flag)
        {
            printf("Case %d: Yes\n", j);
        }
        else
        {
            printf("Case %d: No\n", j);
        }
    }
    return 0;
}

