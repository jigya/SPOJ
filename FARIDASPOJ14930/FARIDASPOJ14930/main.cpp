//
//  main.cpp
//  FARIDASPOJ14930
//
//  Created by Jigya Yadav on 04/11/14.
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

using namespace std;

int main(int argc, const char * argv[])
{

    int t, i, j, k, n;
    int monsters[10100];
    long long int money[10100][2];
    scanf("%d", &t);
    for (k = 1; k <= t; k++)
    {
        scanf("%d", &n);
        if(n==0)
        {
            cout<<"Case "<<k<<": "<<"0"<<endl;
            continue;
        }
        for (i = 0; i < n; i++)
        {
            scanf("%d", &j);
            monsters[i] = j;
        }
        money[0][0] = 0;
        money[0][1] = monsters[0];
        for (i = 1; i < n; i++)
        {
            money[i][0] = max(money[i-1][0], money[i-1][1]);
            money[i][1] = money[i-1][0]+monsters[i];
        }
//        for (i = 0; i < n; i++)
//        {
//            for (j = 0; j < 2; j++)
//            {
//                cout<<money[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<"Case "<<k<<": "<<max(money[n-1][0], money[n-1][1])<<endl;
    }
    return 0;
}

