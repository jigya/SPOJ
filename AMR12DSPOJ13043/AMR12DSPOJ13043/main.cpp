//
//  main.cpp
//  AMR12DSPOJ13043
//
//  Created by Jigya Yadav on 04/09/14.
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
#include <queue>

using namespace std;

int main(int argc, const char * argv[])
{
    int t,i;
    string s;
    scanf("%d",&t);
    while (t--)
    {
        bool flag=true;
        cin>>s;
        int len=s.length();
        for(i=0;i<len;i++)
        {
            if(s[i]!=s[len-1-i])
            {
                flag=false;
                break;
            }
        }
        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

