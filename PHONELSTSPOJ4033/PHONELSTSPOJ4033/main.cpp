//
//  main.cpp
//  PHONELSTSPOJ4033
//
//  Created by Jigya Yadav on 30/08/14.
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
#include <fstream>

using namespace std;

class Trie
{
private:
    int words;
    int prefixes;
    Trie* edges[10];
public:
    
    //Constructor for the trie
    Trie()
    {
        words=0;
        prefixes=0;
        for(int i=0;i<10;i++)
        {
            edges[i]=NULL;
        }
    }
    
    //Add a word to the trie
    bool addWord(string str)
    {
        //Empty string means we have inserted the string
        //Update the number of words ending at this node
        if(str.empty())
        {
            words++;
            if(prefixes>0 || words>1)
            {
                return false;
            }
            else
                return true;
        }
        else
        {
            //Update the number of prefixes for this node
            prefixes++;
            
            //Check if there are words ending at this position
            if(words>0)
            {
                return false;
            }
            char firstCharacter=str[0];
            if(edges[firstCharacter-'0']==NULL)
            {
                edges[firstCharacter-'0']=new Trie();
            }
            return edges[firstCharacter-'0']->addWord(str.substr(1));
        }
    }
};
int main(int argc, const char * argv[])
{
    int i,j,k,m,n,t;
    bool flag;
    string str;
    scanf("%d",&t);
    while (t--)
    {
        Trie tr;
        flag=true;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>str;
            flag=flag&tr.addWord(str);
        }
        if(flag==false)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}

