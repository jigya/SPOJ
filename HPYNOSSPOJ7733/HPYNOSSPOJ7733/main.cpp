//
//  main.cpp
//  HPYNOSSPOJ7733
//
//  Created by Jigya Yadav on 17/08/14.
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

int isHappy(unsigned int n)
{
    vector<bool> visited(1000, false);
    int i,j,k;
    int sum=0;
    int cnt=0;
    bool hit=false;
    while(n>0)
    {
        sum=0;
        i=n;
        while(i)
        {
            j=i%10;
            sum+=j*j;
            i/=10;
        }
        if(visited[sum])
        {
            hit=true;
            break;
        }
        else
        {
            cnt++;
            visited[sum]=true;
        }
        if(sum==1)
        {
            break;
        }
        n=sum;
    }
    if(hit)
        return -1;
    else
        return cnt;
}

int main(int argc, const char * argv[])
{
    unsigned int n;
    scanf("%u",&n);
//    for(n=2;n<= 2147483647;n++)
    printf("%d\n",isHappy(n));
    return 0;
}

