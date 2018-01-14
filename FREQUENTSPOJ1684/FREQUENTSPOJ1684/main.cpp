//
//  main.cpp
//  FREQUENTSPOJ1684
//
//  http://niceproblems.blogspot.in/2012/05/uva-11235-frequent-values.html
//  Created by Jigya Yadav on 23/12/14.
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

int arr[100100];
int cnt[100100];
int start[100100];
int segTree[1000000];

int segNodeCount;
//Build the segment tree from given array
void initialize(int lo, int hi, int pos)
{
    if(lo==hi)
    {
        segTree[pos]=cnt[lo];
        if(pos>segNodeCount)
            segNodeCount=pos;
    }
    else
    {
        int mid=lo+(hi-lo)/2;
        initialize(lo, mid, 2*pos+1);
        initialize(mid+1, hi, 2*pos+2);
        segTree[pos]=max(segTree[2*pos+1], segTree[2*pos+2]);
    }
}

//Get the minimum in the range "lowerLimit" to "upperLimit"
int getMax(int node, int lo, int hi, int lowerLimit, int upperLimit)
{
//    cout<<node<<" "<<lo<<" "<<hi<<endl;
    if((lowerLimit<=lo && hi<=upperLimit))
    {
        return segTree[node];
    }
    if(lowerLimit>hi || upperLimit<lo)
    {
        return INT_MIN;
    }
    int mid=lo+(hi-lo)/2;
    return max(getMax(node*2+1, lo, mid, lowerLimit, upperLimit), getMax(2*node+2, mid+1, hi, lowerLimit, upperLimit));
}

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t, q;
    scanf("%d", &n);
    while ( n != 0)
    {
        segNodeCount = -1;
        scanf("%d", &q);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
//        cout<<"here"<<endl;
        for (i = 0; i < n; )
        {
            j = i+1;
            while (j < n && arr[j] == arr[j-1])
            {
                j++;
            }
            for (k = i; k < j; k++)
            {
                cnt[k] = j - i;
                start[k] = i;
            }
            i = j;
        }
//        for (i = 0; i < n; i++)
//        {
//            cout<<arr[i]<<" "<<cnt[i]<<" "<<start[i]<<endl;
//        }
        initialize(0, n-1, 0);
        while (q--)
        {
            scanf("%d %d", &i, &j);
            if (arr[i-1] == arr[j-1])
            {
                cout<<(j-i+1)<<endl;
            }
            else
            {
                i--;
                j--;
                k = cnt[i]+start[i]-1;
                int cnt1 = cnt[i]+start[i]-i;
                int cnt2 = j-start[j]+1;
                int r1 = k+1;
                int r2 = start[j] - 1;
                int ans = max(cnt1, cnt2);
//                cout<<cnt1<<" "<<cnt2<<" "<<r1<<" "<<r2<<endl;
                if (r1 <= r2)
                {
//                    cout<<"calling"<<endl;
                    int cnt3 = getMax(0, 0, n-1, r1, r2);
                    ans = max(ans, cnt3);
                }
                cout<<ans<<endl;
            }
        }
        scanf("%d", &n);
    }
    return 0;
}

