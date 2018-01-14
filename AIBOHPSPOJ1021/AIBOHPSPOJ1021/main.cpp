//
//  main.cpp
//  AIBOHPSPOJ1021
//
//  Created by Jigya Yadav on 27/08/14.
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

short arr[6105][6105];
int main(int argc, const char * argv[])
{
    int i,j,k,t,m,n;
    string str, str2, str3;
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        int len=str.length();
        str3="";
        for(string::reverse_iterator rtr=str.rbegin();rtr!=str.rend();rtr++)
        {
            str3+=*rtr;
        }
        for(i=0;i<=len;i++)
        {
            for(j=0;j<=len;j++)
            {
                if(i==0 || j==0)
                {
                    arr[i][j]=0;
                }
                else if(str[i-1]==str3[j-1])
                {
                    arr[i][j]=arr[i-1][j-1]+1;
                }
                else
                {
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        printf("%d\n",len-arr[len][len]);
    }
    return 0;
}

