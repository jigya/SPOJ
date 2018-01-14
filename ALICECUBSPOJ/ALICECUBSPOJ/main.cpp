//
//  main.cpp
//  ALICECUBSPOJ
//
//  http://www.quora.com/How-do-I-solve-the-SPOJ-ALICECUB-problem-using-BFS
//  Created by Jigya Yadav on 08/06/15.
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

int adjacentVertices[][4] = {{8,4,2,1}, {9,5,3,0}, {10,6,3,0}, {11,7,2,1}, {12, 6, 5, 0}, {13, 7, 5, 1}, {14, 7, 4, 2}, {15, 6, 5, 3}, {12, 10, 9, 0}, {13, 11, 8, 1}, {14, 11, 8, 2}, {15, 10, 9, 3}, {14, 13, 8, 4}, {15, 12, 9, 5}, {15, 12, 6, 10}, {14, 13, 11, 7}};

int arr[140000];
bool visited[140000] = {false};

int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    /* Move all bits of first set to rightmost side */
    unsigned int set1 =  (x >> p1) & ((1U << n) - 1);
    
    /* Moce all bits of second set to rightmost side */
    unsigned int set2 =  (x >> p2) & ((1U << n) - 1);
    
    /* XOR the two sets */
    unsigned int xory = (set1 ^ set2);
    
    /* Put the xor bits back to their original positions */
    xory = (xory << p1) | (xory << p2);
    
    /* XOR the 'xor' with the original number so that the
     two sets are swapped */
    unsigned int result = x ^ xory;
    
    return result;
}

void bfs(unsigned int x)
{
    unsigned int p, h;
    queue<unsigned int> q;
    q.push(x);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        forall(i, 0, 16)
        {
            forall(j, 0, 4)
            {
                h = swapBits(p, i, adjacentVertices[i][j], 1);
                if (!visited[h])
                {
                    if (h == 255)
                    {
                        printf("Yes\n");
                    }
                    q.push(h);
                    visited[h] = true;
                    arr[h] = arr[p]+1;
                }
            }
        }
    }
}

unsigned int binToDecimal(int num[20])
{
    int k = 1;
    unsigned int j = 0;
    for (int i = 15; i >= 0; i--)
    {
        j += num[i]*k;
        k *= 2;
    }
    return j;
}

int main(int argc, const char * argv[])
{
    arr[255] = 0;
    int num[20];
    memset(visited, false, sizeof(visited));
    visited[255] = true;
    bfs(255);
//    printf("Here");
    int t, p;
    s(t);
//    forall(i, 0, 1000)
//    {
//        printf("%d\n", arr[i]);
//    }
    forall(i, 1, t+1)
    {
        string str = "";
        forall(j, 0, 16)
        {
            s(num[j]);
        }
        unsigned int k = binToDecimal(num);
//        printf("%d\n", k);
        if (arr[k] <= 3)
        {
            printf("Case #%d: %d\n", i, arr[k]);
        }
        else
        {
            printf("Case #%d: more\n", i);
        }
    }
    return 0;
}
