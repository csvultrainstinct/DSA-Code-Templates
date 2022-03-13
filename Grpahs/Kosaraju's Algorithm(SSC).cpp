#include <bits/stdc++.h>

using namespace std;

void dfs(int i,vector<int>adj[],stack<int>&st,vector<int>&vis){
    vis[i]=1;
    for(auto j:adj[i]){
        if(!vis[j]){
            dfs(j,adj,st,vis);
        }
    }
    st.push(i);
}

void revDfs(int i,vector<int>transpose[],vector<int>&vis,vector<int>&ans){
    ans.push_back(i);
    vis[i]=1;
    for(auto j:transpose[i]){
        if(!vis[j]){
            revDfs(j,transpose,vis,ans);
        }
    }
}

vector<vector<int>> KosaRajusAlgorithm(int n, vector<int>adj[]){
    stack<int>st;
    vector<int>vis(n+1,0);
    for(auto i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,st,vis);
        }
    }
    vector<int>transpose[n+1];
    for(auto i=1;i<=n;i++){
        vis[i]=0;
        for(auto j:adj[i]){
            transpose[j].push_back(i);
        }
    }
    vector<vector<int>>ssc;
    vector<int>ans;
    
    while(!st.empty()){
        int temp=st.top();
        st.pop();
        if(!vis[temp]){
            revDfs(temp,transpose,vis,ans);
            ssc.push_back(ans);
        }
    }
    
    return ssc;
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
    vector<vector<int>>ans=KosaRajusAlgorithm(n,adj);
    
    for(auto i=0;i<ans.size();i++){
        for(auto j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
