//
//  main.cpp
//  MYQ1SPOJ10639
//
//  Created by Jigya Yadav on 04/11/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

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
    int t, seat_pos;
    char direction;
    long long int n, m;
    scanf("%d", &t);
    char arr[5];
    arr[0]='W';
    arr[1]='A';
    arr[2]='A';
    arr[3]='M';
    arr[4]='W';
    while (t--)
    {
        scanf("%lld", &n);
        if (n == 1)
        {
            printf("poor conductor\n");
            continue;
        }
        m = (n-2);
        int rowno = m/5;
        int pos = (rowno*5);
        if (rowno&1)
        {
            seat_pos = (4-m+pos);
            if (m <= pos+2)
            {
                direction = 'R';
            }
            else
            {
                direction = 'L';
            }
        }
        else
        {
            seat_pos = (m-pos);
            if (m <= pos+1)
            {
                direction = 'L';
            }
            else
            {
                direction = 'R';
            }
        }
        printf("%d %c %c\n", (rowno+1), arr[seat_pos], direction);
//        cout<<rowno+1<<" "<<arr[seat_pos]<<" "<<direction<<endl;
    }
    return 0;
}

