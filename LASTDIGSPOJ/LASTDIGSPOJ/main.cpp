//
//  main.cpp
//  LASTDIGSPOJ
//
//  Created by Jigya Yadav on 25/06/15.
//  Copyright (c) 2015 Jigya Yadav. All rights reserved.
//

#include<cstdio>
#define ll long long int
#define sl(n)                       scanf("%lld",&n)
using namespace std;
ll modulo(ll a,ll b)
{
    ll x=1,y=a;
    while(b > 0)
    {if(b%2 == 1)
        {x=(x*y)%10;}
        y = (y*y)%10;
        b /= 2;}
    return x%10;
}
int main(int argc, const char * argv[])
{
    int t;ll a, b;scanf("%d", &t);
    while (t--)
    {
        sl(a);
        sl(b);
        if(a == 0 && b == 0)
        {printf("1\n");}
        else if (a == 0)
        {printf("0\n");}
        else if(b == 0)
        {printf("1\n");}
        else
        {printf("%lld\n", modulo(a, b));}
    }
    return 0;
}
