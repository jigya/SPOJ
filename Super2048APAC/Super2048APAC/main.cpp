//
//  main.cpp
//  Super2048APAC
//
//  Created by Jigya Yadav on 08/11/14.
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
    freopen("/Users/jigyayadav/downloads/B-large-practice.in.txt", "r", stdin);
    freopen("/Users/jigyayadav/downloads/B-large-practiceout.txt", "w", stdout);
    int i, j, k, m, n, t;
    string dir;
    cin >> t;
    int arr[25][25];
    bool shifted[25][25];
    int rslt[25][25];
    for (int s = 1; s <= t; s++)
    {
        cin >> n;
        cin >> dir;
        memset(shifted, false, sizeof(shifted));
        forall(i, 0, n)
        {
            forall(j, 0, n)
            {
                cin >> arr[i][j];
            }
        }
        if (dir == "right")
        {
            for (k = 1; k <= n; k++)
            {
                for (i = n-1; i >= 1; i--)
                {
                    for (j = 0; j < n; j++)
                    {
                        if (arr[j][i] == 0)
                        {
                            arr[j][i] = arr[j][i-1];
                            arr[j][i-1] = 0;
                        }
                        else if(arr[j][i] == arr[j][i-1])
                        {
                            if (!shifted[j][i] && !shifted[j][i-1])
                            {
                                arr[j][i] = 2*arr[j][i];
                                arr[j][i-1] = 0;
                                shifted[j][i] = true;
                            }
                        }
                    }
                }
            }
        }
        else if(dir == "left")
        {
            for (k = 1; k <= n; k++)
            {
                for (i = 0; i < n-1; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        if (arr[j][i] == 0)
                        {
                            arr[j][i] = arr[j][i+1];
                            arr[j][i+1] = 0;
                        }
                        else if(arr[j][i] == arr[j][i+1])
                        {
                            if (!shifted[j][i] && !shifted[j][i+1])
                            {
                                arr[j][i] = 2*arr[j][i];
                                arr[j][i+1] = 0;
                                shifted[j][i] = true;
                            }
                        }
                    }
                }
            }

        }
        else if(dir == "up")
        {
            for (k = 1; k <= n; k++)
            {
                for (i = 0; i < n-1; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        if (arr[i][j] == 0)
                        {
                            arr[i][j] = arr[i+1][j];
                            arr[i+1][j] = 0;
                        }
                        else if(arr[i][j] == arr[i+1][j])
                        {
                            if (!shifted[i][j] && !shifted[i+1][j])
                            {
                                arr[i][j] = 2*arr[i][j];
                                arr[i+1][j] = 0;
                                shifted[i][j] = true;
                            }
                        }
                    }
                }
            }

        }
        else
        {
            for (k = 1; k <= n; k++)
            {
                for (i = n-1; i >= 0; i--)
                {
                    for (j = 0; j < n; j++)
                    {
                        if (arr[i][j] == 0)
                        {
                            arr[i][j] = arr[i-1][j];
                            arr[i-1][j] = 0;
                        }
                        else if(arr[i][j] == arr[i-1][j])
                        {
                            if (!shifted[i][j] && !shifted[i-1][j])
                            {
                                arr[i][j] = 2*arr[i][j];
                                arr[i-1][j] = 0;
                                shifted[i][j] = true;
                            }
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<s<<": "<<endl;
        forall(i, 0, n)
        {
            forall(j, 0, n)
            {
                cout << arr[i][j] << " ";
            }
            cout<<endl;
        }
    }
    return 0;
}

