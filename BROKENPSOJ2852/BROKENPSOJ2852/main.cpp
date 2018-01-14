//
//  main.cpp
//  BROKENPSOJ2852
//
//  Created by Jigya Yadav on 07/11/14.
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

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, s;
    int arr[500];
    string sentence;
    while (1)
    {
        cin >> m;
        if (m == 0)
        {
            break;
        }
        getline(cin, sentence);
        memset(arr, -1, sizeof(arr));
        getline(cin, sentence);
        n = sentence.length();
//        cout<<sentence<<endl;
        i = 0;
        j = 0;
        int cnt = 0;
        int maxlen = -1;
        int currlen = 0;
        int wr;
        while (i < n && j < n)
        {
            if (arr[sentence[j]] != -1)
            {
                arr[sentence[j]] = j;
                currlen++;
            }
            else
            {
//                cout<<"here"<<endl;
                if (cnt == m)
                {
                    maxlen = max(currlen, maxlen);
                    int minPos = INT_MAX;
                    
                    for (s = 0; s < 256; s++)
                    {
                        if (arr[s] != -1 && minPos > arr[s])
                        {
//                             cout<<"arr[s] = "<<(char)s<<" "<<arr[s]<<endl;
                            minPos = arr[s];
                            wr = s;
                        }
                    }
//                    cout<<"minpos = "<<minPos<<endl;
                    i = minPos+1;
                    cnt--;
                    currlen = j - i;
                    arr[wr] = -1;
                }
                arr[sentence[j]] = j;
                cnt++;
                currlen++;
            }
            j++;
//            cout<<"i="<<i<<" j="<<j<<" "<<cnt<<endl;
            
        }
        maxlen = max(currlen, maxlen);
        cout<<maxlen<<endl;
//         cout << sentence << endl;
    }
    return 0;
}

