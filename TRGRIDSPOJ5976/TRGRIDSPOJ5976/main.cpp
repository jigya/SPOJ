//
//  main.cpp
//  TRGRIDSPOJ5976
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
    int t,i,j,k,m,n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        if(n==1)
        {
            printf("R\n");
            continue;
        }
        if(m==1)
        {
            printf("D\n");
            continue;
        }
        if(n==2)
        {
            printf("L\n");
            continue;
        }
        if(m==2)
        {
            printf("U\n");
            continue;
        }
        int minDimension=min(n,m);
        
        //minDimension is odd
        if(minDimension&1)
        {
            n-=(minDimension-1);
            m-=(minDimension-1);
            if(n==1)
            {
                printf("R\n");
                continue;
            }
            if(m==1)
            {
                printf("D\n");
                continue;
            }
            if(n==2)
            {
                printf("L\n");
                continue;
            }
            if(m==2)
            {
                printf("U\n");
                continue;
            }
        }
        else
        {
            n-=(minDimension-2);
            m-=(minDimension-2);
            if(n==1)
            {
                printf("R\n");
                continue;
            }
            if(m==1)
            {
                printf("D\n");
                continue;
            }
            if(n==2)
            {
                printf("L\n");
                continue;
            }
            if(m==2)
            {
                printf("U\n");
                continue;
            }
        }
    }
    return 0;
}

