//
//  main.cpp
//  LastDig2SPOJ5699
//
//  Created by Jigya Yadav on 13/08/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//


#include <iostream>
#include <stdio.h>

using namespace std;

long long int modulo(long long int a,long long int b,int c){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c;
        b /= 2;
    }
    return x%c;
}

int main(int argc, const char * argv[])
{
    string a;
    long long int b;
    int n,i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        cin>>a;
        scanf("%lld",&b);
        int lastInt=a[a.length()-1]-'0';
        printf("%lld\n", modulo(lastInt, b, 10));
    }
    return 0;
}

