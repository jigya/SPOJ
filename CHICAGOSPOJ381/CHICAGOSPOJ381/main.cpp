//
//  main.cpp
//  CHICAGOSPOJ381
//
//  Created by Jigya Yadav on 07/09/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int fastread()
{
    int input;
    char c=0;
    while (c<33) c=getchar();
    input=0;
    while (c>33)
    {
        input=input*10+c-'0';
        c=getchar();
    }
    return input;
}

int djikstra(int source, int destination, vector< vector< pair<int, int> > > adjList, int V)
{
    vector<double> dist(V+5, 97654321);
    dist[source]=0;
    priority_queue< int, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, source));
    while (!pq.empty())
    {
        ii top=pq.top();
        pq.pop();
        int d = top.first;
        int v = top.second;
        if(d<=dist[v])
        {
            for(vector< pair<int, int> >::iterator itr=adjList[v].begin();itr!=adjList[v].end();itr++)
            {
                int v2=itr->first;
                int cost=itr->second;
                if(dist[v2]>(dist[v]*cost)%100)
                {
                    dist[v2]=(dist[v]*cost)%100;
                    pq.push(ii(dist[v2], v2));
                }
            }
        }
    }
    return dist[destination];
}

int main(int argc, const char * argv[])
{
    int t,i,j,k;
    t=fastread();
    while (t--)
    {
        
    }
    return 0;
}

