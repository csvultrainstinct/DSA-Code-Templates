#include <bits/stdc++.h>

using namespace std;

vector<int> ShortestPath(int n,vector<pair<int,int>>adj[],int s){
    vector<int>dist(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
    pq.push({0,s});
    while(!pq.empty()){
        int tempdist=pq.top().first;
        int tempnode=pq.top().second;
        pq.pop();
        for(auto i:adj[tempnode]){
            if(i.second+tempdist<dist[i.first]){
                dist[i.first]=i.second+tempdist;
                pq.push({dist[i.first],i.first});
            }
        }
    }
    
    return dist;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for(auto i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int s;
    cin>>s;
    vector<int>ans=ShortestPath(n,adj,s);
    for(auto i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

return 0;
}
