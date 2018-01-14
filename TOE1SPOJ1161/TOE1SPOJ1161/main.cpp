//
//  main.cpp
//  TOE1SPOJ1161
//
//  Created by Jigya Yadav on 06/12/14.
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

map<string, bool> hm;

//1 means x's turn
//0 means o's turn

bool checkWin(string str)
{
    int i, j, k=0;
    
    if (str[0] == str[3] && str[3] ==  str[6] && str[0] != '.')
    {
        return true;
    }
    if (str[1] == str[4] && str[4] == str[7] && str[1] != '.')
    {
        return true;
    }
    if (str[2] == str[5] && str[5] == str[8] && str[2] != '.')
    {
        return true;
    }
    if (str[0]== str[1] && str[1] == str[2] && str[0] != '.')
    {
        return true;
    }
    if (str[3]== str[4] && str[4] == str[5] && str[3] != '.')
    {
        return true;
    }
    if (str[6]== str[7] && str[7] == str[8] && str[6] != '.')
    {
        return true;
    }
    if (str[0]== str[4] && str[4] == str[8] && str[0] != '.')
    {
        return true;
    }
    if (str[2]== str[4] && str[4] == str[6] && str[2] != '.')
    {
        return true;
    }
    return false;
}

void genPossibleStates(string str, int turn)
{
    if (hm.find(str) != hm.end())
    {
//        cout<<"eher1"<<endl;
        return;
    }
    hm.insert(make_pair(str, true));
    if (checkWin(str))
    {
//        cout<<"here"<<endl;
        return;
    }
    string newstr;
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            newstr = str;
            if (turn == 1)
            {
                newstr[i] = 'X';
            }
            else if(turn == 0)
            {
                newstr[i] = 'O';
            }
            genPossibleStates(newstr, !turn);
        }
    }
}5

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t;
    string str = ".........";
    genPossibleStates(str, 1);
//    for (map<string, bool>::iterator it = hm.begin(); it != hm.end(); it++)
//    {
//        cout<<it->first<<endl;
//    }
    scanf("%d", &t);
    string input;
    while (t--)
    {
        input = "";
        for (i = 0; i < 3; i++)
        {
            cin>>str;
            input += str;
        }
        if (hm.find(input) != hm.end())
        {
            printf("yes\n");
        }
        else printf("no\n");
    }
    return 0;
}

