//
//  main.cpp
//  HOTELSSPOJ9861
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

vector<int> arr(300005,0);
int main(int argc, const char * argv[])
{
    int n,i,j,k;
    long long int m;
    scanf("%d%lld",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&j);
        arr.push_back(j);
    }
    i=0;
    long long int sum=0;
    long long int maxVal=INT_MIN;
    int start_idx=0, end_idx=0;
    while(end_idx<n && sum<=m)
    {
        sum+=arr[end_idx];
        end_idx++;
    }
    if(sum>m && end_idx>n)
    {
        sum-=arr[end_idx-1];
    }
    else if(sum>m)
    {
        sum-=arr[end_idx];
    }
    maxVal=sum;
    cout<<maxVal<<" "<<sum<<endl;
    while(start_idx<n && end_idx<n)
    {
        sum+=arr[end_idx];
        while(start_idx<=end_idx && sum>m)
        {
            sum-=arr[start_idx++];
        }
        maxVal=max(maxVal,sum);
        end_idx++;
    }
    printf("%lld\n",maxVal);
    return 0;
}

