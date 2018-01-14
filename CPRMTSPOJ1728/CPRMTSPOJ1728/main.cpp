//
//  main.cpp
//  CPRMTSPOJ1728
//
//  Created by Jigya Yadav on 19/08/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

//The question basically asks to find the common characters between the strings

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
    string str1, str2;
    while(cin>>str1>>str2)
    {
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        int i,j;
        i=j=0;
        string rslt;
        while(i<str1.length() && j<str2.length())
        {
            if(str1[i]<str2[j])
            {
                i++;
            }
            else if(str1[i]>str2[j])
            {
                j++;
            }
            else
            {
                rslt+=str1[i];
                i++;
                j++;
            }
        }
        cout<<rslt<<endl;
    }
    return 0;
}

