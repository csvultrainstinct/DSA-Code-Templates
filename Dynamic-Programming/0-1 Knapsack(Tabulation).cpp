#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,w;
    cin>>n>>w;
    vector<int>wt;
    for(auto i=0;i<n;i++){
        int ins;
        cin>>ins;
        wt.push_back(ins);
    }
    vector<int>val;
    for(auto i=0;i<n;i++){
        int ins;
        cin>>ins;
        val.push_back(ins);
    }
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    for(auto i=0;i<n+1;i++){
        for(auto j=0;j<w+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(auto i=1;i<n+1;i++){
        for(auto j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
   cout<<dp[n][w]<<endl;
    return 0;
}
