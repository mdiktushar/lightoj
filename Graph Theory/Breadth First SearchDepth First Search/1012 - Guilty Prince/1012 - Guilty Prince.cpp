#include<bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    int t;cin>>t;
    int tc=1;
    while(t--)
    {
        pair<int, int>P;
        int s1=0, s2=0;
        int r,c;cin>>c>>r;
        char a[r][c];
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
            {
                char b;cin>>b;
                a[i][j]=b;
                if(b=='@')
                {
                    P.first = i;
                    P.second = j;
                }
            }

        queue<pair<int,int>>Q;
        vector<lli>v;
        Q.push(P);
        v.push_back(P.first*23+P.second);

        /** BFS **/
        while(Q.size()!=0)
        {
            int R = Q.front().first;
            int C = Q.front().second;
            if(R-1>=0 && a[R-1][C]=='.')
            {
                P.first=R-1; P.second=C;
                if(find(v.begin(),v.end(),P.first*23+P.second)==v.end()){
                    Q.push(P);
                    v.push_back(P.first*23+P.second);
                }
            }
            if(R+1<r && a[R+1][C]=='.')
            {
                P.first=R+1; P.second=C;
                if(find(v.begin(),v.end(),P.first*23+P.second)==v.end()){
                    Q.push(P);
                    v.push_back(P.first*23+P.second);
                }
            }
            if(C-1>=0 && a[R][C-1]=='.')
            {
                P.first=R; P.second=C-1;
                if(find(v.begin(),v.end(),P.first*23+P.second)==v.end()){
                    Q.push(P);
                    v.push_back(P.first*23+P.second);
                }
            }
            if(C+1<c && a[R][C+1]=='.')
            {
                P.first=R; P.second=C+1;
                if(find(v.begin(),v.end(),P.first*23+P.second)==v.end()){
                    Q.push(P);
                    v.push_back(P.first*23+P.second);
                }
            }
            Q.pop();
        }
        cout<<"Case "<<tc++<<": "<<v.size()<<endl;
    }
    return 0;
}

