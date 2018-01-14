//
//  main.cpp
//  EDISTSPOJ6219
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

int main(int argc, const char * argv[])
{
    int t,i,j,k;
    string str1, str2;
    scanf("%d",&t);
    while(t--)
    {
        cin>>str1>>str2;
        vector< vector<int> > arr(str1.length()+5, vector<int>(str2.length()+5, 0));
        int len1=str1.length();
        int len2=str2.length();
        for(i=0;i<=len1;i++)
        {
            for(j=0;j<=len2;j++)
            {
                if(i==0)
                {
                    arr[i][j]=j;
                }
                else if(j==0)
                {
                    arr[i][j]=i;
                }
                else
                {
                    if(str1[i-1]==str2[j-1])
                    {
                        k=0;
                    }
                    else
                    {
                        k=1;
                    }
                    arr[i][j]=min(arr[i-1][j-1]+k, min(arr[i-1][j]+1, arr[i][j-1]+1));
                }
            }
        }
        printf("%d\n", arr[len1][len2]);
    }
    return 0;
}

