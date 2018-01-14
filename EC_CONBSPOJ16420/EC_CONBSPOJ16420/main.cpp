//
//  main.cpp
//  EC_CONBSPOJ16420
//
//  Created by Jigya Yadav on 17/12/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//
//  Reverse bits of a number
//  http://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
#include<fstream>

using namespace std;

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t;
    unsigned int a;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%u", &a);
        if (a&1)
        {
            printf("%u\n", a);
        }
        else
        {
            unsigned int rev_num = 0;
            unsigned int num =  a;
            while (num)
            {
//                cout<<num<<" "<<(num&1)<<endl;
                rev_num |= num&1;
                num >>= 1;
                rev_num <<= 1;
            }
            rev_num >>= 1;
            printf("%u\n", rev_num);
        }
    }
    return 0;
}

