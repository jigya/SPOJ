////
////  main.cpp
////  NBINSPOJ19561
////
////  Created by Jigya Yadav on 14/01/15.
////  Copyright (c) 2015 Jigya Yadav. All rights reserved.
////
//
//#include<cstdio>
//#include<iostream>
//#include<vector>
//#include<map>
//#include<set>
//#include<stack>
//#include<queue>
//#include<algorithm>
//#include<cmath>
//#include<string>
//#include<cstdlib>
//#include<climits>
//#include<cstring>
//#include<fstream>
//#include <sstream>
//#define ll long long int
//
//// Input macros
//#define s(n)                        scanf("%d",&n)
//#define sc(n)                       scanf("%c",&n)
//#define sl(n)                       scanf("%lld",&n)
//#define sf(n)                       scanf("%lf",&n)
//#define ss(n)                       scanf("%s",n)
//
//// Useful constants
//#define INF                         (int)1e9
//#define EPS                         1e-9
//
//// Useful hardware instructions
//#define bitcount                    __builtin_popcount
//#define gcd                         __gcd
//
//// Useful container manipulation / traversal macros
//#define forall(i,a,b)               for(int i=a;i<b;i++)
//#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
//#define all(a)                      a.begin(), a.end()
//#define in(a,b)                     ( (b).find(a) != (b).end())
//#define pb                          push_back
//#define fill(a,v)                    memset(a, v, sizeof a)
//#define sz(a)                       ((int)(a.size()))
//#define mp                          make_pair
//
//// Some common useful functions
//#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
//#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
//#define checkbit(n,b)                ( (n >> b) & 1)
//#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
//#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
//
//using namespace std;
//#define LIMITFIB 1000000000000000
//
//ll fibonacci[100];
//ll sumFibonacci[100];
//
//int main(int argc, const char * argv[])
//{
//    int i, j, k, t, numBits;
//    ll m, n, p, q, r;
//    fibonacci[1] = 1;
//    fibonacci[2] = 1;
//    fibonacci[3] = 2;
//    i = 4;
//    do
//    {
//        fibonacci[i] = fibonacci[i-1]+fibonacci[i-2];
//        i++;
//    }while (fibonacci[i-1] <= LIMITFIB);
//    sumFibonacci[1] = 1;
//    sumFibonacci[2] = 2;
//    i = 3;
//    do
//    {
//        sumFibonacci[i] = sumFibonacci[i-1] + fibonacci[i];
//        i++;
//    }while(sumFibonacci[i-1] <= LIMITFIB);
//    k = i;
//    for (i = 1; i <= k; i++)
//    {
//        cout<<i<<" "<<fibonacci[i]<<" "<<sumFibonacci[i]<<endl;
//    }
//    
//    
//    scanf("%d", &t);
//    while (t--)
//    {
//        scanf("%lld", &n);
//        numBits = lower_bound(sumFibonacci+1, sumFibonacci+k, n) - (sumFibonacci);
//        
//    }
//    return 0;
//}
//


#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main(){
	ll memo_sum[82];
	memo_sum[0] = 2; memo_sum[1] = 3;
    
	for(int i=2; i<82; i++){
		memo_sum[i] = memo_sum[i-1] + memo_sum[i-2];
	}
    
	int t;
	scanf("%i", &t);
	while(t--){
		ll n;
		scanf("%lli", &n);
		n++;
		ll *it = lower_bound(memo_sum, memo_sum+82, n);
		int len = (it - memo_sum) + 1, i = 2;
		char ans[len+1];
		ans[0] = '1'; ans[1] = '0';
		ans[len] = '\0';
		ll curr = n - *(it-1);
		while (i < len) {
			it = lower_bound(memo_sum, memo_sum+82, curr);
			int len2 = (it - memo_sum) + 1;
			for (; i + len2 < len; i++) {
				ans[i] = '0';
			}
			if (curr == 1) {
				ans[i] = '0';
			}
			else if (curr == 2) {
				ans[i] = '1';
			}
			else {
				ans[i] = '1';
				if (i+1 < len)
					ans[i+1] = '0';
			}
			i += 2;
			curr = curr - *(it - 1);
		}
		printf("%s\n", ans);
        
	}
	return 0;
}