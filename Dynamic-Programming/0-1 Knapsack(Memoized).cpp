#include <bits/stdc++.h>

using namespace std;

int Helper(int i,int w,vector<int>wt,vector<int>val,vector<vector<int>> &dp){
    if(i==0 || w==0){
        return 0;
    }
    if(dp[i][w]!=-1){
        return dp[i][w];
    }
    if(wt[i]<=w){
        return dp[i][w]=max(val[i]+Helper(i-1,w-wt[i],wt,val,dp),Helper(i-1,w,wt,val,dp));
    }
    
    return dp[i][w]=Helper(i-1,w,wt,val,dp);
}

int main()
{
    int n,w;
    cin>>n>>w;
    vector<int>wt;
    vector<int>val;
    for(auto i=0;i<n;i++){
        int ins;
        cin>>ins;
        wt.push_back(ins);
    }
    for(auto i=0;i<n;i++){
        int ins;
        cin>>ins;
        val.push_back(ins);
    }
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    cout<<Helper(n-1,w,wt,val,dp)<<endl;
    
    return 0;
}
