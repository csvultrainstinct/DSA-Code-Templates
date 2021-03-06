#include <bits/stdc++.h>

using namespace std;

bool bipartiteBFS(int i,vector<int>adj[],vector<int>& color){
    queue<int>q;
    q.push(i);
    color[i]=1;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto j:adj[i]){
            if(color[j]==-1){
                color[j]=1-color[i];
                q.push(j);
            }
            else if(color[i]==color[j]){
                return false;
            }
        }
    }
    
    return true;
}

bool isBipartite(int n,vector<int>adj[]){
    vector<int>color(n+1,-1);
    for(auto i=1;i<=n;i++){
        if(color[i]==-1){
            if(!bipartiteBFS(i,adj,color)){
                return false;
            }
        }
    }
    
    return true;
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

    cout<<isBipartite(n,adj)<<endl;

    return 0;
}
