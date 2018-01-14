//
//  main.cpp
//  EDITSPOJ10537
//
//  Created by Jigya Yadav on 13/12/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//
//  Easy- Consider two cases-onw in which we switch the first letter, one in which we dont
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
    int i, j, k, m, n;
//    string tr;
    char tr[1010];
    int upper[1010];
    int lower[1010];
    while (scanf("%s", tr) != EOF)
    {
        n = strlen(tr);
        if (tr[0] >= 'A' && tr[0] <= 'Z')
        {
            upper[0] = 0;
            lower[0] = 1;
        }
        else
        {
            upper[0] = 1;
            lower[0] = 0;
        }
        for (i = 1; i < n; i++)
        {
            if (i&1)
            {
                if (tr[i] >= 'a' && tr[i] <= 'z')
                {
                    upper[i] = 0;
                }
                else
                {
                    upper[i] = 1;
                }
            }
            else
            {
                if (tr[i] >= 'a' && tr[i] <= 'z')
                {
                    upper[i] = 1;
                }
                else
                {
                    upper[i] = 0;
                }
            }
        }
        for (i = 1; i < n; i++)
        {
            if (i&1)
            {
                if (tr[i] >= 'a' && tr[i] <= 'z')
                {
                    lower[i] = 1;
                }
                else
                {
                    lower[i] = 0;
                }
            }
            else
            {
                if (tr[i] >= 'a' && tr[i] <= 'z')
                {
                    lower[i] = 0;
                }
                else
                {
                    lower[i] = 1;
                }
            }
        }
        int sumu = 0, suml = 0;
        for (i = 0; i < n; i++)
        {
            sumu += upper[i];
            suml += lower[i];
        }
        cout<<min(sumu, suml)<<endl;
    }
    return 0;
}

