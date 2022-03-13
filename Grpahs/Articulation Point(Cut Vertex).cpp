#include <bits/stdc++.h>

using namespace std;

void dfs(int i,int parent,vector<int>&tin,vector<int>&low,vector<int>&vis,vector<int>adj[],int timer,vector<int>&ans){
    vis[i]=1;
    tin[i]=timer++;
    low[i]=timer++;
    int child=0;
    for(auto j:adj[i]){
        if(j==parent){
            continue;
        }
        if(!vis[j]){
            dfs(j,i,tin,low,vis,adj,timer,ans);
            low[i]=min(low[i],low[j]);
            if(low[j]>=tin[i]&&parent!=-1){
                ans[i]=1;
            }
            child++;
        }
        else{
            low[i]=min(low[i],tin[j]);
        }
    }
    if(parent==-1 && child>1){
        ans[i]=1;
    }
}

vector<int> articulationPoints(int n, vector<int>adj[]){
    vector<int>tin(n+1,-1);
    vector<int>low(n+1,-1);
    vector<int>vis(n+1,0);
    vector<int>ans(n+1,0);
    int timer=0;
    for(auto i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,-1,tin,low,vis,adj,timer,ans);
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
    vector<int>ans(n+1,0);
    ans=articulationPoints(n,adj);
    for(auto i=0;i<ans.size();i++){
        if(ans[i]==1){
        cout<<ans[i]<<" ";
        }
    }

    return 0;
}
