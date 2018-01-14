//
//  main.cpp
//  PPATHSPOJ
//
//  Created by Jigya Yadav on 15/04/15.
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

bool prime[10010] = {true};
void genPrimes()
{
    memset(prime, true, sizeof(prime));
    int i, j;
    for(i = 2; i <= 10000; i++)
    {
        if (prime[i])
        {
//            cout<<i<<endl;
            for (j = 2; j*i <= 10000; j++)
            {
                prime[i*j] = false;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int t, i, j, k, m, n, units, tens, hundreds, thousands;
    genPrimes();
//    for (i = 2; i < 10000; i++)
//    {
//        if (prime[i])
//        {
//            cout<<i<<endl;
//        }
//    }
//    cout<<"primes ended"<<endl;
    s(t);
    pair<int, int> d;
    while (t--)
    {
        bool visited[10000] = {false};
        memset(visited, false, sizeof(visited));
        s(m);
        s(n);
        if (m == n)
        {
            printf("0\n");
            continue;
        }
        queue< pair<int, int> > q;
        q.push(mp(m, 0));
        int cost = -1;
        bool ans = false;
        while (!q.empty() && ans == false)
        {
//            cout<<"here"<<endl;
            d = q.front();
            q.pop();
            k = d.first;
            units = k%10;
            k /= 10;
            tens = k%10;
            k /= 10;
            hundreds = k%10;
            k /= 10;
            thousands = k;
            for (i = 0; i <= 9 && ans == false; i++)
            {
                k = d.first;
                k = k-units;
                if (i == units)
                {
                    continue;
                }
                k += i;
                if(k == n)
                {
                    ans = true;
                    cost = d.second+1;
                }
//                cout<<k<<endl;
                if (prime[k] && !visited[k])
                {
                    visited[k] = true;
                    q.push(mp(k, d.second+1));
                }
            }
            for (i = 0; i <= 9 && ans == false; i++)
            {
                k = d.first;
                k = k-tens*10;
                if (i == tens)
                {
                    continue;
                }
                k += i*10;
                if(k == n)
                {
                    ans = true;
                    cost = d.second+1;
                }
//                cout<<k<<endl;
                if (prime[k] && !visited[k])
                {
                    visited[k] = true;
                    
                    q.push(mp(k, d.second+1));
                }
            }
            for (i = 0; i <= 9 && ans == false; i++)
            {
                k = d.first;
                k = k-hundreds*100;
                if (i == hundreds)
                {
                    continue;
                }
                k += i*100;
                if(k == n)
                {
                    ans = true;
                    cost = d.second+1;
                }
//                cout<<k<<endl;
                if (prime[k] && !visited[k])
                {
                    visited[k] = true;
                    
                    q.push(mp(k, d.second+1));
                }
            }
            for (i = 1; i <= 9 && ans == false; i++)
            {
                k = d.first;
                k = k-thousands*1000;
                if (i == units)
                {
                    continue;
                }
                k += i*1000;
                if(k == n)
                {
                    ans = true;
                    cost = d.second+1;
                }
//                cout<<k<<endl;
                if (prime[k] && !visited[k])
                {
                    visited[k] = true;
                    
                    q.push(mp(k, d.second+1));
                }
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}
