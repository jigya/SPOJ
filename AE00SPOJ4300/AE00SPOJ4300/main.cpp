//
//  main.cpp
//  AE00SPOJ4300
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
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
#include<fstream>

#define ll long long int

using namespace std;

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t;
    scanf("%d", &n);
    ll cnt = 1;
    for (i = 2; i <= n; i++)
    {
        m = i;
        int ans = 0;
        for (j = 1; j*j <= m; j++)
        {
            if (m%j == 0)
            {
                ans++;
            }
        }
//        cout<<i<<" "<<ans<<endl;
        cnt += ans;
    }
    printf("%lld\n", cnt);
    return 0;
}

