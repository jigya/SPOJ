//
//  main.cpp
//  BYTESM2SPOJ3923
//
//  Created by Jigya Yadav on 16/08/14.
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
#include <sstream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    int i,j,k,t,h,w,a,b,c, max_val;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&h, &w);
        vector< vector<int> > arr(h+5, vector<int>(w+5, 0));
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        for(i=1;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                a=arr[i-1][j];
                if(j-1>=0)
                    b=arr[i-1][j-1];
                else
                    b=INT_MIN;
                if(j+1<w)
                    c=arr[i-1][j+1];
                else
                    c=INT_MIN;
                arr[i][j]=max(a, max(b,c))+arr[i][j];
            }
        }
//        for(i=0;i<h;i++)
//        {
//            for(j=0;j<w;j++)
//            {
//                cout<<arr[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        max_val=INT_MIN;
        for(i=0;i<w;i++)
        {
            max_val=max(max_val, arr[h-1][i]);
        }
        cout<<max_val<<endl;
    }
    return 0;
}

