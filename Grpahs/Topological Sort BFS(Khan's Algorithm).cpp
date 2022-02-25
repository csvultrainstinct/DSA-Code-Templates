#include <bits/stdc++.h>

using namespace std;

vector<int> topoSort(int n,vector<int>adj[]){
    vector<int>inDegree(n+1,0);
    queue<int>q;
    for(auto i=1;i<=n;i++){
        for(auto j:adj[i]){
            inDegree[j]++;
        }
    }
    for(auto i=1;i<=n;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
        for(auto j:adj[temp]){
            inDegree[j]--;
            if(inDegree[j]==0){
                q.push(j);
            }
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
    }
    
    vector<int>ans=topoSort(n,adj);
    for(auto i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
