#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
    int T,N;
    cin>>T;
    
    for(	; T-- ;     )
    {
        cin>>N;
        bool visited[10002][9];
        memset(visited, 0, sizeof visited);
        queue <string> q;
        q.push("6");
        q.push("8");
        
        string result;
        while(!q.empty())
        {
            string S=q.front();
            q.pop();
            
            int mod=0;
            for( int digit=0 ; digit<S.size() ; digit++ )
            {
                mod=((mod*10)+S[digit]-'0')%N;
            }
            if(mod==0)
            {
                result=S;
                break;
            }
            
            if(!visited[mod][S[S.size()-1] - '0'])
            {
                visited[mod][S[S.size()-1] - '0']=true;
                q.push(S+"6");
                if(S[S.size()-1] == '8')
                    q.push(S+"8");
            }
        }
        cout<<((result=="")?"-1":result)<<endl;
    }
    return 0;
}