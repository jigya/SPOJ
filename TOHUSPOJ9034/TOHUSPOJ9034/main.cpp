//
//  main.cpp
//  TOHUSPOJ9034
//
//  Created by Jigya Yadav on 06/11/14.
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
    int n, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        double sum = ((double)2/3);
        if (n > 1)
        {
            double sum1 = 0.5*(1.0/2)*(1.0/3);
            double sum2 = 0.5*(1.0/(n+1))*(1.0/(n+2));
            sum += abs(sum1-sum2);
        }
        printf("%.11lf\n", sum);
    }
    return 0;
}

