/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

struct node{
    int u;
    int v;
    int w;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        w = weight;
    }
    
};

bool comp(node a,node b){
    return a.w<b.w;
}

int findPar(int n,vector<int> &par){
    if(n==par[n]) return n;
    return par[n]=findPar(par[n],par);
}

void unions(int u,int v,vector<int>&par,vector<int>&rank){
     u=findPar(u,par);
     v=findPar(v,par);
    if(rank[u]<rank[v]){
        par[u]=v;
    }
    else if(rank[u]>rank[v]){
        par[v]=u;
    }
    else{
        par[v]=u;
        rank[u]++;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<node>edges;
    for(auto i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    sort(edges.begin(),edges.end(),comp);
    
    vector<int> par(n);
    for(auto i=0;i<n;i++){
        par[i]=i;
    }
    vector<int>rank(n,0);
    int cost=0;
    
    vector<pair<int,int>>mst;
    for(auto i:edges){
        if(findPar(i.u,par)!=findPar(i.v,par)){
            cost+=i.w;
            mst.push_back({i.u,i.v});
            unions(i.u,i.v,par,rank);
        }
    }
    cout<<cost<<endl;
    for(auto i:mst){
        cout<<i.first<<"-->"<<i.second<<endl;
    }
    return 0;
}
