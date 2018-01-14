//
//  main.cpp
//  DeepaSolution
//
//  Created by Jigya Yadav on 29/01/15.
//  Copyright (c) 2015 Jigya Yadav. All rights reserved.
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
#include <sstream>
#include <cfloat>

using namespace std;

int prob[100][100];


//Replace the array size in array prob
void printCombinations(int pos, vector<int> arr, int m, int n)
{
    if (pos == m)
    {
        for(int i = 0; i < arr.size()-1;i++)
        {
            printf("%d , ", arr[i]);
        }
        printf("%d", arr[arr.size()-1]);
        printf("\n");
        return;
    }
    int k = pos;
    pos++;
    for(int i = 0; i < n; i++)
    {
        arr.push_back(prob[k][i]);
        printCombinations(pos, arr, m, n);
        arr.pop_back();
    }
}

int main(int argc, const char * argv[])
{
    vector<int> arr;
    prob[0][0] = 1;
    prob[0][1] = 3;
    prob[0][2] = 5;
    prob[1][0] = 2;
    prob[1][1] = 6;
    prob[1][2] = 7;
    prob[2][0] = 3;
    prob[2][1] = 4;
    prob[2][2] = 1;
    printCombinations(0, arr, 3, 1);
    return 0;
}

