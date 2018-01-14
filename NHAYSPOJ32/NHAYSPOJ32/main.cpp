//
//  main.cpp
//  NHAYSPOJ32
//
//  Created by Jigya Yadav on 28/08/14.
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


vector<int> buildFailureFunction(char* pattern)
{
    int len=strlen(pattern);
    vector<int> arr(len+1);
    int i=0,j;
    while(i<len)
    {
        while(true)
        {
            j=arr[i-1];
            if(pattern[i-1]==pattern[j])
            {
                arr[i]=j+1;
                break;
            }
            if(j==0)
            {
                arr[i]=0;
                break;
            }
            j=arr[j];
        }
    }
    return arr;
}

int main(int argc, const char * argv[])
{
    int n,t;
    char *pattern;
    scanf("%d",&t);
    char c;
    while(t--)
    {
        scanf("%d",&n);
        pattern=(char *)malloc(sizeof(char)*(n+5));
        gets(pattern);
        vector<int> failureArray=buildFailureFunction(pattern);
        int i=0,j=0;
        c=getchar();
        cout<<c<<endl;
        while(1)
        {
            if(pattern[i]==c)     //If the characters match
               {
                   i++;
                   j++;
                   c=getchar();
                   if(i==n)
                   {
                       printf("%d\n",j-n);
                   }
               }
               else if(i>0)        //Check largest possible suffix/prefix
               {
                   i=failureArray[i];
               }
               else                //Empty pattern string-jump this character in the text
               {
                   j++;
                   c=getchar();
               }
            if(c=='\n')
            {
                break;
            }
        }
        printf("\n");
    }
    return 0;
}

