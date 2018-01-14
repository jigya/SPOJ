//
//  main.cpp
//  BYECAKESSPOJ7185
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
    int a,b,c,d;
    int presentE, presentF, presentS, presentM, reqE, reqF, reqS, reqM;
    scanf("%d%d%d%d%d%d%d%d", &presentE, &presentF, &presentS, &presentM, &reqE, &reqF, &reqS, &reqM);
    while(presentE!=-1)
    {
        a=ceil(presentE/(double)reqE);
        b=ceil(presentF/(double)reqF);
        c=ceil(presentS/(double)reqS);
        d=ceil(presentM/(double)reqM);
        int maxVal=max(a, max(b, max(c,d)));
        printf("%d %d %d %d\n", reqE*maxVal-presentE, reqF*maxVal-presentF, reqS*maxVal-presentS, reqM*maxVal-presentM);
        scanf("%d%d%d%d%d%d%d%d", &presentE, &presentF, &presentS, &presentM, &reqE, &reqF, &reqS, &reqM);
    }
    return 0;
}

