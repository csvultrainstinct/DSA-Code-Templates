#include <bits/stdc++.h>

using namespace std;

void dfs(int i,vector<int>adj[],vector<int>&vis,stack<int>&s){
    vis[i]=1;
    for(auto j:adj[i]){
        if(!vis[j]){
            dfs(j,adj,vis,s);
        }
    }
    
    s.push(i);
}


vector<int> topoSort(int n, vector<int>adj[]){
    vector<int>vis(n+1,0);
    vector<int>ans;
    stack<int>s;
    for(auto i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,s);
        }
    }
    
    while(!s.empty()){
        int temp=s.top();
        s.pop();
        ans.push_back(temp);
    }
    
    return ans;
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
    }
    
    vector<int>ans=topoSort(n,adj);
    for(auto i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
