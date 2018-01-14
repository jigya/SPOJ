//
//  main.cpp
//  PasswordAttacker
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

#define MOD 1000000007

using namespace std;

long long int modFactorial(int a)
{
    ll fact = 1;
    forall(i, 1, a+1)
    {
        fact = (fact*i)%MOD;
    }
//    cout<<"fact="<<fact<<endl;
    return fact;
}

int main(int argc, const char * argv[])
{
    freopen("/Users/jigyayadav/downloads/A-large-practice.in.txt", "r", stdin);
    freopen("/Users/jigyayadav/downloads/PasswordAttackerLargeOut.txt", "w", stdout);
    int t, k, n;
    cin >> t;
    ll arr[110][110];
    forall(s, 1, t+1)
    {
        cin >> k >> n;
        memset(arr, 0, sizeof(arr));
        arr[0][0] = 1;
        forall(i, 0, n+1)
        {
            forall(j, 0, k+1)
            {
                if((i == 0 && j == 0) || (j > i))
                {
                }
                else if(j == 0)
                {
                    arr[i][j] = 0;
                }
                else
                {
                    arr[i][j] = (arr[i-1][j-1]%MOD+((j%MOD)*(arr[i-1][j]%MOD))%MOD)%MOD;
                }
//                cout<<arr[i][j]<<" ";
            }
//            cout<<endl;
        }
//        cout<<arr[n][k]<<endl;
        ll ans = (arr[n][k]*modFactorial(k))%MOD;
        cout<<"Case #"<<s<<": "<<ans<<endl;
    }
    return 0;
}

