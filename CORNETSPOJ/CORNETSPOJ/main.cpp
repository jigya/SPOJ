//
//  main.cpp
//  CORNETSPOJ
//
//  Created by Jigya Yadav on 12/06/15.
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

int arr[20100];
int distan[20100];

void initialise(int n)
{
    forall(i, 1, n+1)
    {
        arr[i] = i;
    }
}

int parent(int x)
{
    if(x == arr[x])
    {
        return x;
    }
    int i = arr[x];
    arr[x] = parent(arr[x]);
    distan[x] = distan[i] + distan[x];
    return arr[x];
}

int dist(int x)
{
    int d = 0;
    while (x != arr[x])
    {
        d += abs(x-arr[x])%1000;
        x = arr[x];
    }
    return d;
}

bool connected(int x, int y)
{
    return (parent(x) == parent(y));
}

void uniony(int x, int y)
{
    int rootX = parent(x);
    int rootY = parent(y);
    if (rootX == rootY)
    {
        return;
    }
    arr[rootX] = rootY;
}

int main(int argc, const char * argv[])
{
    int t, i, j, k, m, n, p, q;
    char c;
    s(t);
    while (t--)
    {
//        cout << "kfhgifho\n";
        s(n);
        initialise(n);
        memset(distan, 0, sizeof(distan));
//        printf("Here\n");
        while(1)
        {
            sc(c);
            sc(c);
//            printf("c = %c\n", c);
            if (c == 'O')
            {
                break;
            }
            else if(c == 'E')
            {
                s(p);
                parent(p);
                printf("%d\n", distan[p]);
            }
            else if(c == 'I')
            {
                s(p);
                s(q);
                arr[p] = arr[q];
                distan[p] = distan[q] + abs(p-q)%1000;
            }
        }
    }
    return 0;
}
