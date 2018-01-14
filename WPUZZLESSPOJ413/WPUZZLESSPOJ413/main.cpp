//
//  main.cpp
//  WPUZZLESSPOJ413
//
//  Created by Jigya Yadav on 13/01/15.
//  Copyright (c) 2015 Jigya Yadav. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

const int MAXS = 1500000;

const int MAXC = 26; // Number of characters in the alphabet.

int out[MAXS]; // Output for each state, as a bitwise mask.
// Bit i in this mask is on if the keyword with index i appears when the
// machine enters this state.

// Used internally in the algorithm.
int f[MAXS]; // Failure function
int g[MAXS][MAXC]; // Goto function, or -1 if fail.

int buildMatchingMachine(const vector<string> &words, char lowestChar = 'A', char highestChar = 'Z') {
    memset(out, 0, sizeof out);
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    
    int states = 1; // Initially, we just have the 0 state
    
    for (int i = 0; i < words.size(); ++i) {
        const string &keyword = words[i];
        int currentState = 0;
        for (int j = 0; j < keyword.size(); ++j) {
            int c = keyword[j] - lowestChar;
            if (g[currentState][c] == -1) { // Allocate a new node
                g[currentState][c] = states++;
            }
            currentState = g[currentState][c];
        }
        out[currentState] |= (1 << i); // There's a match of keywords[i] at node currentState.
    }
    
    // State 0 should have an outgoing edge for all characters.
    for (int c = 0; c < MAXC; ++c) {
        if (g[0][c] == -1) {
            g[0][c] = 0;
        }
    }
    
    // Now, let's build the failure function
    queue<int> q;
    for (int c = 0; c <= highestChar - lowestChar; ++c) {  // Iterate over every possible input
        // All nodes s of depth 1 have f[s] = 0
        if (g[0][c] != -1 and g[0][c] != 0) {
            f[g[0][c]] = 0;
            q.push(g[0][c]);
        }
    }
    while (q.size()) {
        int state = q.front();
        q.pop();
        for (int c = 0; c <= highestChar - lowestChar; ++c) {
            if (g[state][c] != -1) {
                int failure = f[state];
                while (g[failure][c] == -1) {
                    failure = f[failure];
                }
                failure = g[failure][c];
                f[g[state][c]] = failure;
                out[g[state][c]] |= out[failure]; // Merge out values
                q.push(g[state][c]);
            }
        }
    }
    
    return states;
}

int findNextState(int currentState, char nextInput, char lowestChar = 'A') {
    int answer = currentState;
    int c = nextInput - lowestChar;
    while (g[answer][c] == -1) answer = f[answer];
    return g[answer][c];
}

