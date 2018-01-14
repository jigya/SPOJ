//
//  main.cpp
//  HISTOGRASPOJ1805
//
//  Created by Jigya Yadav on 31/08/14.
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

int main(int argc, const char * argv[])
{
    int t,i,j,n;
    scanf("%d",&t);
    while(t!=0)
    {
        vector<int> arr;
        vector<long long int> area(t+5,0);
        for(i=0;i<t;i++)
        {
            scanf("%d",&j);
            arr.push_back(j);
        }
        stack<int> st;
        for(i=0;i<t;i++)
        {
            while(!st.empty())
            {
                if(arr[i]<=arr[st.top()])
                {
                    st.pop();
                }
                else
                    break;
            }
            if(st.empty())
            {
                n=-1;
            }
            else
            {
                n=st.top();
            }
            area[i]=i-n-1;
            st.push(i);
        }
//        for(i=0;i<t;i++)
//            cout<<area[i]<<" ";
//        cout<<endl;
        while(!st.empty())
        {
            st.pop();
        }
        for(i=t-1;i>=0;i--)
        {
            while(!st.empty())
            {
                if(arr[i]<=arr[st.top()])
                {
                    st.pop();
                }
                else
                    break;
            }
            if(st.empty())
            {
                n=t;
            }
            else
            {
                n=st.top();
            }
            area[i]+=n-i-1;
            st.push(i);
        }
//        for(i=0;i<t;i++)
//            cout<<area[i]<<" ";
//        cout<<endl;
        for(i=0;i<t;i++)
        {
            
            area[i]=(area[i]+1)*arr[i];
        }
        long long int maxArea=-1;
        for(i=0;i<t;i++)
            maxArea=max(area[i],maxArea);
        printf("%lld\n",maxArea);
        scanf("%d",&t);
    }
    return 0;
}

