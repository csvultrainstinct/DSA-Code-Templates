#include <bits/stdc++.h>

using namespace std;

vector<int> PrimsAlgo(int n,vector<pair<int,int>>adj[]){
    vector<int>par(n,-1);
    vector<int>key(n,INT_MAX);
    vector<int>mst(n,false);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
    
    key[0]=0;
    par[0]=-1;
    pq.push({0,0});
    
    while(!pq.empty()){
        int temp=pq.top().second;
        pq.pop();
        
        mst[temp]=true;
        for(auto j:adj[temp]){
            int u=j.first;
            int weight=j.second;
            if(mst[u]==false && weight<key[u]){
                par[u]=temp;
                key[u]=weight;
                pq.push({key[u],u});
            }
        }
    }
    
    return par;
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
    
    vector<int>ans=PrimsAlgo(n,adj);
    
    for(auto i=0;i<ans.size();i++){
        cout<<ans[i]<<"->"<<i<<endl;
    }

    return 0;
}
