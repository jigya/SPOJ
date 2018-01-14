//
//  main.cpp
//  HERDINGSPOJ4177
//
//  Created by Jigya Yadav on 30/01/15.
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

pair<int, int> arr[1010][1010];
int dr[1010][1010];
char str[1010];
int cnt = 0;

int visit(int x, int y, int num)
{
    if (dr[x][y] != -1)
    {
        return dr[x][y];
    }
    dr[x][y] = num;
    int r = visit(x+arr[x][y].first, y+arr[x][y].second, num);
    dr[x][y] = r;
    return r;
}

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, p, q, r;
    memset(dr, -1, sizeof(dr));
    s(n);s(m);
    forall(i, 0, n)
    {
        scanf("%s", str);
        forall(j, 0, m)
        {
            if (str[j] == 'N')
            {
                arr[i][j].first = -1;
                arr[i][j].second = 0;
            }
            else if(str[j] == 'S')
            {
                arr[i][j].first = 1;
                arr[i][j].second = 0;
            }
            else if(str[j] == 'E')
            {
                arr[i][j].first = 0;
                arr[i][j].second = 1;
            }
            else if(str[j] == 'W')
            {
                arr[i][j].first = 0;
                arr[i][j].second = -1;
            }
        }
    }
    forall(i, 0, n)
    {
        forall(j, 0, m)
        {
            if (dr[i][j] == -1)
            {
                cnt++;
                int h = visit(i, j, cnt);
//                cout<<h<<endl;
//                forall(pw, 0, n)
//                {
//                    forall(qw, 0, m)
//                    {
//                        cout<<dr[pw][qw]<<" ";
//                    }
//                    cout<<endl;
//                }
                if (h < cnt)
                {
                    cnt--;
                }
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}

