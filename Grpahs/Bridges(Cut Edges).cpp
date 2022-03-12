#include <bits/stdc++.h>

using namespace std;


void dfs(int i,int parent,vector<int>adj[],vector<int>&tin,vector<int>&low,vector<int>&vis,int timer,vector<pair<int,int>>&ans){
    vis[i]=1;
    tin[i]=timer++;
    low[i]=timer++;
    for(auto j:adj[i]){
        if(j==parent){
            continue;
        }
        if(!vis[j]){
        dfs(j,i,adj,tin,low,vis,timer,ans);
        low[i]=min(low[j],low[i]);
        if(low[j]>tin[i]){
            ans.push_back({i,j});
        }
        }
        else{
            low[i]=min(low[i],tin[j]);
        }
    }
}

vector<pair<int,int>> bridges(int n, vector<int> adj[]){
    vector<int>tin(n+1,-1);
    vector<int>low(n+1,-1);
    vector<int>vis(n+1,0);
    int timer=0;
    vector<pair<int,int>>ans;
    for(auto i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,-1,adj,tin,low,vis,timer,ans);
        }
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
        adj[v].push_back(u);
    }
    vector<pair<int,int>>ans=bridges(n,adj);
    for(auto i:ans){
        cout<<i.first<<"-->"<<i.second<<endl;
    }

    return 0;
}
