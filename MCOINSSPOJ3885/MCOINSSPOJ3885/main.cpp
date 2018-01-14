//
//  main.cpp
//  MCOINSSPOJ3885
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

int main(int argc, const char * argv[])
{
    int k,l,t,n,i,j,m;
    scanf("%d%d%d",&k,&l,&m);
    
    //false means losing position, true is winning position
    vector<int> arr(1000010, false);
    arr[1]=true;
    arr[k]=true;
    arr[l]=true;
    bool ans;
    for(i=2;i<1000010;i++)
    {
        ans=false;
        if(i-1>=0)
        {
            ans=ans|(!arr[i-1]);
        }
        if(i-k>=0)
        {
            ans=ans|(!arr[i-k]);
        }
        if(i-l>=0)
        {
            ans=ans|(!arr[i-l]);
        }
        arr[i]=ans;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&n);
        if(arr[n]==true)
            printf("A");
        else
            printf("B");
    }
    return 0;
}

