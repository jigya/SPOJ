//
//  main.cpp
//  ADFRUITSSPOJ9493
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
#define ll long long int

using namespace std;

int arr[120][120];
int dir[120][120];
string common;

void printlcs(int i, int j, char *stra, char *strb)
{
    if (i ==0 || j == 0)
    {
        return;
    }
    if (dir[i][j] == 0)
    {
        printlcs(i-1, j-1, stra, strb);
        common += stra[i-1];
    }
    else if(dir[i][j] == 1)
    {
        printlcs(i-1, j, stra, strb);
    }
    else
    {
        printlcs(i, j-1, stra, strb);
    }
}


void lcs(char *stra, char *strb)
{
//    cout<<stra<<" "<<strb<<endl;
    char str1[150] = "1", str2[150] = "1";
    strcat(str1, stra);
    strcat(str2, strb);
    int i, j, k;
    int n1 = strlen(stra);
    int n2 = strlen(strb);
    for (i = 0; i <= n1; i++)
    {
        arr[0][i] = 0;
    }
    for (i = 0; i <= n2; i++)
    {
        arr[i][0] = 0;
    }
    for (i = 1; i <= n1; i++)
    {
        for (j = 1; j <= n2; j++)
        {
            if (str1[i] == str2[j])
            {
                arr[i][j] = arr[i-1][j-1]+1;
                dir[i][j] = 0;
            }
            else
            {
                arr[i][j] =  max(arr[i-1][j], arr[i][j-1]);
                //from top
                if (arr[i-1][j] > arr[i][j-1])
                {
                    dir[i][j] = 1;
                }
                else
                {
                    dir[i][j] = -1;
                }
            }
        }
    }
    printlcs(n1, n2, stra, strb);
}

int main(int argc, const char * argv[])
{
    int i, j, k, n1, n2, start1, end1, start2, end2;
    char str1[110], str2[110];
    while (cin >> str1 >> str2)
    {
        common = "";
        memset(arr, 0, sizeof(arr));
        memset(dir, 5, sizeof(dir));
        lcs(str1, str2);
        i = start1 = end1 = start2 = end2 = k = 0;
        n1= strlen(str1);
        n2= strlen(str2);
        string nname;
//        cout<<common<<endl;
        for (i = 0; i < common.length(); i++)
        {
            while (end1 < n1 && str1[end1] != common[i])
            {
                end1++;
            }
            for (j = start1; j < end1; j++)
            {
                nname += str1[j];
            }
            start1 = end1 = end1+1;
            while (end2 < n2 && str2[end2] != common[i])
            {
                end2++;
            }
            for (j = start2; j < end2; j++)
            {
                nname += str2[j];
            }
            start2 = end2 = end2+1;
            nname += common[i];
        }
        for (i = start1; i < n1; i++)
        {
            nname += str1[i];
        }
        for (i = start2 ; i < n2; i++)
        {
            nname += str2[i];
        }
        cout<<nname<<endl;
    }
    
    return 0;
}

