//
//  main.cpp
//  ABCDSPOJ8551
//
//  Created by Jigya Yadav on 14/12/14.
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
    int i, j, k, m, n, t;
    char wr;
    char arr[2][100010];
    bool pres[4];
    scanf("%d", &n);
    getchar();
    for (i = 0; i  < 2*n; i++)
    {
        scanf("%c", &arr[0][i]);
//        cout<<arr[0][i];
    }
//    cout<<endl;
    for (i = 0; i < 2*n; i+=2)
    {
//        cout<<i<<endl;
        k = m = -1;
        memset(pres, false, sizeof(pres));
        pres[arr[0][i]-'A'] = true;
        pres[arr[0][i+1]-'A'] = true;
        for (j = 0; j < 4; j++)
        {
            if (pres[j] == false)
            {
                if (k == -1)
                {
                    k = j;
                }
                else
                {
                    m = j;
                }
            }
        }
        if(i > 0)
        {
            if ((m+'A') == arr[1][i-1])
            {
                arr[1][i] = (char)(k+'A');
                arr[1][i+1] = (char)(m+'A');
            }
            else
            {
                arr[1][i] =  (char)(m+'A');
                arr[1][i+1] = (char)(k+'A');
            }
        }
        else
        {
            arr[1][i] =  (char)(k+'A');
            arr[1][i+1] = (char)(m+'A');
        }
    }
//    cout<<"ehere"<<n<<endl;
    for (i = 0; i < 2*n; i++)
    {
        cout<<arr[1][i];
    }
    return 0;
}

