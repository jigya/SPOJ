//
//  main.cpp
//  TAUTSPOJ147
//
//  Created by Jigya Yadav on 30/12/14.
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

int implies[2][2];
int iff[2][2];

int isFalse;

void evaluateExp(stack<int> st, string expr, int pos, map<char, int> mp)
{
    if (pos == -1)
    {
        if (st.top() == false)
        {
            isFalse = true;
        }
        return;
    }
    if (expr[pos] == 'C')
    {
        int f = st.top();
        st.pop();
        int g = st.top();
        st.pop();
        st.push(f&g);
        pos--;
        evaluateExp(st, expr, pos, mp);
    }
    else if(expr[pos] == 'D')
    {
        int f = st.top();
        st.pop();
        int g = st.top();
        st.pop();
        st.push(f|g);
        pos--;
        evaluateExp(st, expr, pos, mp);
    }
    else if(expr[pos] == 'N')
    {
        int f = st.top();
        st.pop();
        st.push(!f);
        pos--;
        evaluateExp(st, expr, pos, mp);
    }
    else if(expr[pos] == 'I')
    {
        int f = st.top();
        st.pop();
        int g = st.top();
        st.pop();
        st.push(implies[f][g]);
        pos--;
        evaluateExp(st, expr, pos, mp);
    }
    else if(expr[pos] == 'E')
    {
        int f = st.top();
        st.pop();
        int g = st.top();
        st.pop();
        st.push(iff[f][g]);
        pos--;
        evaluateExp(st, expr, pos, mp);
    }
    else
    {
        if(mp.find(expr[pos]) == mp.end())
        {
            mp[expr[pos]] = 0;
            st.push(0);
            pos--;
            evaluateExp(st, expr, pos, mp);
            pos++;
            st.pop();
            
            
            mp[expr[pos]] = 1;
            st.push(1);
            pos--;
            evaluateExp(st, expr, pos, mp);
        }
        else
        {
            st.push(mp[expr[pos]]);
            pos--;
            evaluateExp(st, expr, pos, mp);
        }
    }
}


int main(int argc, const char * argv[])
{
    int t;
    string s;
    implies[0][0] = 1;
    implies[0][1] = 1;
    implies[1][0] = 0;
    implies[1][1] = 1;
    iff[0][0] = 1;
    iff[0][1] = 0;
    iff[1][0] = 0;
    iff[1][1] = 1;
    scanf("%d", &t);
    while (t--)
    {
        cin >> s;
//        cout<<s<<endl;
        isFalse = false;
        stack<int> st;
        map<char, int> hm;
        evaluateExp(st, s, s.length()-1, hm);
        if (isFalse == false)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

