//
//  main.cpp
//  UCV2013ESPOJ5433
//
//  Created by Jigya Yadav on 04/02/15.
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

#define MOD 1000000007

using namespace std;


long long int fast(long long int a, long long int n) {
	if (n == 0) return 1;
	else if (n == 1) return a;
	long long int b = fast(a, n / 2);
	
	b = (b * b) % MOD;
	
	if (n & 1) {
		b = (b * a) % MOD;
	}
	
	return b;
}
ll inverseEuler(ll n)
{
    ll k = fast(n, MOD-2);
//    cout<<"called with "<<n<<": "<<k<<endl;
    return k;
}

int main(int argc, const char * argv[])
{
    int n;
    int start[55];
    int finish[55];
    int diff[55];
    ll f[30000];
    ll inv[55];
    while (1)
    {
        ll sum_diff = 0;
        s(n);
        if(n == 0)
        {
            break;
        }
        forall(i, 1, n+1)
        {
            s(start[i]);
        }
        forall(i, 1, n+1)
        {
            s(finish[i]);
            diff[i] = abs(finish[i]-start[i]);
            sum_diff += diff[i];
        }
//        cout<<sum_diff<<endl;
        f[0] = 1;
        f[1] = 1;
        forall(i, 2, sum_diff+1)
        {
            f[i] = (f[i-1]*i)%MOD;
//            cout<<f[i]<<" ";
        }
//        cout<<endl;
        ll ans = f[sum_diff];
        forall(i, 1, n+1)
        {
                inv[i] = inverseEuler(f[diff[i]]);
//                cout<<inv[i]<<endl;
            ans = (ans*inv[i])%MOD;
        }
//        cout<<endl;
        printf("%lld\n", ans);
    }
    return 0;
}

