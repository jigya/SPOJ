//
//  main.cpp
//  SHPATHSPOJ15
//
//  Created by Jigya Yadav on 05/09/14.
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
    vector<int> dist(V+5, 97654321);
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
                if(dist[v2]>dist[v]+cost)
                {
                    dist[v2]=dist[v]+cost;
                    pq.push(ii(dist[v2], v2));
                }
            }
        }
    }
    return dist[destination];
}


int main(int argc, const char * argv[])
{
    int t, i, j, m, numCities, neighbours, cost, r, source, destination;
    string cityName, src, dest;
    t=fastread();
    while ( t-- )
    {
        map< string, int > hm;
        numCities=fastread();
        vector< vector< pair<int, int> > > adjList(numCities+2);
        
        for( i = 1 ; i <= numCities ; i++ )
        {
            cin>>cityName;
            hm[cityName]=i;
            neighbours=fastread();
            for ( j = 1; j <= neighbours ; j++ )
            {
                m=fastread();
                cost=fastread();
                adjList[i].push_back( make_pair( m, cost ) );
            }
        }
        r=fastread();
        for( i = 1; i <= r; i++)
        {
            cin>>src>>dest;
            source = hm[src];
            destination = hm[dest];
            printf("%d\n", djikstra(source, destination, adjList, numCities));
        }
    }
    return 0;
}

