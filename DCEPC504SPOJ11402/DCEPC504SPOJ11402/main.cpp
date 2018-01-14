//
//  main.cpp
//  DCEPC504SPOJ11402
//
//  Created by Jigya Yadav on 03/11/14.
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

string find(int n, long long int k)
{
    if (k == 1 && n == 1)
    {
        return "Male";
    }
    long long int par = (k+1)/2;
    string y = find(n-1, par);
    if (par*2 == k+1)
    {
        return y;
    }
    else if(par*2 == k)
    {
        if(y == "Male")
        {
            return "Female";
        }
        else
        {
            return "Male";
        }
    }
    return "Male";
}

int main(int argc, const char * argv[])
{
    int t, m, n;
    long long int k;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%lld", &n, &k);
        cout<<find(n, k)<<endl;
    }
    return 0;
}

