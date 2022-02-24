#include <bits/stdc++.h>

using namespace std;

bool CheckDFS(int i,vector<int>adj[],vector<int> &vis,int n){
    vector<int>dfsvis(n+1,0);
    if(!vis[i]){
        vis[i]=1;
        dfsvis[i]=1;
    }
    for(auto j:adj[i]){
        if(!vis[i]){
            vis[i]=1;
            dfsvis[i]=1;
            if(CheckDFS(j,adj,vis,n)){
                return true;
            }
        }
        else if(vis[i] && dfsvis[i]){
            return true;
        }
    }
 
    return false;   
}

bool isCycle(int n,vector<int>adj[]){
    vector<int>vis(n+1,0);
    for(auto i=1;i<=n;i++){
        if(!vis[i]){
            if(CheckDFS(i,adj,vis,n)){
                return true;
            }
        }
    }
    
    return false;
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
    
    cout<<isCycle(n,adj)<<endl;
    
    return 0;
}
