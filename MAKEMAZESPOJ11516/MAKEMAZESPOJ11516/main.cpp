//
//  main.cpp
//  MAKEMAZESPOJ11516
//
//  Created by Jigya Yadav on 15/01/15.
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

char arr[30][30];
bool visited[30][30];

void dfs(int x1, int y1, int m, int n)
{
    visited[x1][y1] = true;
    if (x1+1 < m && !visited[x1+1][y1] && arr[x1+1][y1] != '#')
    {
        dfs(x1+1, y1, m, n);
    }
    if (y1-1 >= 0 && !visited[x1][y1-1] && arr[x1][y1-1] != '#')
    {
        dfs(x1, y1-1, m, n);
    }
    if (x1-1 >=0 && !visited[x1-1][y1] && arr[x1-1][y1] != '#')
    {
        dfs(x1-1, y1, m, n);
    }
    if (y1+1 < n && !visited[x1][y1+1] && arr[x1][y1+1] != '#')
    {
        dfs(x1, y1+1, m, n);
    }
}

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, t;
    s(t);
    pair<int, int> startPos, endPos;
    while (t--)
    {
        memset(visited, false, sizeof(visited));
        startPos = endPos = make_pair(-1, -1);
        s(m);
        s(n);
        forall(i, 0, m)
        {
            scanf("%s", arr[i]);
        }
//        forall(i, 0, m)
//        {
//            
//        }
        
        int cnt = 0;
        forall(i, 0, n)
        {
            if (arr[0][i] == '.' && !visited[0][i])
            {
                cnt++;
                if (startPos.first == -1)
                {
                    startPos.first = 0;
                    startPos.second = i;
                }
                else
                {
                    endPos.first = 0;
                    endPos.second = i;
                }
                visited[0][i] =  true;
            }
            if (arr[m-1][i] == '.' && !visited[m-1][i])
            {
                cnt++;
                if (startPos.first == -1)
                {
                    startPos.first = m-1;
                    startPos.second = i;
                }
                else
                {
                    endPos.first = m-1;
                    endPos.second = i;
                }
                visited[m-1][i] = true;
            }
        }
        
        forall(i, 0, m)
        {
            if (arr[i][0] == '.' && !visited[i][0])
            {
                cnt++;
                if (startPos.first == -1)
                {
                    startPos.first = i;
                    startPos.second = 0;
                }
                else
                {
                    endPos.first = i;
                    endPos.second = 0;
                }
                visited[i][0] = true;
            }
            if (arr[i][n-1] == '.' && !visited[i][n-1])
            {
                cnt++;
                if (startPos.first == -1)
                {
                    startPos.first = i;
                    startPos.second = n-1;
                }
                else
                {
                    endPos.first = i;
                    endPos.second = n-1;
                }
                visited[i][n-1] = true;
            }
        }
        
//        cout<<cnt<<" "<<startPos.first<<" "<<startPos.second<<" "<<endPos.first<<" "<<endPos.second<<endl;
        memset(visited, false, sizeof(visited));
        if (cnt != 2)
        {
            printf("invalid\n");
            continue;
        }
        dfs(startPos.first, startPos.second, m, n);
//        forall(i, 0, m)
//        {
//            forall(j, 0, n)
//            {
//                cout<<visited[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        if (!visited[endPos.first][endPos.second])
        {
            printf("invalid\n");
        }
        else
        {
            printf("valid\n");
        }
    }
    return 0;
}

