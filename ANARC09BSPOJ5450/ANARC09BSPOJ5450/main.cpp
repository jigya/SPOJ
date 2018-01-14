//
//  main.cpp
//  ANARC09BSPOJ5450
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

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}

int main(int argc, const char * argv[])
{
    int m, n;
    while(1)
    {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0)
        {
            break;
        }
        long long int product = (ll)m * n;
        long long int g = gcd(m, n);
        product = product/g;
        product = product/g;
        printf("%lld\n", product);
    }
    return 0;
}

