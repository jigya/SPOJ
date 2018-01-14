//
//  main.cpp
//  FiboSumSPOJ8001
//  Has code for modular matrix exponentiation
//
//  http://fusharblog.com/solving-linear-recurrence-for-programming-contest/
//
//  http://www.mathblog.dk/uva-10229-modular-fibonacci/
//
//  Created by Jigya Yadav on 24/08/14.
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

#define ll long long
#define MOD 1000000007

const int K=2;


//Multiply two square matrices with dimensions K
vector< vector<ll> >  matrixMul( vector< vector<ll> > a, vector< vector<ll> > b)
{
    int i,j,k;
    vector< vector<ll> > arr(K, vector<ll>(K, 0));
    for(i=0;i<K;i++)
    {
        for(j=0;j<K;j++)
        {
            for(k=0;k<K;k++)
            {
                arr[i][j]=(arr[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
            }
        }
    }
    return arr;
}

//Modular matrix exponentiation
vector< vector<ll> > matrixExp(vector< vector<ll> > matrix, ll pow)
{
    if(pow==1)
        return matrix;
    vector< vector<ll> > arr=matrixExp(matrix, pow/2);
    arr=matrixMul(arr,arr);
    if(pow&1)
    {
        return matrixMul(arr,matrix);
    }
    return arr;
}

int main(int argc, const char * argv[])
{
    int t,n,m,i,j;
    scanf("%d",&t);
    vector< vector<ll> > arr(2, vector<ll>(2,0));
    arr[0][0]=1;
    arr[0][1]=1;
    arr[1][0]=1;
    arr[1][1]=0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        vector< vector<ll> > arrn=matrixExp(arr, n+1);
        vector< vector<ll> > arrm=matrixExp(arr, m+2);
        ll a=((arrn[0][1]-1)%MOD+MOD)%MOD;
        ll b=((arrm[0][1]-1)%MOD+MOD)%MOD;
        ll ans=((b%MOD-a%MOD)+MOD)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}

