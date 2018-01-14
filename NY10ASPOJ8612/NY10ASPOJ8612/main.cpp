//
//  main.cpp
//  NY10ASPOJ8612
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

size_t stringCount(const std::string& referenceString,
                   const std::string& subString) {
    
    const size_t step = subString.size();
    
    size_t count(0);
    size_t pos(0) ;
    
    while( (pos=referenceString.find(subString, pos)) !=std::string::npos) {
        pos++;
        ++count ;
    }
    
    return count;
    
}

int main(int argc, const char * argv[])
{
    int n,i,j,t;
    string str;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        cin>>str;
        printf("%d",t);
        int tttCount=stringCount(str, "TTT");
        int tthCount=stringCount(str, "TTH");
        int thtCount=stringCount(str, "THT");
        int thhCount=stringCount(str, "THH");
        int httCount=stringCount(str, "HTT");
        int hthCount=stringCount(str, "HTH");
        int hhtCount=stringCount(str, "HHT");
        int hhhCount=stringCount(str, "HHH");
        printf(" %d %d %d %d %d %d %d %d\n", tttCount, tthCount, thtCount, thhCount, httCount, hthCount, hhtCount, hhhCount);
    }
    return 0;
}

