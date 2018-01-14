//
//  main.cpp
//  JNEXTSPOJ12150
//
//  Created by Jigya Yadav on 22/12/14.
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
    int i, k, m, n, t;
    char j;
    scanf("%d", &t);
    char arr[1000100];
    while (t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &k);
            arr[i] = (char)('0'+k);
        }
        k = -1;
        for (i = 0; i < n-1; i++)
        {
            if (arr[i] < arr[i+1])
            {
                k = i;
            }
        }
        if (k == -1)
        {
            printf("-1\n");
            continue;
        }
        m = k+1;
        for (i = k+1; i < n; i++)
        {
            if (arr[i] > arr[k])
            {
                m = i;
            }
        }
        j =  arr[k];
        arr[k] = arr[m];
        arr[m] = j;
        reverse(arr+k+1, arr+n);
        for (i = 0; i < n; i++)
        {
            printf("%c", arr[i]);
        }
        printf("\n");
    }
    return 0;
}

