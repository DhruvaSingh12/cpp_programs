#include<bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;

long long solve(long long base, long long exp){
    long long res=1;
    base%=MOD; 
    while(exp>0){
        if(exp%2==1) res=(res*base)%MOD;
        base=(base*base)%MOD; 
        exp/=2; 
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        long long c=0;
        vector<pair<long long, long long>> freq;
        for(int i=0; i<n; i++){
            long long x;
            cin>>x;
            if(x==-1) c++;
            else{
                if(freq.empty() || freq.back().first!=x){
                    freq.push_back({x, 1});
                }
                else freq.back().second++;
            }
        }

        long long ways=1, k=0;
        for(auto pair:freq){
            ways = (ways*solve(2, pair.second-1))%MOD;
        }

        for(long long i=1; i<freq.size(); i++){
            if(freq[i].first == freq[i-1].first+1){
                k=(k+1)%MOD;
            }
        }

        long long even = (c==0) ? 1:solve(2, c-1), odd = (c==0) ? 0:solve(2, c-1);
        long long ans = (even+(odd*k) % MOD) % MOD;
        ans = (ans*ways)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}