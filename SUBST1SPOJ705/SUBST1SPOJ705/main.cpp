//
//  main.cpp
//  SUBST1SPOJ705
//
//  Created by Jigya Yadav on 04/09/14.
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
#include <stack>

using namespace std;

#define MAXN 65536
#define MAXLG 17


long long int sumLcp;

struct entry
{
    int nr[2];
    int p;
} L[MAXN];

int P[MAXLG][MAXN];
int N;
int stp, cnt;
int LCP[MAXN];
vector<int> arr(MAXN);

int cmp(struct entry a, struct entry b)
{
    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}


int lcp(int x, int y)
{
    int k, ret = 0;
    if (x == y) return N - x;
    for (k = stp - 1; k >= 0 && x < N && y < N; k --)
        if (P[k][x] == P[k][y])
            x += 1 << k, y += 1 << k, ret += 1 << k;
    return ret;
}

void buildLCP()
{
    int i;
    for(i=1;i<N;i++)
    {
        LCP[i]=lcp(arr[i], arr[i-1]);
    }
}

int main(int argc, const char * argv[])
{
    int t,i,j,k;
    string str,A;
    scanf("%d",&t);
    while (t--)
    {
        cin>>str;
        N=str.length();
        sumLcp=0;
        A=str;
        for(N=A.length(), i = 0; i < N; i++)
            P[0][i] = A[i] - 'a';
        
        for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
        {
            for(i=0; i < N; i++)
            {
                L[i].nr[0]=P[stp- 1][i];
                L[i].nr[1]=i +cnt <N? P[stp -1][i+ cnt]:-1;
                L[i].p= i;
            }
            sort(L, L+N, cmp);
            for(i=0; i < N; i++)
                P[stp][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
        }
        for(i=0;i<N;i++)
        {
            arr[P[stp-1][i]]=i;
        }
        buildLCP();
        for(i=1;i<N;i++)
        {
            cout<<LCP[i]<<endl;
            sumLcp+=LCP[i];
            cout<<"sumLCP= "<<sumLcp<<endl;
        }
        long long int ans=(N*(N-1))/2-sumLcp;
        printf("%lld\n",ans);
    }
    return 0;
}

