#include <bits/stdc++.h>

using namespace std;

bool CycleDetection(int n,vector<int>adj[]){
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
    int c=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            c++;
        for(auto j:adj[temp]){
            inDegree[j]--;
            if(inDegree[j]==0){
                q.push(j);
            }
        }
    }
    
   return (c==n); 
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
    
    cout<<CycleDetection(n,adj)<<endl;

    return 0;
}
