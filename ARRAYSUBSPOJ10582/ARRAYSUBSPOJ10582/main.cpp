//
//  main.cpp
//  ARRAYSUBSPOJ10582
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

int main(int argc, const char * argv[])
{
    vector<int> arr;
    deque<int> d;
    int n,k,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&j);
        arr.push_back(j);
    }
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        while(!d.empty() && arr[i]>=arr[d.back()])
        {
            d.pop_back();
        }
        d.push_back(i);
    }
//    for(deque<int>::iterator itr=d.begin();itr!=d.end();itr++)
//        cout<<*itr<<" ";
//    cout<<endl;
    for(i=k;i<n;i++)
    {
        printf("%d ",arr[d.front()]);
        while(!d.empty() && arr[i]>=arr[d.back()])
        {
            d.pop_back();
        }
        while (!d.empty() && d.front()<=i-k)
        {
            d.pop_front();
        }
        d.push_back(i);
//        for(deque<int>::iterator itr=d.begin();itr!=d.end();itr++)
//            cout<<*itr<<" ";
//        cout<<endl;
    }
    printf("%d\n",arr[d.front()]);
    return 0;
}

