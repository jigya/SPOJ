//
//  main.cpp
//  CMEXPRSPOJ10
//
//  http://stackoverflow.com/questions/26763975/removing-unnecessary-duplicates-parentheses-from-arithmetic-expressions-using-st?rq=1
//  Created by Jigya Yadav on 01/01/15.
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
#define ll long long int

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

using namespace std;

int convertInfixToPostfix(char post[], char exp[])
{
    strcat(exp, ")");
    stack<char> st;
    st.push('(');
    int k = 0;
    forall(i, 0, strlen(exp))
    {
        switch (exp[i])
        {
            case '(':
                st.push('(');
                break;
            case ')':
                while (st.top() != '(')
                {
                    post[k++] = st.top();
                    st.pop();
                }
                st.pop();
                break;
            case '+':
                if(!st.empty())
                while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                {
                    post[k++] = st.top();
                    st.pop();
                }
                st.push('+');
                break;
            case '-':
                if(!st.empty())
                while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                {
                    post[k++] = st.top();
                    st.pop();
                }
                st.push('-');
                break;
            case '*':
                if(!st.empty())
                while (st.top() == '*' || st.top() == '/')
                {
                    post[k++] = st.top();
                    st.pop();
                }
                st.push('*');
                break;
            case '/':
                if(!st.empty())
                while (st.top() == '*' || st.top() == '/')
                {
                    post[k++] = st.top();
                    st.pop();
                }
                st.push('/');
                break;
            default:
                post[k++] = exp[i];
                break;
        }
    }
    post[k] = '\0';
//    cout<<post<<endl;
    return k;
}

class intermediate
{
public:
    string expr;
    char oper;
    intermediate(string a, char b)
    {
        expr = a;
        oper = b;
    }
};

string convertPostfixToInfix(char post[])
{
    stack<intermediate> st;
    forall(i, 0, strlen(post))
    {
        if (post[i] == '+')
        {
            intermediate rightIntermediate(st.top());
            st.pop();
            intermediate leftIntermediate(st.top());
            st.pop();
            string newexpr = leftIntermediate.expr + post[i] + rightIntermediate.expr;
            intermediate d(newexpr, post[i]);
            st.push(d);
        }
        else if(post[i] == '-')
        {
            intermediate rightIntermediate(st.top());
            st.pop();
            intermediate leftIntermediate(st.top());
            st.pop();
            string rightexpr;
            if (rightIntermediate.oper == '-' || rightIntermediate.oper == '+')
            {
                rightexpr = "("+rightIntermediate.expr+")";
            }
            else
            {
                rightexpr = rightIntermediate.expr;
            }
            string newexpr = leftIntermediate.expr + post[i] + rightexpr;
            intermediate d(newexpr, post[i]);
            st.push(d);
        }
        else if(post[i] == '*')
        {
            string rightExpr, leftExpr;
            intermediate rightIntermediate(st.top());
            st.pop();
            intermediate leftIntermediate(st.top());
            st.pop();
            if (rightIntermediate.oper == '+' || rightIntermediate.oper == '-')
            {
                rightExpr = "("+rightIntermediate.expr+")";
            }
            else
                rightExpr = rightIntermediate.expr;
            if (leftIntermediate.oper == '+' || leftIntermediate.oper == '-')
            {
                leftExpr = "("+leftIntermediate.expr+")";
            }
            else
            leftExpr = leftIntermediate.expr;
            string newexpr = leftExpr + post[i] + rightExpr;
            intermediate d(newexpr, post[i]);
            st.push(d);
        }
        else if(post[i] == '/')
        {
            string rightExpr, leftExpr;
            intermediate rightIntermediate(st.top());
            st.pop();
            intermediate leftIntermediate(st.top());
            st.pop();
            if (rightIntermediate.oper == '+' || rightIntermediate.oper == '-' || rightIntermediate.oper == '*' || rightIntermediate.oper == '/')
            {
                rightExpr = "("+rightIntermediate.expr+")";
            }
            else
                rightExpr = rightIntermediate.expr;
            if (leftIntermediate.oper == '+' || leftIntermediate.oper == '-')
            {
                leftExpr = "("+leftIntermediate.expr+")";
            }
            else
                leftExpr = leftIntermediate.expr;
            string newexpr = leftExpr + post[i] + rightExpr;
            intermediate d(newexpr, post[i]);
            st.push(d);
        }
        else
        {
            stringstream ss;
            string s;
            ss << post[i];
            ss >> s;
            intermediate d(s, 'p');
            st.push(d);
        }
    }
    return st.top().expr;
}


int main(int argc, const char * argv[])
{
    int t;
    scanf("%d", &t);
    char arr[500];
    char post[500];
    while (t--)
    {
        scanf("%s", arr);
        convertInfixToPostfix(post, arr);
        cout<<convertPostfixToInfix(post)<<endl;
    }
    return 0;
}

