//
//  main.cpp
//  GCD2SPOJ2906
//
//  Created by Jigya Yadav on 26/08/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main(int argc, const char * argv[])
{
    int t,i,k,a;
    string str;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&a);
        cin>>str;
        if(a==0)
        {
            cout<<str<<endl;
            continue;
        }
        k=(str[0]-'0')%a;
        for(i=1;i<str.length();i++)
        {
            k=(k*10+(str[i]-'0'))%a;
        }
        printf("%d\n",gcd(a,k));
    }
    return 0;
}

