#include <bits/stdc++.h>

using namespace std;

void TopoSort(int i,vector<pair<int,int>>adj[],vector<int> &vis,stack<int> &st){
    vis[i]=1;
    for(auto j:adj[i]){
        if(!vis[i]){
            TopoSort(j.first,adj,vis,st);
        }
    }
    st.push(i);
    
}

vector<int> ShortestPath(int n,vector<pair<int,int>>adj[],int s){
    vector<int>vis(n+1,0);
    stack<int>st;
    for(auto i=1;i<=n;i++){
        if(!vis[i]){
            TopoSort(i,adj,vis,st);
        }
    }
    vector<int>dist(n+1,INT_MAX);
    dist[s]=0;
    while(!st.empty()){
        int temp=st.top();
        st.pop();
        if(dist[temp]!=INT_MAX){
        for(auto i:adj[temp]){
            if(dist[temp]+i.second<dist[i.first]){
                dist[i.first]=dist[temp]+i.second;
            }
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
    }
    int s;
    cin>>s;
    vector<int>ans=ShortestPath(n,adj,s);
    for(auto i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
