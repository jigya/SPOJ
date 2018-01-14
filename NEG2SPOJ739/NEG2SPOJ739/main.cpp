//
//  main.cpp
//  NEG2SPOJ739
//
//  Created by Jigya Yadav on 29/08/14.
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

int main(int argc, const char * argv[])
{
    int t,i,j,rem;
    vector<char> arr;
    scanf("%d",&t);
    if(t==0)
    {
        printf("0");
    }
    while(t!=0)
    {
        rem=t%-2;
        t=t/-2;
        if(rem<0)
        {
            rem+=2;
            t+=1;
        }
        arr.push_back(rem+'0');
    }
    for(vector<char>::reverse_iterator itr=arr.rbegin();itr!=arr.rend();itr++)
    {
        printf("%c",*itr);
    }
    printf("\n");
    return 0;
}

