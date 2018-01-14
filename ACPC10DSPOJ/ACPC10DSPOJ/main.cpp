//
//  main.cpp
//  ACPC10DSPOJ
//
//  Created by Jigya Yadav on 07/06/15.
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

int row1[][2] = {{1, 0}, {0, 1}, {1, 1}};
int row2[][2] = {{1, 0}, {0, 1}, {1, 1}, {1,-1}};
int row3[][2] = {{1, -1}, {1, 0}};

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, p, x, y;
    int cost[100100][3];
    ll cumulativeCost[100100][3] = {INF};
    int num = 1;
    while(1)
    {
        s(n);
        if (n == 0)
        {
            break;
        }
        forall(i, 0, n)
        {
            forall(j, 0, 3)
            {
                s(cost[i][j]);
                cumulativeCost[i][j] = 1e14;
            }
        }
        cumulativeCost[0][1] = cost[0][1];
        cumulativeCost[0][2] = cumulativeCost[0][1] + cost[0][2];
        cumulativeCost[1][0] = cumulativeCost[0][1] + cost[1][0];
        cumulativeCost[1][1] = cost[1][1] + min(cumulativeCost[1][0], min(cumulativeCost[0][1], cumulativeCost[0][2]));
        cumulativeCost[1][2] = cost[1][2] + min(cumulativeCost[1][1], min(cumulativeCost[0][1], cumulativeCost[0][2]));
//        forall(i, 0, 4)
//        {
//            x = 0+row2[i][0];
//            y = 1+row2[i][1];
//            cumulativeCost[x][y] = min(cumulativeCost[x][y], cumulativeCost[0][1] + cost[x][y]);
//        }
//        forall(i, 0, 2)
//        {
//            x = 0+row3[i][0];
//            y = 2+row3[i][1];
//            cumulativeCost[x][y] = min(cumulativeCost[x][y], cumulativeCost[0][2] + cost[x][y]);
//        }
        forall(p, 1, n)
        {
            forall(i, 0, 3)
            {
                cumulativeCost[p+row1[i][0]][0+row1[i][1]] = min(cumulativeCost[p+row1[i][0]][0+row1[i][1]], cumulativeCost[p][0] + cost[p+row1[i][0]][0+row1[i][1]]);
            }
            forall(i, 0, 4)
            {
                cumulativeCost[p+row2[i][0]][1+row2[i][1]] = min(cumulativeCost[p+row2[i][0]][1+row2[i][1]], cumulativeCost[p][1] + cost[p+row2[i][0]][1+row2[i][1]]);
            }
            forall(i, 0, 2)
            {
                cumulativeCost[p+row3[i][0]][2+row3[i][1]] = min(cumulativeCost[p+row3[i][0]][2+row3[i][1]], cumulativeCost[p][2] + cost[p+row3[i][0]][2+row3[i][1]]);
            }
        }
        printf("%d. %lld\n", num, cumulativeCost[n-1][1]);
        num++;
    }
    return 0;
}
