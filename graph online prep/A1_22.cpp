#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<int>> adj(N+1);
    for(int i=0;i<M;i++){
        int p,c;
        cin>>p>>c;
        adj[c].push_back(p);
    }

    int Q;
    cin>>Q;
    for(int qry=0;qry<Q;qry++){
        int r;
        cin>>r;
        vector<bool> visited(N+1,false);
        queue<int> q;
        int cnt=0;
        q.push(r);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int pre:adj[node]){
                if(!visited[pre]){
                    visited[pre]=true;
                    cnt++;
                    q.push(pre);

                }
            }
        }
        cout<<cnt;
        
    }
}