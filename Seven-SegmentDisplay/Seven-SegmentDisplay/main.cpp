//
//  main.cpp
//  Seven-SegmentDisplay
//
//  Created by Jigya Yadav on 08/11/14.
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
#include<math.h>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
#include<fstream>
#include <sstream>

#define ll long long int

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
#define toChar(a) a+'0'

using namespace std;

int main(int argc, const char * argv[])
{
    int t, i, j, k, m, n;
    freopen("/Users/jigyayadav/downloads/A-small-practice.in.txt", "r", stdin);
    freopen("/Users/jigyayadav/downloads/A-small-practiceout.txt", "w", stdout);
    string str, wr;
    cin >> t;
    char works[15];
    vector<string> arr;
    vector<string> comb;
    for (int s = 1; s <= t; s++)
    {
        memset(works, '2', sizeof(works));
//        forall(i, 0, 7)
//            cout<<works[i]<<endl;
        arr.clear();
        comb.clear();
        cin >> n;
        forall(i, 0, n)
        {
            cin >> str;
//            cout<<"str="<<str<<endl;
            arr.push_back(str);
            forall(j, 0, 7)
            {
                if (str[j] == '1')
                {
                    works[j] = '1';
                }
            }
        }
//        forall(i, 0, 7)
//            cout<<works[i]<<endl;
        string zero="", one="", two="", three="", four="", five="", six="", seven="", eight="", nine="";
        stringstream ss;
        ss<<works[0]<<works[1]<<works[2]<<works[3]<<works[4]<<works[5]<<"0";
        zero=ss.str();
        ss.str("");
        ss<<"0"<<works[1]<<works[2]<<"0"<<"0"<<"0"<<"0";
        one=ss.str();
        ss.str("");
        ss<<works[0]<<works[1]<<"0"<<works[3]<<works[4]<<"0"<<works[6];
        two=ss.str();
        ss.str("");
        ss<<works[0]<<works[1]<<works[2]<<works[3]<<"0"<<"0"<<works[6];
        three=ss.str();
        ss.str("");
        ss<<"0"<<works[1]<<works[2]<<"0"<<"0"<<works[5]<<works[6];
        four=ss.str();
        ss.str("");
        ss<<works[0]<<"0"<<works[2]<<works[3]<<"0"<<works[5]<<works[6];
        five=ss.str();
        ss.str("");
        ss<<works[0]<<"0"<<works[2]<<works[3]<<works[4]<<works[5]<<works[6];
        six=ss.str();
        ss.str("");
        ss<<works[0]<<works[1]<<works[2]<<"0"<<"0"<<"0"<<"0";
        seven=ss.str();
        ss.str("");
        ss<<works[0]<<works[1]<<works[2]<<works[3]<<works[4]<<works[5]<<works[6];
        eight=ss.str();
        ss.str("");
        ss<<works[0]<<works[1]<<works[2]<<works[3]<<"0"<<works[5]<<works[6];
        nine=ss.str();
        ss.str("");
        comb.push_back(nine);
        comb.push_back(eight);
        comb.push_back(seven);
        comb.push_back(six);
        comb.push_back(five);
        comb.push_back(four);
        comb.push_back(three);
        comb.push_back(two);
        comb.push_back(one);
        comb.push_back(zero);
//        foreach(v, comb)
//        {
//            cout<<*v<<endl;
//        }
        int cnt = 0;
        string rslt;
        for (i = 0; i < 10; i++)
        {
            k = i;
            for (j = 0; j < n; j++, k = (k+1)%10)
            {
                bool flag = true;
                for (m = 0; m < 7; m++)
                {
                    if (comb[k][m] == '2')
                    {
                        continue;
                    }
                    else if(comb[k][m] != arr[j][m])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                {
                    break;
                }
            }
            if (j == n)
            {
                cnt++;
                rslt = comb[k];
            }
        }
        if (cnt > 1 || cnt == 0)
        {
            cout<<"Case #"<<s<<": ";
            cout << "ERROR!" <<endl;
        }
        else
        {
            cout<<"Case #"<<s<<": ";
            cout<<rslt<<endl;
        }
    }
    return 0;
}

