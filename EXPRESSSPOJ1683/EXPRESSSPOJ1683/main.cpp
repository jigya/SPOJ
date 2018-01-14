//
//  main.cpp
//  EXPRESSSPOJ1683
//
//  Algorithm: Build expression tree from postfix, then do bfs
//  Created by Jigya Yadav on 05/01/15.
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

struct node
{
    node *left;
    node *right;
    char c;
};

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    string r;
    while (t--)
    {
        stack<node*> st;
        queue<node*> q;
        string rslt;
        cin >> r;
        forall(i, 0, r.length())
        {
            if (r[i] >= 'a' && r[i] <= 'z')
            {
                node* d = (node*)malloc(sizeof(node));
                d->left = NULL;
                d->right = NULL;
                d->c = r[i];
                st.push(d);
            }
            else
            {
                node *lt = st.top();
                st.pop();
                node *rt = st.top();
                st.pop();
                node *d = (node *)malloc(sizeof(node));
                d -> left = rt;
                d -> right = lt;
                d -> c = r[i];
                st.push(d);
            }
        }
        q.push(st.top());
        while (!q.empty())
        {
            node *d = q.front();
            q.pop();
            if (d != NULL)
            {
                q.push(d->left);
                q.push(d->right);
                rslt += d->c;
            }
        }
        reverse(rslt.begin(), rslt.end());
        cout<<rslt<<endl;
    }
    return 0;
}

