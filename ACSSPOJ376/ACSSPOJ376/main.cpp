//
//  main.cpp
//  ACSSPOJ376
//
//  Created by Jigya Yadav on 06/01/15.
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

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, x, y, t;
    string str;
    char c;
    int rows1[1500], columns1[6000];
    int rows2[1500], columns2[6000];
//    int arr[1235][5679];
//    k = 1;
//    forall(i, 1, 1235)
//    {
//        forall(j, 1, 5679)
//        {
//            arr[i][j] = k;
//            k++;
//        }
//    }
    //rows1[i] represents the place where original row i is present
    //rows2[i] represents the row present at position i now
    forall(i, 0, 1500)
    {
        rows1[i] = rows2[i] = i;
    }
    forall(i, 0, 6000)
    {
        columns1[i] = columns2[i] = i;
    }
    while (cin >> c)
    {
        if (c == 'R')
        {
            cin >> x >> y;
            t = rows1[x];
            rows1[x] = rows1[y];
            rows1[y] = t;
            rows2[rows1[x]] = x;
            rows2[rows1[y]] = y;
        }
        else if(c == 'C')
        {
            cin >> x >> y;
            t = columns1[x];
            columns1[x] = columns1[y];
            columns1[y] = t;
            columns2[columns1[x]] = x;
            columns2[columns1[y]] = y;
        }
        else if(c == 'Q')
        {
            cin >> x >> y;
            int a = rows1[x];
            int b = columns1[y];
            a--;
            b--;
            cout<<(a*5678)+b+1<<endl;
        }
        else
        {
            cin >> x;
            x--;
            int a = x/5678;
            int b = x - (a*5678);
            a++;
            b++;
            cout<<rows2[a]<<" "<<columns2[b]<<endl;
        }
    }
    return 0;
}

