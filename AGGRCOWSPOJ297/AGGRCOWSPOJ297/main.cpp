//
//  main.cpp
//  AGGRCOWSPOJ297
//
//  Created by Jigya Yadav on 28/08/14.
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
#include <fstream>

using namespace std;

int ans;

int largestMinDistance(int lo, int hi, vector<int> arr, int n, int numCows)
{
    int mid,i,currDist,cnt;
    while(lo<hi)
    {
        mid=lo+(hi-lo+1)/2;
//        cout<<mid<<endl;
        currDist=0;
        cnt=0;
        for(i=1;i<n;i++)
        {
            currDist+=arr[i]-arr[i-1];
            if(currDist>=mid)
            {
                cnt++;
                currDist=0;
            }
        }
//        cout<<"cnt="<<cnt<<endl;
        if(cnt>=numCows-1)
        {
            lo=mid;
        }
        else
        {
            hi=mid-1;
        }
    }
    return lo;
}


int main(int argc, const char * argv[])
{
    int t,i,j,m,n,c;
    scanf("%d",&t);
    vector<int> arr(100005);
    while(t--)
    {
        arr.clear();
        scanf("%d%d",&n,&c);
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            arr.push_back(j);
        }
        sort(arr.begin(), arr.end());
        m=arr[n-1]-arr[0];
        ans=0;
        printf("%d\n",largestMinDistance(1, m, arr, n, c));
    }
    return 0;
}

