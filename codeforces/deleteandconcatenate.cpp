#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    long long c, sum=0;
    cin>>n>>c;
    
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(), a.end());
    
    long long ans=sum-(long long)n*c;

    for(int i=0; i<n/2; i++){
        if(a[i]<c){
            ans+=(c-a[i]);
        } 
        else break;
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}