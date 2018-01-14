//
//  main.cpp
//  BUGLIFESPOJ3377
//
//  Checking bipartiteness of a graph
//  https://kartikkukreja.wordpress.com/2013/08/23/testing-bipartiteness/?blogsub=confirming#blog_subscription-2
//  Created by Jigya Yadav on 24/09/14.
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

#define FEMALE 0
#define MALE 1
#define UNKNOWN 2

vector<int> graph[2010];
int gender[2010];

bool checkBipartite(int node)
{
    int u;
    queue<int> q;
    gender[node] = MALE;
    q.push(node);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (vector<int>::iterator itr = graph[u].begin(); itr != graph[u].end(); itr++)
        {
            if (gender[*itr] == UNKNOWN)
            {
                if (gender[u] == MALE)
                {
                    gender[*itr] = FEMALE;
                }
                else
                {
                    gender[*itr] = MALE;
                }
                q.push(*itr);
            }
            else if(gender[u] == gender[*itr])
            {
                return false;
            }
        }
    }
    return true;
}


int main(int argc, const char * argv[])
{
    int t, i, j, k, s, numBugs, numInteractions;
    scanf("%d", &t);
    for (s = 1; s <= t; s++)
    {
        scanf("%d%d", &numBugs, &numInteractions);
        for (i = 0; i < numBugs+5; i++)
        {
            graph[i].clear();
            gender[i] = UNKNOWN;
            
        }
        for (i = 1; i <= numInteractions; i++)
        {
            scanf("%d%d", &j, &k);
            graph[j].push_back(k);
            graph[k].push_back(j);
        }
        printf("Scenario #%d:\n", s);
        bool c = true;
        for (i = 1; i <= numBugs; i++)
        {
            if (gender[i] == UNKNOWN)
            {
                c=c and checkBipartite(i);
            }
        }
        if(c == true)
        {
            printf("No suspicious bugs found!\n");
        }
        else
        {
            printf("Suspicious bugs found!\n");
        }
    }
    return 0;
}

