#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> c(n);
    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for(int i=0; i<n; i++){
        dp[i][i] = 1;
    }

    for(int i=2; i<=n; i++){
        for(int j=0; j<n-i+1; j++){
            int k = j+i-1;
            dp[j][k] = 1+dp[j+1][k];

            for(int l=j; l<k; l++){
                dp[j][k] = min(dp[j][k], dp[j][l] + dp[l+1][k]);
            }

            if(c[j]==c[k]){
                if(i==2) dp[j][k]=1;
                else dp[j][k] = min(dp[j][k], dp[j+1][k-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}