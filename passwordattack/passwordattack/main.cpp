// AUTHOR : SIKANDER MAHAN
// sikander_nsit
// PLAGIARISM IS BAD

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string.h>

#define tr(type,c,it) for(type::iterator it=c.begin();it!=c.end();++it)
#define all(c) c.begin(),c.end()
#define mod 10000007
#define itor(c) c::iterator
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define si set<int>
#define msi multiset<int>
#define ii pair<int,int>
#define sii set<ii>
#define vii vector<ii>
#define vvi vector<vi>
#define pb push_back
#define mp make_pair

using namespace std;

vector<int> vec[1000001];
void AllFactors(int n)
{
    int sqn=sqrt(n);
    int i,j,k;
    for(i=1;i<=sqn;++i)
    {
        j=i*i;
        vec[j].pb(i);
        j+=i;
        for(k=i+1;j<=n;j+=i,++k)
        {
            vec[j].pb(i);
            vec[j].pb(k);
        }
    }
}

int ans[1000002]={0};

int main()
{
    //ios::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t=0,i=0,j=0,n=0,m=0,k=0,num=0,temp=0,ind=0,sz;
    AllFactors(1000000);
    for (i = 0; i <= 1000; i++)
    {
        cout<<i<<" ";
        tr(vector<int>, vec[i], it)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    cin>>t;
    string str;
    int digit[10]={0};
    for(i=0;i<t;++i)
    {
        cout<<"Case #"<<i+1<<": ";
        for(j=0;j<10;++j)
        {
            cin>>digit[j];
        }
        cin>>n;
        for(j=1;j<=n;++j)
        {
            temp=j;
            num=0;
            while(temp>0)
            {
                if(digit[temp%10]==0)
                    break;
                temp/=10;
                num++;
            }
            if(temp==0)
            {
                ans[j]=num;
            }
            else
            {
                ans[j]=mod;
            }
        }
        for(j=1;j<=n;++j)
        {
            if(ans[j]!=mod)
                continue;
            else
            {
                sz=vec[j].size();
                if(sz&1)
                {
                    ans[j]=min(ans[j],2*ans[vec[j][sz-1]]+1);
                    sz--;
                }
                for(k=0;k<sz;k+=2)
                {
                    ans[j]=min(ans[j],1+ans[vec[j][k]]+ans[vec[j][k+1]]);
                }
            }
        }
        if(ans[n]!=mod)
            cout<<ans[n]+1;
        else
            cout<<"Impossible";
        cout<<"\n";
    }
    return 0;
}
