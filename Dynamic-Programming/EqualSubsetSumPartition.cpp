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
   int s;
   for(auto i=0;i<n;i++){
       s+=a[i];
   }
   if(s%2!=0){
       cout<<false<<endl;
   }
   else{
   vector<vector<bool>>dp(n+1,vector<bool>((s/2)+1,false));
   for(auto i=0;i<=n;i++){
       for(auto j=0;j<=s/2;j++){
           if(j==0){
               dp[i][j]=true;
           }
       }
   }
   for(auto i=1;i<=n;i++){
       for(auto j=1;j<=s/2;j++){
           if(a[i-1]<=j){
               dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
           }
           else{
               dp[i][j]=dp[i-1][j];
           }
       }
   }
   cout<<dp[n][s/2]<<endl;
   }

    return 0;
}
