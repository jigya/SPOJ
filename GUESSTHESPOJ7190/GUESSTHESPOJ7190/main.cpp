//
//  main.cpp
//  GUESSTHESPOJ7190
//
//  Created by Jigya Yadav on 20/09/14.
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

//int main(int argc, const char * argv[])
//{
//    string str;
//    int i, j, n;
//    int cnt = 0;
//    vector< vector< pair<int, int> > > factors(25);
//    factors[1].push_back(make_pair(1, 1));
//    for(i = 2; i <= 20; i++)
//    {
//        n = i;
//        for( j = 2; j*j <= n; j++)
//        {
//            cnt=0;
//            if(n % j == 0)
//            {
//                while(n%j == 0)
//                {
//                    cnt++;
//                    n /= j;
//                }
//                factors[i].push_back( make_pair(j, cnt) );
//            }
//        }
//        if( n != 1)
//        {
//            factors[i].push_back( make_pair(n, 1) );
//        }
//    }
//    
////    for( i = 1; i <= 20; i++)
////    {
////        for(vector<pair<int, int>>::iterator itr=factors[i].begin(); itr != factors[i].end() ; itr++)
////        {
////            cout<<itr->first<<" "<<itr->second<<" ";
////        }
////        cout<<endl;
////    }
//    
//    cin >> str;
//    while(str != "*")
//    {
//        map<int, int> hm;
//        for( i = 0; i < str.length(); i++ )
//        {
//            if( str[i] == 'Y')
//            {
//                for( j = 0; j <= factors[ i + 1 ].size() ; j++ )
//                {
//                    if(hm.count(factors[i+1][j].first) != 0)
//                    {
//                        hm[factors[ i + 1 ][ j ].first]=max(hm[factors[ i + 1 ][ j ].first], factors[i+1][j].second);
//                    }
//                    else
//                    {
//                        hm[factors[ i + 1 ][ j ].first] = factors[ i + 1 ][ j ].second;
//                    }
////                    cout<< factors[i+1][j].first<<" "<<hm[factors[i+1][j].first]<<endl;
//                }
//            }
//        }
//        long long int num = 1;
//        for ( map<int, int>::iterator itr = hm.begin() ; itr != hm.end(); itr++)
//        {
//            for(j = 0; j < itr -> second; j++)
//            {
//                num *= (long long int)itr->first;
//            }
//        }
//        for ( i = 0;  i < str.length(); i++ )
//        {
//            if( (num % (i+1) == 0 && str[i] == 'N') || (num % (i+1) != 0 && str[i] == 'Y'))
//            {
//                break;
//            }
//        }
//        if( i == str.length())
//        {
//            cout<<num<<endl;
//        }
//        else
//        {
//            cout<<"-1"<<endl;
//        }
//        cin>>str;
//    }
//    return 0;
//}


long long int gcd(long long int a, long long int b)
{
    if( b == 0 )
    {
        return a;
    }
    return gcd(b, a % b);
}

long long int lcm(long long int a, long long int b)
{
    return ( a * b )/gcd( a, b);
}

int main()
{
    string str;
    long long int num, i;
    cin  >> str;
    while( str != "*")
    {
        num=1;
        for ( i = 0; i < str.length() ; i++ )
        {
            if( str[i] == 'Y')
            {
                if(num > i+1)
                    num = lcm(num, i+1);
                else
                    num = lcm(i+1, num);
            }
        }
        for ( i = 0;  i < str.length(); i++ )
        {
            if( (num % (i+1) == 0 && str[i] == 'N') || (num % (i+1) != 0 && str[i] == 'Y'))
            {
                break;
            }
        }
        if( i == str.length())
        {
            cout<<num<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
        cin>>str;
    }
    return 0;
}