int main()
{
    int t, i, j, k, l, c, w;
    scanf("%d", &t);
    char arr[1000][1000];
    char g[2000];
    int currentState;
    while (t--)
    {
        vector<string> keywords;
        map<string, pair<char, pair<int, int> > > ans;
        scanf("%d %d %d", &l, &c, &w);
        for (i = 0; i < l; i++)
        {
            scanf("%s", arr[i]);
        }
        for (i = 0; i < w; i++)
        {
            scanf("%s", g);
            keywords.push_back(g);
        }
        buildMatchingMachine(keywords);
        
        //Horizontal
        for (i = 0; i < l; i++)
        {
            int y = i;
            currentState = 0;
            string text = arr[i];
            for (int i = 0; i < text.size(); ++i) {
                currentState = findNextState(currentState, text[i], 'A');
                if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
                for (int j = 0; j < keywords.size(); ++j) {
                    if (out[currentState] & (1 << j)) { // Matched keywords[j]
//                        cout << "Keyword " << keywords[j] << " appears from "
//                        << i - keywords[j].size() + 1 << " to " << i << endl;
                        ans[keywords[j]] = make_pair('C', make_pair(y, i - keywords[j].size() + 1));
                    }
                }
            }
            currentState = 0;
            reverse(text.begin(), text.end());
            for (int i = 0; i < text.size(); ++i) {
                currentState = findNextState(currentState, text[i], 'A');
                if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
                for (int j = 0; j < keywords.size(); ++j) {
                    if (out[currentState] & (1 << j)) { // Matched keywords[j]
//                        cout << "Keyword " << keywords[j] << " appears from "
//                        << i - keywords[j].size() + 1 << " to " << i << endl;
                        ans[keywords[j]] = make_pair('G', make_pair(y, c - (i - keywords[j].size() + 1) - 1));
                    }
                }
            }
        }
        
        //Vertical
        for (i = 0; i < c; i++)
        {
            int y = i;
            string text;
            currentState = 0;
            for (j = 0; j < l; j++)
            {
                text += arr[j][i];
            }
            for (int i = 0; i < text.size(); ++i) {
                currentState = findNextState(currentState, text[i], 'A');
                if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
                for (int j = 0; j < keywords.size(); ++j) {
                    if (out[currentState] & (1 << j)) { // Matched keywords[j]
//                        cout << "Keyword " << keywords[j] << " appears from "
//                        << i - keywords[j].size() + 1 << " to " << i << endl;
                        ans[keywords[j]] = make_pair('E', make_pair(i - keywords[j].size() + 1, y));
                    }
                }
            }
            currentState = 0;
            reverse(text.begin(), text.end());
            for (int i = 0; i < text.size(); ++i) {
                currentState = findNextState(currentState, text[i], 'A');
                if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
                for (int j = 0; j < keywords.size(); ++j) {
                    if (out[currentState] & (1 << j)) { // Matched keywords[j]
//                        cout << "Keyword " << keywords[j] << " appears from "
//                        << i - keywords[j].size() + 1 << " to " << i << endl;
                        ans[keywords[j]] = make_pair('A', make_pair(l-1-(i - keywords[j].size() + 1), y));
                    }
                }
            }
        }
        
        //Diagonal \ above triangle
        for (i = 0; i < c; i++)
        {
            int y = i;
            string text;
            j = 0;
            k = i;
            while (k < c && j < l)
            {
                text += arr[j][k];
                k++;
                j++;
            }
//            cout<<"Diagonal:"<<text<<endl;
            currentState = 0;
            for (int i = 0; i < text.size(); ++i) {
                currentState = findNextState(currentState, text[i], 'A');
                if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
                for (int j = 0; j < keywords.size(); ++j) {
                    if (out[currentState] & (1 << j)) { // Matched keywords[j]
//                        cout << "Keyword " << keywords[j] << " appears from "
//                        << i - keywords[j].size() + 1 << " to " << i << endl;
                        ans[keywords[j]] = make_pair('D', make_pair(0 + i - keywords[j].size() + 1, y + i - keywords[j].size() + 1));
                    }
                }
            }
            currentState = 0;
            reverse(text.begin(), text.end());
            int len = text.size();
            for (int i = 0; i < text.size(); ++i) {
                currentState = findNextState(currentState, text[i], 'A');
                if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
                for (int j = 0; j < keywords.size(); ++j) {
                    if (out[currentState] & (1 << j)) { // Matched keywords[j]
//                        cout << "Keyword " << keywords[j] << " appears from "
//                        << i - keywords[j].size() + 1 << " to " << i << endl;
                        ans[keywords[j]] = make_pair('H', make_pair(0 + len - 1 - (i - keywords[j].size() + 1), y + len - 1 - (i - keywords[j].size() + 1)));
                    }
                }
            }
        }
        
       
        //Diagonal \ below triangle
        for (i = 1; i < l; i++)
        {
            int y = i;
            string text;
            j = 0;
            k = i;
            while (k < c && j < l)
            {
                text += arr[k][j];
                k++;
                j++;
            }
//            cout<<"Diagonal2:"<<text<<endl;
            currentState = 0;
            for (int i = 0; i < text.size(); ++i) {
                currentState = findNextState(currentState, text[i], 'A');
                if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
                for (int j = 0; j < keywords.size(); ++j) {
                    if (out[currentState] & (1 << j)) { // Matched keywords[j]
//                        cout << "Keyword " << keywords[j] << " appears from "
//                        << i - keywords[j].size() + 1 << " to " << i << endl;
                        ans[keywords[j]] = make_pair('D', make_pair(y + i - keywords[j].size() + 1, 0 + i - keywords[j].size() + 1));
                    }
                }
            }
            currentState = 0;
            reverse(text.begin(), text.end());
            int len = text.size();
            for (int i = 0; i < text.size(); ++i) {
                currentState = findNextState(currentState, text[i], 'A');
                if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
                for (int j = 0; j < keywords.size(); ++j) {
                    if (out[currentState] & (1 << j)) { // Matched keywords[j]
//                        cout << "Keyword " << keywords[j] << " appears from "
//                        << i - keywords[j].size() + 1 << " to " << i << endl;
                        ans[keywords[j]] = make_pair('H', make_pair(y + len - 1 - (i - keywords[j].size() + 1), 0 + len - 1 - (i - keywords[j].size() + 1)));
                    }
                }
            }
        }
        
        //Diagonal / below triangle
        for (i = 0; i < l; i++)
        {
            int y = i;
            string text;
            k = i;
            j = c-1;
            while(j >= 0 && k < l)
            {
                text += arr[k][j];
                k++;
                j--;
            }
            currentState = 0;
            for (int i = 0; i < text.size(); ++i) {
                currentState = findNextState(currentState, text[i], 'A');
                if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
                for (int j = 0; j < keywords.size(); ++j) {
                    if (out[currentState] & (1 << j)) { // Matched keywords[j]
//                        cout << "Keyword " << keywords[j] << " appears from "
//                        << i - keywords[j].size() + 1 << " to " << i << endl;
                        ans[keywords[j]] = make_pair('F', make_pair(y + i - keywords[j].size() + 1, c - 1 - ( i - keywords[j].size() + 1)));
                    }
                }
            }
            currentState = 0;
            reverse(text.begin(), text.end());
            int len =  text.size();
            for (int i = 0; i < text.size(); ++i) {
                currentState = findNextState(currentState, text[i], 'A');
                if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
                for (int j = 0; j < keywords.size(); ++j) {
                    if (out[currentState] & (1 << j)) { // Matched keywords[j]
//                        cout << "Keyword " << keywords[j] << " appears from "
//                        << i - keywords[j].size() + 1 << " to " << i << endl;
                        ans[keywords[j]] = make_pair('B', make_pair(y + (len - 1 - (i - keywords[j].size() + 1)), c - 1 - (len - 1 - (i - keywords[j].size() + 1))));
                    }
                }
            }
        }
        
        //Diagonal / above triangle
        for (i = 0; i < c-1; i++)
        {
            int y = i;
            string text;
            j = 0;
            k = i;
            while (j < l && k >= 0)
            {
                text += arr[j][k];
                k--;
                j++;
            }
            currentState = 0;
            for (int i = 0; i < text.size(); ++i) {
                currentState = findNextState(currentState, text[i], 'A');
                if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
                for (int j = 0; j < keywords.size(); ++j) {
                    if (out[currentState] & (1 << j)) { // Matched keywords[j]
//                        cout << "Keyword " << keywords[j] << " appears from "
//                        << i - keywords[j].size() + 1 << " to " << i << endl;
                        ans[keywords[j]] = make_pair('F', make_pair(0 + i - keywords[j].size() + 1, y - ( i - keywords[j].size() + 1)));
                    }
                }
            }
            currentState = 0;
            reverse(text.begin(), text.end());
            int len = text.size();
            for (int i = 0; i < text.size(); ++i) {
                currentState = findNextState(currentState, text[i], 'A');
                if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
                for (int j = 0; j < keywords.size(); ++j) {
                    if (out[currentState] & (1 << j)) { // Matched keywords[j]
//                        cout << "Keyword " << keywords[j] << " appears from "
//                        << i - keywords[j].size() + 1 << " to " << i << endl;
                        ans[keywords[j]] = make_pair('B', make_pair(0 + (len - 1 - (i - keywords[j].size() + 1)), y - (len - 1 - (i - keywords[j].size() + 1))));
                    }
                }
            }
        }
        for (vector<string>::iterator itr = keywords.begin(); itr != keywords.end(); itr++)
        {
            printf("%d %d %c\n", ans[*itr].second.first, ans[*itr].second.second, ans[*itr].first);
        }
        printf("\n");
    }
    return 0;
    
}

