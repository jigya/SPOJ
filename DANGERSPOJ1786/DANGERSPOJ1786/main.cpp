//
//  main.cpp
//  DANGERSPOJ1786
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
#include <cmath>
#include <stack>

using namespace std;


int main(int argc, const char * argv[])
{
    string str;
    int r,i,j,k,ans;
    cin>>str;
    while(str!="00e0")
    {
        r=str[0]-'0';
        r=r*10+(str[1]-'0');
        for(i=1;i<=str[3]-'0';i++)
        {
            r*=10;
        }
        ans=2*(r-pow(2,(int)log2(r)))+1;
        printf("%d\n",ans);
        cin>>str;
    }
    return 0;
}

