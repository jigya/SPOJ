//
//  main.cpp
//  TEMSPOJ757
//
//  Created by Jigya Yadav on 31/01/15.
//  Copyright (c) 2015 Jigya Yadav. All rights reserved.
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
#include <sstream>
#include <cfloat>
#define ll long long int

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-6

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

using namespace std;

int arr[55][55][55];
ll sum_arr[55][55][55];
ll temp[50];
int start, finish;

ll find_submatrix_sum(int x, int y1, int y2, int z1, int z2)
{
//    cout<<"In func: "<<x<<" "<<y1<<" "<<z1<<" "<<y2<<" "<<z2<<" ";
    ll sum = sum_arr[x][y2][z2]-sum_arr[x][y1-1][z2]-sum_arr[x][y2][z1-1]+sum_arr[x][y1-1][z1-1];
//    cout<<sum<<endl;
    return sum;
}

ll kadane(int z)
{
    finish = -1;
    ll max_so_far = temp[0];
    ll curr_max = temp[0];
    int local_start = 0;
    forall(i, 1, z)
    {
        curr_max = curr_max+temp[i];
        if (curr_max < 0)
        {
            curr_max = 0;
            local_start = i+1;
        }
        else if(curr_max > max_so_far)
        {
            max_so_far = curr_max;
            start = local_start;
            finish = i;
        }
    }
    if (finish != -1)
    {
        return max_so_far;
    }
    max_so_far = temp[0];
    start = finish = 0;
    forall(i, 1, z)
    {
        if (temp[i] > max_so_far)
        {
            max_so_far = temp[i];
            start = finish = i;
        }
    }
    return max_so_far;
}

int main(int argc, const char * argv[])
{
    int t, x, y, z, x1, y1, x2, y2, z1, z2;
    s(t);
    while (t--)
    {
        ll max_sum = LONG_LONG_MIN;
        memset(sum_arr, 0, sizeof(sum_arr));
        s(x);
        s(y);
        s(z);
        forall(i, 1, x+1)
        {
            forall(j, 1, y+1)
            {
                forall(k, 1, z+1)
                {
                    s(arr[i][j][k]);
                }
            }
        }
//        forall(k, 1, z+1)
//        {
//            forall(i, 1, x+1)
//            {
//                forall(j, 1, y+1)
//                {
//                    cout<<arr[i][j][k]<<" ";
//                }
//                cout<<endl;
//            }
//            cout<<endl;
//        }
        
//        cout<<"__________________________________"<<endl;
        forall(i, 1, x+1)
        {
            forall(j, 1, y+1)
            {
                forall(k, 1, z+1)
                {
                    if (k == 1 && j == 1)
                    {
                        sum_arr[i][j][k] = (ll)arr[i][j][k];
                    }
                    else if(k == 1)
                    {
                        sum_arr[i][j][k] = arr[i][j][k]+sum_arr[i][j-1][k];
                    }
                    else if(j == 1)
                    {
                        sum_arr[i][j][k] = arr[i][j][k]+sum_arr[i][j][k-1];
                    }
                    else
                    {
                        sum_arr[i][j][k] = sum_arr[i][j][k-1]+sum_arr[i][j-1][k]-sum_arr[i][j-1][k-1]+arr[i][j][k];
                    }
//                    cout<<sum_arr[i][j][k]<<" ";
                }
//                cout<<endl;
            }
//            cout<<endl;
        }
//        cout<<x<<" "<<y<<" "<<z<<endl;
        forall(left, 1, y+1)
        {
            forall(right, left, y+1)
            {
                forall(top, 1, z+1)
                {
                    forall(bottom, top, z+1)
                    {
//                        cout<<"here: "<<left<<" "<<right<<" "<<top<<" "<<bottom<<endl;
                        forall(i, 1, x+1)
                        {
                            temp[i-1] = find_submatrix_sum(i, left, right, top, bottom);
//                            cout<<temp[i-1]<<" ";
                        }
                        ll w = kadane(x);
                        start++;
                        finish++;
//                        cout<<"Max: "<<w<<" "<<start<<" "<<finish<<endl;
                        if (w > max_sum)
                        {
                            y1 = left;
                            y2 = right;
                            z1 = top;
                            z2 = bottom;
                            x1 = start;
                            x2 = finish;
                            max_sum = w;
                        }
                    }
                }
            }
        }
        printf("%d %d %d %d %d %d\n", x1, y1, z1, x2, y2, z2);
    }
    return 0;
}

