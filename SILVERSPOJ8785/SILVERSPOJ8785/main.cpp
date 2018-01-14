//
//  main.cpp
//  SILVERSPOJ8785
//
//  http://mathbyvemuri.blogspot.in/2011/12/puzzle-31.html
//  Created by Jigya Yadav on 18/08/14.
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
    int i,j,t;
    scanf("%d",&t);
    while(t!=0)
    {
        i=int(log(t)/log(2));
        printf("%d\n",i);
        scanf("%d",&t);
    }
    return 0;
}

