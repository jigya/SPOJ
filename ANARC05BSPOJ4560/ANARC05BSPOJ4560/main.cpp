//
//  main.cpp
//  ANARC05BSPOJ4560
//
//  Created by Jigya Yadav on 19/08/14.
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

int main(int argc, const char * argv[])
{
    int n1,n2,i,j,k;
    scanf("%d",&n1);
    while(n1!=0)
    {
        vector<int> arr1;
        vector<int> arr2;
        long long int sum1=0;
        long long int sum2=0;
        long long int sum=0;
        for(i=0;i<n1;i++)
        {
            scanf("%d",&k);
            arr1.push_back(k);
        }
        scanf("%d",&n2);
        for(i=0;i<n2;i++)
        {
            scanf("%d",&k);
            arr2.push_back(k);
        }
        i=j=0;
        while(i<n1 && j<n2)
        {
            if(arr1[i]<arr2[j])
            {
                sum1+=arr1[i++];
            }
            else if(arr1[i]>arr2[j])
            {
                sum2+=arr2[j++];
            }
            else if(arr1[i]==arr2[j])
            {
                sum+=max(sum1,sum2);
                sum+=arr1[i];
                sum1=sum2=0;
                i++;
                j++;
            }
        }
        while(i<n1)
        {
            sum1+=arr1[i++];
        }
        while(j<n2)
        {
            sum2+=arr2[j++];
        }
        sum+=max(sum1, sum2);
        printf("%lld\n",sum);
        scanf("%d",&n1);
    }
    return 0;
}

