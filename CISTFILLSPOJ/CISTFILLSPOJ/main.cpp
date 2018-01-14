//
//  main.cpp
//  CISTFILLSPOJ
//
//  Created by Jigya Yadav on 11/06/15.
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


int minLevel = 0;

int maxLevel = 104000;

pair< pair<ll,ll>, pair<ll, ll> > pr[50100];

int n;

ll vol;

ll maxht;
ll loht = 1<<30;

//double binSearch()
//{
//    int iter = 1;
//    double lo = loht;
//    double hi = maxht;
//    while (hi-lo >= 1e-3)
//    {
//        double mid = lo+(hi-lo)/2;
//        double totalFilled = 0;
//        forall(i, 0, n)
//        {
//            ll b = pr[i].first.first;
//            ll h = pr[i].first.second;
//            ll w = pr[i].second.first;
//            ll d = pr[i].second.second;
//            if (mid <= b)
//            {}
//            else if (mid > b+h)
//            {
//                totalFilled += h*w*d;
//            }
//            else
//            {
//                totalFilled += (mid-b)*(double)w*d;
//            }
//        }
//        if (totalFilled >= vol)
//        {
//            hi = mid;
//        }
//        else
//        {
//            lo = mid;
//        }
//        iter++;
//    }
//    return hi;
//}

void go(){
    register double hi= maxht,mid,curr_volume;
    double lo=loht;
    int i=0;
    
    while( hi-lo >= 1e-3 ){
        mid = ( lo+hi )/2;
        curr_volume = 0;
        for(i=0;i<n;i++) if(mid-pr[i].first.first>=0){
            if(pr[i].first.second < mid-pr[i].first.first) curr_volume += pr[i].second.first*pr[i].second.second*pr[i].first.second;
            else curr_volume +=  pr[i].second.first*pr[i].second.second*(mid - pr[i].first.first);
        }
        ((curr_volume>=vol)?hi:lo) = mid;
    }
    printf("%.2lf\n",hi);
}

int main(int argc, const char * argv[])
{
    int t, m, p, q, r;
    ll b, h, w, d;
    s(t);
    ll totalVol;
    while (t--)
    {
        s(n);
        maxht = 0;
        totalVol = 0;
        forall(i, 0, n)
        {
            sl(b);
            sl(h);
            sl(w);
            sl(d);
            pr[i] = mp(mp(b, h), mp(w, d));
            totalVol += h*w*d;
            if (b+h > maxht)
            {
                maxht = b+h;
            }
            if(b < loht)
            {
                loht = b;
            }
        }
        sl(vol);
        if (vol > totalVol)
        {
            printf("OVERFLOW\n");
        }
        else
        {
//            double ans = binSearch();
//            bool ansCorrect = false;
//            double maxLevel = -1;
//            forall(i, 0, n)
//            {
//                b = pr[i].first.first;
//                h = pr[i].first.second;
//                w = pr[i].second.first;
//                d = pr[i].second.second;
//                if (ans > b && ans < b+h)
//                {
//                    ansCorrect = true;
//                }
//                if (b+h > maxLevel && b+h < ans)
//                {
//                    maxLevel = b+h;
//                }
//            }
//            if(!ansCorrect)
//            {
//                ans = maxLevel;
//            }
//            printf("%.2lf\n", ans);
            go();
        }
    }
    return 0;
}
