//
//  main.cpp
//  TETRASPOJ16
//
//  Created by Jigya Yadav on 06/11/14.
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
#include<iomanip>

using namespace std;

#define ll long long int

int main(int argc, const char * argv[])
{
    int n;
    double u, v, w, U, V, W, udash, vdash, wdash;
    double volume, a1, a2, a3, a4, s1, s2, s3, s4, r;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&u, &v, &w, &W, &V, &U);
        udash = v*v+w*w-U*U;
        vdash = w*w+u*u-V*V;
        wdash = u*u+v*v-W*W;
        volume = sqrt(4*u*u*v*v*w*w-u*u*udash*udash-v*v*vdash*vdash-w*w*wdash*wdash+udash*vdash*wdash)/12.0;
        s1 = (u + v + W)/2.0;
        s2 = (v + w + U)/2.0;
        s3 = (w + u + V)/2.0;
        s4 = (U + V + W)/2.0;
        a1 = sqrt(s1 * (s1 - u) * (s1 - v) * (s1 - W));
        a2 = sqrt(s2 * (s2 - v) * (s2 - w) * (s2 - U));
        a3 = sqrt(s3 * (s3 - w) * (s3 - u) * (s3 - V));
        a4 = sqrt(s4 * (s4 - U) * (s4 - V) * (s4 - W));
        r = (3.0*volume)/(a1+a2+a3+a4);
        printf("%.4lf\n", r);
    }
    return 0;
}

