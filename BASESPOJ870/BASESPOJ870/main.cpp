//
//  main.cpp
//  BASESPOJ870
//
//  Created by Jigya Yadav on 06/11/14.
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
#include<iomanip>

using namespace std;

char mapping[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};


string toDigit(int n, int b)
{
    string str;
    stack<int> r;
    while (n > 0)
    {
        r.push(n % b);
        n = n/b;
    }
    while (!r.empty())
    {
        int y = r.top();
        r.pop();
        str += mapping[y];
    }
    return str;
}

int fromDigit(string str, int b)
{
    int  n = 0;
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'F')
        {
            n = n*b + (str[i] - 'A' + 10);
        }
        else
        {
            n = n*b + str[i] - '0';
        }
    }
    return n;
}

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t, basefrom, baseto;
    string str;
    ios_base::sync_with_stdio(false);
    while (cin >> str >> basefrom >> baseto)
    {
        string rslt = toDigit(fromDigit(str, basefrom), baseto);
        if (rslt.length() > 7)
        {
            cout << setw(7) << "ERROR" << endl;
        }
        else
        {
            cout << setw(7) << toDigit(fromDigit(str, basefrom), baseto)<<endl;
        }
//        cout << str << " " << basefrom << " " << baseto <<endl;
    }
    return 0;
}

