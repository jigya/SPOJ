//
//  main.cpp
//  THREECOLSPOJ207
//
//  Created by Jigya Yadav on 07/01/15.
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

using namespace std;

int pos;

//m_green, m_blue, m_red represent the max number of green nodes in the subtree rooted at this node if the current node is green, blue or red respectively
struct node
{
public:
    node *left;
    node *right;
    int num;
    int m_green;
    int m_blue;
    int m_red;
};

node *buildTree(char *str)
{
    node *d = (node*)malloc(sizeof(node));
    d->num = pos;
    if (str[pos] == '0')
    {
        d->left = NULL;
        d->right = NULL;
        pos++;
    }
    else if(str[pos] == '1')
    {
        pos++;
        d->left = buildTree(str);
        d->right = NULL;
    }
    else if(str[pos] == '2')
    {
        pos++;
        d->left = buildTree(str);
        d->right = buildTree(str);
    }
    d->m_green = d->m_blue = d->m_red = -1;
    return d;
}


//0 - green
//1 - blue
//2 - red
void solevMax(node *root, int color)
{
    if (color == 0 && root->m_green == -1)
    {
        if (root->left && root->right)
        {
            solevMax(root->left, 1);
            solevMax(root->left, 2);
            solevMax(root->right, 1);
            solevMax(root->right, 2);
            root->m_green = min(root->left->m_blue + root->right->m_red, root->left->m_red + root->right->m_blue)+1;
        }
        else if(root->left)
        {
            solevMax(root->left, 1);
            solevMax(root->left, 2);
            root->m_green = min(root->left->m_blue, root->left->m_red)+1;
        }
        else
        {
            root->m_green = 1;
        }
    }
    else if(color == 1 && root->m_blue == -1)
    {
        if (root->left && root->right)
        {
            solevMax(root->left, 0);
            solevMax(root->left, 2);
            solevMax(root->right, 0);
            solevMax(root->right, 2);
            root->m_blue = min(root->left->m_green + root->right->m_red, root->left->m_red + root->right->m_green);
        }
        else if(root->left)
        {
            solevMax(root->left, 0);
            solevMax(root->left, 2);
            root->m_blue = min(root->left->m_green, root->left->m_red);
        }
        else
        {
            root->m_blue = 0;
        }
    }
    else if(color == 2 && root->m_red == -1)
    {
        if (root->left && root->right)
        {
            solevMax(root->left, 0);
            solevMax(root->left, 1);
            solevMax(root->right, 0);
            solevMax(root->right, 1);
            root->m_red = min(root->left->m_green + root->right->m_blue, root->left->m_blue + root->right->m_green);
        }
        else if(root->left)
        {
            solevMax(root->left, 0);
            solevMax(root->left, 1);
            root->m_red = min(root->left->m_green, root->left->m_blue);
        }
        else
        {
            root->m_red = 0;
        }
    }
}

void solevMin(node *root, int color)
{
    if (color == 0 && root->m_green == -1)
    {
        if (root->left && root->right)
        {
            solevMin(root->left, 1);
            solevMin(root->left, 2);
            solevMin(root->right, 1);
            solevMin(root->right, 2);
            root->m_green = max(root->left->m_blue + root->right->m_red, root->left->m_red + root->right->m_blue)+1;
        }
        else if(root->left)
        {
            solevMin(root->left, 1);
            solevMin(root->left, 2);
            root->m_green = max(root->left->m_blue, root->left->m_red)+1;
        }
        else
        {
            root->m_green = 1;
        }
    }
    else if(color == 1 && root->m_blue == -1)
    {
        if (root->left && root->right)
        {
            solevMin(root->left, 0);
            solevMin(root->left, 2);
            solevMin(root->right, 0);
            solevMin(root->right, 2);
            root->m_blue = max(root->left->m_green + root->right->m_red, root->left->m_red + root->right->m_green);
        }
        else if(root->left)
        {
            solevMin(root->left, 0);
            solevMin(root->left, 2);
            root->m_blue = max(root->left->m_green, root->left->m_red);
        }
        else
        {
            root->m_blue = 0;
        }
    }
    else if(color == 2 && root->m_red == -1)
    {
        if (root->left && root->right)
        {
            solevMin(root->left, 0);
            solevMin(root->left, 1);
            solevMin(root->right, 0);
            solevMin(root->right, 1);
            root->m_red = max(root->left->m_green + root->right->m_blue, root->left->m_blue + root->right->m_green);
        }
        else if(root->left)
        {
            solevMin(root->left, 0);
            solevMin(root->left, 1);
            root->m_red = max(root->left->m_green, root->left->m_blue);
        }
        else
        {
            root->m_red = 0;
        }
    }
}


int main(int argc, const char * argv[])
{
    int t;
    char arr[10200];
    scanf("%d", &t);
    while (t--)
    {
        node *root1, *root2;
        scanf("%s", arr);
//        cout<<arr<<endl;
        pos = 0;
        root1=buildTree(arr);
        pos = 0;
        root2=buildTree(arr);
//        cout<<"here"<<endl;
        solevMax(root1, 0);
        solevMax(root1, 1);
        solevMax(root1, 2);
        solevMin(root2, 0);
        solevMin(root2, 1);
        solevMin(root2, 2);
        int minAns = min(root1->m_blue, min(root1->m_green, root1->m_red));
        int maxAns = max(root2->m_blue, max(root2->m_green, root2->m_red));
//        cout<<root1->m_blue<<" "<<root1->m_green<<" "<<root1->m_red<<endl;
//        cout<<root2->m_blue<<" "<<root2->m_green<<" "<<root2->m_red<<endl;
        cout<<maxAns<<" "<<minAns<<endl;
    }
    return 0;
}

