//
//  main.cpp
//  TOANDFROSPOJ400
//
//  Created by Jigya Yadav on 20/01/15.
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

int main(int argc, const char * argv[])
{
    int i, j, k, t, m, n;
    s(t);
    char arr[120][30];
    char arr2[120][30];
    char str[250];
    while (1)
    {
        s(t);
        if (t == 0)
        {
            break;
        }
        ss(str);
        n = strlen(str);
        
        j = 0;
        k = 0;
        forall(i, 0, n)
        {
            arr[j][k] = str[i];
            k++;
            if (k == t)
            {
                k = 0;
                j++;
            }
        }
//        forall(i, 0, n/t)
//        {
//            forall(j, 0, t)
//            {
//                cout<<arr[i][j];
//            }
//            cout<<endl;
//        }
        int y = 0;
        forall(i, 0, n/t)
        {
            if (y == 0)
            {
                forall(k, 0, t)
                {
                    arr2[i][k] = arr[i][k];
                }
            }
            else
            {
                forall(k, 0, t)
                {
                    arr2[i][k] = arr[i][t-1-k];
                }
            }
            y = !y;
        }
//        forall(i, 0, n/t)
//        {
//            forall(j, 0, t)
//            {
//                cout<<arr2[i][j];
//            }
//            cout<<endl;
//        }
        forall(i, 0, t)
        {
                forall(k, 0, n/t)
                {
                    printf("%c", arr2[k][i]);
                }

        }
        printf("\n");
    }
    return 0;
}

