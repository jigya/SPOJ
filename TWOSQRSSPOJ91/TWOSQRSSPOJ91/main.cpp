//
//  main.cpp
//  TWOSQRSSPOJ91
//
//  Use Fermats theorem
//  Created by Jigya Yadav on 17/08/14.
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



vector<int> PrimeSieve()
{
    vector<int> arr;
    vector<bool> prime(1000005,true);
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<=1000001;(i==2)?i++:i+=2)
    {
        if(prime[i])
        {
            for(int j=2;j*i<=1000001;j++)
            {
                prime[j*i]=false;
            }
            arr.push_back(i);
        }
    }
    return arr;
}

int main(int argc, const char * argv[])
{
    vector<int> primes=PrimeSieve();
    int t;
    bool flag;
    long long int n,i, cnt;
    scanf("%d",&t);
    while (t--)
    {
        flag=true;
        scanf("%lld",&n);
        if(n==0)
        {
            printf("Yes\n");
            continue;
        }
        for(i=0;i<primes.size();i++)
        {
            cnt=0;
            while(n%primes[i]==0)
            {
                n/=primes[i];
                if(primes[i]%4==3) cnt++;
            }
            if(cnt%2==1)
            {
                flag=false;
            }
        }
        if(flag && n%4!=3)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}


