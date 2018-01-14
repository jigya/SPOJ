//
//  main.cpp
//  MAXSUMSQSPOJ5972
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
#include<math.h>
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
    int t, i, j, k, m, n;
    int arr[100100];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        forall(i, 0, n)
        {
            scanf("%d", &arr[i]);
        }
        ll cnt = 0;
        ll sum = 0;
        ll minSum = 0;
        ll minCnt = 1;
        ll max_so_far = -1*INF;
        forall(i , 0, n)
        {
            sum += arr[i];
            if (sum-minSum > max_so_far)
            {
                max_so_far = sum-minSum;
                cnt = minCnt;
            }
            else if(sum-minSum==max_so_far)
            {
                cnt += minCnt;
            }
            if (sum < minSum)
            {
                minSum = sum;
                minCnt = 1;
            }
            else if(sum == minSum)
            {
                minCnt++;
            }
        }
        cout<<max_so_far<<" "<<cnt<<endl;
    }
    return 0;
}

