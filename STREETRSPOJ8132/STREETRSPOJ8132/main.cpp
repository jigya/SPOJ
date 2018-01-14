//
//  main.cpp
//  STREETRSPOJ8132
//
//  Created by Jigya Yadav on 03/09/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stack>

using namespace std;

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b, a%b);
}

int main(int argc, const char * argv[])
{
    int n,i,j,k;
    scanf("%d",&n);
    vector<int> arr;
    for(i=0;i<n;i++)
    {
        scanf("%d",&j);
        arr.push_back(j);
    }
    int ans=arr[1]-arr[0];
    for(i=2;i<n;i++)
    {
        ans=gcd(ans, arr[i]-arr[i-1]);
    }
    int numTrees=0;
    for(i=1;i<n;i++)
    {
        numTrees+=(arr[i]-arr[i-1])/ans-1;
    }
    printf("%d\n",numTrees);
    return 0;
}

