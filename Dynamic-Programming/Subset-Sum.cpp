#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>a;
    for(auto i=0;i<n;i++){
        int ins;
        cin>>ins;
        a.push_back(ins);
    }
    int t;
    cin>>t;
    vector<vector<bool>>dp(n+1,vector<bool>(t+1,false));
    for(auto i=0;i<n+1;i++){
        for(auto j=0;j<t+1;j++){
            if(j==0){
                dp[i][j]=true;
            }
        }
    }
    for(auto i=1;i<n+1;i++){
        for(auto j=1;j<t+1;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j]||dp[i][j-a[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

   cout<<dp[n][t]<<endl;
    return 0;
}
