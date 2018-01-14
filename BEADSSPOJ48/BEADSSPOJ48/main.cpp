//
//  main.cpp
//  BEADSSPOJ48
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

#define MAXN 20010
#define MAXLG 17

int P[MAXN][MAXLG];


struct entry
{
    int nr[2];
    int p;
}L[MAXN];

//Compare function to compare two entry structures a and b
int cmp(struct entry a, struct entry b)
{
    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

vector<int> buildSuffixArray(string str, int N)
{
    int i,stp,cnt;
    string A=str;
    for(i = 0; i < N; i++)
    {
        P[0][i] = A[i] - 'a';
    }
    
    for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
    {
        for(i=0; i < N; i++)
        {
            L[i].nr[0]=P[stp- 1][i];
            L[i].nr[1]=i +cnt<N? P[stp -1][i+ cnt]:-1;
            L[i].p= i;
        }
        sort(L, L+N, cmp);
        for(i=0; i < N; i++)
            P[stp][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
    }
    vector<int> arr(MAXN);
    for(i=0;i<N;i++)
    {
        arr[P[stp-1][i]]=i;
    }
    return arr;
}

int main(int argc, const char * argv[])
{
    int i,n;
    string str,str2;
    scanf("%d",&n);
    while (n--)
    {
        cin>>str;
        str2=str;
        str2+=str;
        vector<int> suffixArr=buildSuffixArray(str2, (int)str2.length());
        for(i=0;i<str2.length();i++)
        {
            if(suffixArr[i]>=0 && suffixArr[i]<=str.length()-1)
            {
                printf("%d\n",(suffixArr[i]+1));
                break;
            }
        }
    }
    return 0;
}

