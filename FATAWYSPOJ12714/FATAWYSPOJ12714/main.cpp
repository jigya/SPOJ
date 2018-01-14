//
//  main.cpp
//  FATAWYSPOJ12714
//
//  Created by Jigya Yadav on 18/01/15.
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
#define ll long long int

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-6

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

class UnionFind
{
public:
    int id[505];
    int sz[505];
    int count;
    
    UnionFind(int n)
    {
        count  = n;
        forall(i, 0, n+2)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }
    
    int find(int p)
    {
        while (p != id[p])
        {
            p = id[p];
        }
        return p;
    }
    
    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }
    
    void uniony(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ)
        {
            return;
        }
        if(sz[rootP] < sz[rootQ ])
        {
            id[rootP] = rootQ; sz[rootQ] += sz[rootP];
        }
        else
        {
            id[rootQ] = rootP; sz[rootP] += sz[rootQ];
        }
        count--;
    }
};


/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( string X, string Y, int m, int n )
{
    int L[m+1][n+1];
    int i, j;
    
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
     that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    
    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}



int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t, th;
    char s1[15];
    s(t);
    forall(w, 1, t+1)
    {
        vector<string> arr;
        s(n);
        s(th);
        forall(i, 0, n)
        {
            scanf("%s", s1);
            arr.pb(s1);
        }
        UnionFind d(n);
        for(i = 0; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                k = lcs(arr[i], arr[j], arr[i].length(), arr[j].length());
//                printf("%d\n", k);
                double th1 = (k*100.0)/arr[i].length();
                double th2 = (k*100.0)/arr[j].length();
//                cout<<th1<<" "<<th2<<endl;
                if(th1>=th && th2>=th)
                {
//                    cout<<"here"<<i<<" "<<j<<" "<<th1<<" "<<th2<<endl;
                    d.uniony(i, j);
                }
            }
        }
//        forall(i, 0, n)
//        {
//            cout<<d.id[i]<<" ";
//        }
//        cout<<endl;
        printf("Case #%d:\n%d\n", w, d.count);
    }
    return 0;
}

