//
//  main.cpp
//  ROADNETSPOJ178
//
//  Created by Jigya Yadav on 05/09/14.
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
    int t,i,j,k, n;
    bool flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        vector< vector<bool> > neighbours( n+5, vector<bool>(n+5, false));
        vector< vector<int> > distance( n+5, vector<int>(n+5, false));
        for (i = 1; i <= n; i++)
        {
            for ( j = 1; j <= n; j++)
            {
                scanf("%d", &distance[i][j]);
            }
        }
        for(i = 1; i <= n; i++)
        {
            for( j = i+1; j <= n; j++)
            {
                if( i == j)
                    continue;
                flag = false;
                for( k = 1 ; k <= n ; k++)
                {
                    if( k == i || k == j)
                        continue;
                    if (distance[i][j]==distance[i][k]+distance[k][j])
                    {
                        flag = true;
                        break;
                    }
                }
                if( flag == false )
                {
                    neighbours[i][j] = true;
                }
            }
        }
        for( i = 1 ; i <= n; i++ )
        {
            for ( j=1 ; j <= n ; j++ )
            {
                if(neighbours[i][j])
                {
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
    }
    return 0;
}

