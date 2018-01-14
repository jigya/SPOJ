//
//  main.cpp
//  FaceFrndSPOJ9788
//
//  Created by Jigya Yadav on 13/08/14.
//  Copyright (c) 2014 Jigya Yadav. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <sstream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    int n,i,j,k,t;
    scanf("%d",&n);
    vector<int> directFriends;
    map<int, int> friendsOfFriends;
    for(i=0;i<n;i++)
    {
        scanf("%d", &t);
        directFriends.push_back(t);
        scanf("%d",&k);
        for(j=0;j<k;j++)
        {
            scanf("%d",&t);
            friendsOfFriends.insert(make_pair(t, 0));
        }
    }
    for(i=0;i<n;i++)
    {
        friendsOfFriends.erase(directFriends[i]);
    }
    printf("%d\n",friendsOfFriends.size());
    return 0;
}

