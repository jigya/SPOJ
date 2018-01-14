//
//  main.cpp
//  OLOLOSPOJ7742
//
//  Created by Jigya Yadav on 14/08/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    int n,i,j;
    int rslt=1;
    scanf("%d",&n);
    scanf("%d",&j);
    rslt=j;
    for(i=1;i<n;i++)
    {
        scanf("%d",&j);
        rslt^=j;
    }
    printf("%d\n",rslt);
    return 0;
}

