//
//  main.cpp
//  GOSSIPERSPOJ2139
//
//  Created by Jigya Yadav on 01/01/15.
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
    int i, j, k, m, n, t, p, q, r;
    bool flag;
    scanf("%d %d", &n, &m);
    char name[200];
    char name2[200];
    map<string, int> hm;
    bool arr[2110][2110];
    int numGossips[2110];
    while(n != 0 && m != 0)
    {
        hm.clear();
        flag = true;
        memset(arr, false, sizeof(arr));
        forall(i, 0, n)
        {
            scanf("%s", name);
            arr[i][i] = true;
            numGossips[i] = 1;
            hm[name] = i;
        }
//        for(map<string, int>::iterator itr = hm.begin(); itr != hm.end(); itr++)
//        {
//            cout<<itr->first<<" "<<(itr->second)<<endl;
//        }
        forall(i, 0, m)
        {
            scanf("%s", name);
            scanf("%s", name2);
            int idx1 = hm[name];
            int idx2 =  hm[name2];
            forall(i, 0, n)
            {
                if (arr[idx1][i])
                {
                    if (arr[idx2][i] == false)
                    {
                        numGossips[idx2]++;
                        arr[idx2][i] = true;
                    }
                }
                if (arr[idx2][i])
                {
                    if (arr[idx1][i] == false)
                    {
                        numGossips[idx1]++;
                        arr[idx1][i] = true;
                    }
                }
            }
        }
        forall(i, 0, n)
        {
            if (numGossips[i] != n)
            {
                flag = false;
            }
        }
        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        scanf("%d %d", &n, &m);
    }
    return 0;
}

