//
//  main.cpp
//  BROWSPOJ677
//
//  http://onlinejudge.wordpress.com/2010/07/10/spoj-brow/
//  Created by Jigya Yadav on 25/12/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

//The highway is circular. A simple O(n^2) algorithm can be used to verify hand generated test cases. Considering that the number of cities is ~ 10000 in the worst case, we need an  O(n) algorithm for the code to clear within the time limit. A brewery has to be at a particular city, so the logical solution would be to place the brewery at each city and compute the cost. We can do this easily in O(n^2) but it won’t clear the time limit.

//To do this in O(n), we first place the brewery at city 0. We keep two pointers, the left most limit and the rightmost limit. All cities between left and brewery position B are satisfied by transporting the goods to the left from  the brewery, i.e. you can imagine that if the highway was a straight line, the city would be to the left of the brewery. All cities between B and right are such that their demand is satisfied by sending goods to the right.

//As the highway is circular, we get two distances from any city to the brewery. Let’s call these distances the left-distance and the right-distance. Left-distance is the distance such that the brewery is to the right of the city. The right-distance is analogous. Now, for a city X, we use the left-distance only if it’s right-distance is greater than the left distance. The right distance is nothing but the total-length of the highway minus the left-distance.

//Initially  we set the brewery position at 0. We stretch the left pointer as far left as possible. That is, till a city whose left-distance is less than it’s right-distance. The right pointer is then stretched to cover the remaining cities. Now, we place the brewery at cities 1,2,3 and so on till city n-1 and find the minimum of the transport values at the different cities.

//We can compute the new value of the transportation cost when we shift the brewery one position to the right efficiently. When we move the brewery one position to the right, the number of beer kegs to the left initially increase. If there were any cities to the right before the movement, i.e. if the number of beer kegs to the right of the previous position of the brewery was more than 0, then they decrease by the number of kegs required by the city at which the brewery is at the moment.

//On moving the brewery right, for all cities to the left, the left-distance increases by the distance between the previous city and the current city. We multiply this by the total number of beer kegs required to the left. If there was any demand to the right previously, the right-distance of all cities to the right decreases by the same distance mentioned in the last sentence. We thus decrease the cost by the total number of beer kegs required multiplied by the distance. If there were no cities to the right, we change value of right to the current position of the brewery.

//After doing this, we have to adjust the left and right pointers. If the left-distance of the current left pointer city is greater than total-distance / 2, we move the left one position to the right and adjust the values. The demand from the left decreases by the distance*requirement at that city. We keep moving the left pointer to the right till a point where the left-distance of the city <= total-distance of the highway / 2 . We keep moving the right pointer to cover the rest of the cities and adjust values accordingly.

//Although we have a while loop inside the for loop, the algorithm is not O(n^2) as all cities are never traversed in each while loop on every turn. This is because of the circular nature of the highway. The left pointer is always at a point at most total-distance/2 away from the location of the brewery. So, it covers at most ‘n’ points on the whole.

//At every city, we get a new value after the computations mentioned above. We take the minimum of all these values.


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

int main(int argc, const char * argv[])
{
    int i, j, k, m, n, p, q, r, t;
    scanf("%d", &t);
    int demand[10100];
    int dist[10100];
    ll distSum[10100];
    ll demandSum[10100];
    ll factors[10100];
    ll totalDist, totalDemand;
    ll minCost, currCost, currDist;
    while (t--)
    {
        totalDemand = totalDist = 0;
        scanf("%d", &n);
        m = n-1;
        for (i = 0; i < n; i++)
        {
            scanf("%d %d", &j, &k);
            demand[m] = j;
            dist[i] = k;
            totalDist += (ll)dist[i];
            totalDemand += (ll)demand[m];
            m = (m+1)%n;
        }
        for (i = 0; i < n; i++)
        {
            cout<<demand[i]<<" "<<dist[i]<<endl;
        }
        for (i = 0; i < n; i++)
        {
            distSum[i] =  totalDist - dist[i];
            demandSum[i] = totalDemand - demand[i];
        }
        for (i = 0; i < n; i++)
        {
            factors[i] = demand[(i+n-1)%n]*distSum[i] - dist[i]*demandSum[(i+n-1)%n];
        }
        currCost = currDist = 0;
        minCost = LONG_LONG_MIN;
        for (i = 0; i < n-1; i++)
        {
            currDist += dist[i];
            currCost += currDist * demand[i];
        }
        cout<<currCost<<endl;
        minCost = currCost;
        for (i = 0; i < n; i++)
        {
            currCost += factors[i];
            min(minCost, currCost);
            cout<<currCost<<endl;
        }
        printf("%lld\n", minCost);
    }
    return 0;
}

