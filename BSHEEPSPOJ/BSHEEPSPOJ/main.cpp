//
//  main.cpp
//  BSHEEPSPOJ
//
//  Created by Jigya Yadav on 30/06/15.
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

class Point    {
public:
    int x, y;
    
    // comparison is done first on y coordinate and then on x coordinate
    bool operator < (Point b) {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};

// Point having the least y coordinate, used for sorting other points
// according to polar angle about this point
Point pivot;

// returns -1 if a -> b -> c forms a counter-clockwise turn,
// +1 for a clockwise turn, 0 if they are collinear
int ccw(Point a, Point b, Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

// returns square of Euclidean distance between two points
int sqrDist(Point a, Point b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// used for sorting points according to polar order w.r.t the pivot
bool POLAR_ORDER(Point a, Point b)  {
    int order = ccw(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}

stack<Point> grahamScan(Point *points, int N)    {
    stack<Point> hull;
    
    if (N < 3)
        return hull;
    
    // find the point having the least y coordinate (pivot),
    // ties are broken in favor of lower x coordinate
    int leastY = 0;
    for (int i = 1; i < N; i++)
        if (points[i] < points[leastY])
            leastY = i;
    
    // swap the pivot with the first point
    Point temp = points[0];
    points[0] = points[leastY];
    points[leastY] = temp;
    
    // sort the remaining point according to polar order about the pivot
    pivot = points[0];
    sort(points + 1, points + N, POLAR_ORDER);
    
    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);
    
    for (int i = 3; i < N; i++) {
        Point top = hull.top();
        hull.pop();
        while (!hull.empty() && ccw(hull.top(), top, points[i]) != -1)   {
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);
    }
    return hull;
}

int main(int argc, const char * argv[])
{
    int t, n, x, y;
    s(t);
    Point pts[100010];
    while (t--)
    {
        map< pair<int, int> , int> pts_hm;
        s(n);
        forall(i, 0, n)
        {
            Point d;
            s(x);
            s(y);
            d.x = x;
            d.y = y;
            if (pts_hm.count(mp(x,y)) == 0)
            {
                pts[i] = d;
                pts_hm[mp(x, y)] = i;
            }
        }
        if (pts_hm.size() == 1)
        {
            printf("0.00\n1\n");
            continue;
        }
        else if(pts_hm.size() == 2)
        {
            Point a;
            Point b;
            a.x = (pts_hm.begin()->first).first;
            a.y = (pts_hm.begin()->first).second;
            b.x = (pts_hm.rbegin()->first).first;
            b.y = (pts_hm.rbegin()->first).second;
            int idx1 = pts_hm.begin()->second+1;
            int idx2 = pts_hm.rbegin()->second+1;
            if (a < b)
            {
                printf("%.2lf\n", 2*sqrt(sqrDist(a, b)));
                printf("%d %d\n", idx1, idx2);
            }
            else
            {
                printf("%.2lf\n", 2*sqrt(sqrDist(a, b)));
                printf("%d %d\n", idx2, idx1);
            }
            continue;
        }
        stack<Point> st = grahamScan(pts, n);
        double dist = 0;
        stack<int> revPoints;
        Point a = st.top();
        st.pop();
        revPoints.push(pts_hm[mp(a.x, a.y)]);
        while (!st.empty())
        {
            Point d = st.top();
            st.pop();
            while (!st.empty() && ccw(a, d, st.top()) == 0)
            {
                d = st.top();
                st.pop();
            }
            dist += sqrt(sqrDist(a, d));
            revPoints.push(pts_hm[mp(d.x, d.y)]);
            a = d;
        }
        if (revPoints.size() == 2)
        {
            printf("%.2lf\n", 2*dist);
        }
        else
            printf("%.2lf\n", dist);
        while (!revPoints.empty())
        {
            printf("%d ", revPoints.top()+1);
            revPoints.pop();
        }
        printf("\n");
    }
    return 0;
}
