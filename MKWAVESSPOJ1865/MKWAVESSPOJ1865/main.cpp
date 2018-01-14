//
//  main.cpp
//  MKWAVESSPOJ1865
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


int main(int argc, const char * argv[])
{
    int t, s = 1, f1, f2;
    scanf("%d", &t);
    double vals[1500];
    double sinval;
    while (t!=0)
    {
        forall(i, 1, t+1)
        {
            scanf("%lf", &vals[i]);
        }
        int cnt;
        forall(i, 400, 601)
        {
            forall(j, i+1, 601)
            {
                cnt = 0;
                forall(k, 1, t+1)
                {
                    sinval = sin((i*k)/(57.2957795*t))+sin((j*k)/(57.2957795*t));
//                    cout<<i<<" "<<j<<" "<<abs(sinval-vals[i])<<endl;
                    if (abs(sinval-vals[k]) > 1e-5)
                    {
                        cnt = -1;
                        break;
                    }
                }
                if (cnt == 0)
                {
                    f1 = i;
                    f2 = j;
                    break;
                }
            }
            if (cnt == 0)
            {
                break;
            }
        }
        printf("Case %d, f1 = %d, f2 = %d\n", s, f1, f2);
        scanf("%d", &t);
        s++;
    }
    return 0;
}

