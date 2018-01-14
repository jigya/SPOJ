//
//  main.cpp
//  MIXTURESSPOJ345
//
//  Created by Jigya Yadav on 29/08/14.
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

int main(int argc, const char * argv[])
{
    int t,i,j,k,m,n,l;
    while(cin>>n)
    {
        vector<int> arr;
        for(i=0;i<n;i++)
        {
            cin>>j;
            arr.push_back(j);
        }
        vector< vector<int> > smoke(n+5, vector<int>(n+5,0) );
        vector< vector<int> > values(n+5, vector<int>(n+5, 0) );
        for(i=1;i<=n;i++)
        {
            values[i][i]=arr[i-1];
            smoke[i][i]=0;
        }
        for(i=1;i<=n;i++)
        {
            values[i][i+1]=(arr[i-1]+arr[i])%100;
            smoke[i][i+1]=(arr[i-1]*arr[i]);
        }
        for(l=3;l<=n;l++)
        {
            for(i=0;i<=n-l+1;i++)
            {
                j=i+l-1;
                smoke[i][j]=INT_MAX;
                for(k=i;k<=j-1;k++)
                {
                    m=smoke[i][k]+smoke[k+1][j]+(values[i][k]*values[k+1][j]);
                    if(m<smoke[i][j])
                    {
                        smoke[i][j]=m;
                        values[i][j]=(values[i][k]+values[k+1][j])%100;
                    }
                }
            }
        }
        cout<<smoke[1][n]<<endl;
    }
    return 0;
}

