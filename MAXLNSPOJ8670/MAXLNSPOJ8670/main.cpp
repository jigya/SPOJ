//
//  main.cpp
//  MAXLNSPOJ8670
//
//  Created by Jigya Yadav on 13/08/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <sstream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    int n,i,r;
    scanf("%d",&n);
    double rslt;
    double constVal=.25;
    for(i=0;i<n;i++)
    {
        scanf("%d",&r);
        rslt=4.0*(double)r*r+constVal;
        printf("Case %d: %.2lf\n", i+1, rslt);
    }
    return 0;
}

