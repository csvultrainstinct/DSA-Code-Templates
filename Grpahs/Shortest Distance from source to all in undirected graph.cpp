
#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(int n,vector<int> adj[],int s){
    vector<int>dist(n+1,INT_MAX);
    queue<int>q;
    
    dist[s]=0;
    q.push(s);
    
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        
        for(auto i:adj[temp]){
            if(dist[temp]+1<dist[i]){
                dist[i]=dist[temp]+1;
                q.push(i);
            }
        }
    }
    
    return dist;    
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(auto i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s;
    cin>>s;
    vector<int>dist=shortestPath(n,adj,s);
    
    for(auto i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}
