//
//  main.cpp
//  HIGHWAYSSPOJ3381
//
//  Created by Jigya Yadav on 22/12/14.
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

using namespace std;
const int INF = 2000000000;
typedef pair<int,int> PII;

int main()
{
    int numTest, m;
    scanf("%d", &numTest);
    while (numTest--)
    {
        int N, s, t;
        scanf ("%d%d%d%d", &N, &m, &s, &t);
        vector<vector<PII> > edges(N+5);
            for (int j = 0; j < m; j++)
            {
                int vertex1, vertex2, dist;
                scanf ("%d%d%d", &vertex1, &vertex2, &dist);
                edges[vertex1].push_back (make_pair (dist, vertex2)); // note order of arguments here
                edges[vertex2].push_back (make_pair (dist, vertex1));
            }
//        for (int i = 1; i <= N; i++)
//        {
//            for (vector<PII>::iterator itr = edges[i].begin(); itr != edges[i].end(); itr++)
//            {
//                cout<<"["<<itr->second<<" "<<itr->first<<"];";
//            }
//            cout<<endl;
//        }
        // use priority queue in which top element has the "smallest" priority
        priority_queue<PII, vector<PII>, greater<PII> > Q;
        vector<int> dist(N+5, INF), dad(N+5, -1);
        Q.push (make_pair (0, s));
        dist[s] = 0;
        while (!Q.empty())
        {
            PII p = Q.top();
            if (p.second == t) break;
            Q.pop();
            
            int here = p.second;
            for (vector<PII>::iterator it=edges[here].begin(); it!=edges[here].end(); it++){
                if (dist[here] + it->first < dist[it->second]){
                    dist[it->second] = dist[here] + it->first;
                    dad[it->second] = here;
                    Q.push (make_pair (dist[it->second], it->second));
                }
            }
        }
        if (dist[t] == INF)
        {
            printf("NONE\n");
        }
        else
            printf ("%d\n", dist[t]);
//        if (dist[t] < INF)
//            for(int i=t;i!=-1;i=dad[i])
//                printf ("%d%c", i, (i==s?'\n':' '));
        

    }
    return 0;
}

