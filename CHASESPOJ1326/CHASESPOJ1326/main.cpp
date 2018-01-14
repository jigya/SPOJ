//
//  main.cpp
//  CHASESPOJ1326
//
//  http://www.quora.com/Given-n-points-on-a-2D-plane-how-would-you-find-the-maximum-number-of-points-that-lie-on-the-same-straight-line-Please-give-an-algorithm-to-solve-this-problem
//
//  http://apps.topcoder.com/forums/?module=Thread&threadID=630496&mc=23&view=threaded
//  Created by Jigya Yadav on 05/01/15.
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

//int maxPoints(pair<int, int> points[], int n)
//{
//    if (n == 1)
//    {
//        return 1;
//    }
//    int maxpoints = 0;
//    double slope;
//    forall(i, 0, n-1)
//    {
//        int currentPoints = 1;
//        int dup = 0;
//        map<double, int> hm;
//        forall(j, i+1, n)
//        {
//            if ((points[i].first == points[j].first) && (points[i].second == points[j].second))
//            {
//                dup++;
//                continue;
//            }
//            if (points[i].first == points[j].first)
//            {
//                slope = DBL_MAX;
//            }
//            else
//            {
//                slope = (double)(points[j].second - points[i].second)/(double)(points[i].first-points[j].first);
//                slope += 0.0;
//            }
//            if (hm.count(slope) == 0)
//            {
//                hm[slope] = 2;
//            }
//            else
//            {
//                hm[slope]++;
//            }
//            int y = hm[slope];
//            if (currentPoints+dup < y+dup)
//            {
//                currentPoints = y;
//            }
//        }
//        currentPoints += dup;
//        maxpoints = max(currentPoints, maxpoints);
//    }
//    return maxpoints;
//}

int maxPoints(pair<int, int> points[], int n)
{
    if (n == 1)
    {
        return 1;
    }
    int maxPoints = 0;
    double slope;
    int k = 0;
    forall(i, 0, n-1)
    {
        int dup = 0;
        k = 0;
        long long int arr[3000];
        forall(j, i+1, n)
        {
            if ((points[i].first == points[j].first) && (points[i].second == points[j].second))
            {
                dup++;
                continue;
            }
            if (points[i].first == points[j].first)
            {
                slope = LONG_LONG_MAX;
            }
            else
            {
                slope = (double)(points[j].second - points[i].second)/(double)(points[j].first-points[i].first);
                slope += 0.0;
                slope *= 1e6;
            }
            arr[k++] = slope;
        }
        sort(arr, arr+k);
        int d = 0, currCnt = 1;
        while (d < k-1)
        {
            currCnt = 1;
            while ( d < k-1 && arr[d] == arr[d+1])
            {
                currCnt++;
                d++;
            }
            d++;
            maxPoints = max(maxPoints, currCnt);
        }
        currCnt = 1;
        maxPoints = max(maxPoints, currCnt);
    }
    return maxPoints;
}

int main(int argc, const char * argv[])
{
    int n, t, p, q;
    scanf("%d", &t);
    pair<int, int> arr[3000];
    while (t--)
    {
        scanf("%d", &n);
        forall(i, 0, n)
        {
            scanf("%d %d", &p, &q);
            arr[i] = make_pair(p, q);
        }
        printf("%d\n", maxPoints(arr, n));
    }
    return 0;
}

