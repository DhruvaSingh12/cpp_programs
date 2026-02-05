#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    long long k;
    cin>>n>>k;

    vector<long long> a(n), b(n), pre(n), suf(n);
    long long ans=-2e18;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }

    if(k%2==0) {
        for(int i=0; i<n; i++){
            b[i]=0;
        }
    }

    pre[0]=a[0];

    for(int i=1; i<n; i++){
        pre[i] = max(a[i], a[i]+pre[i-1]);
    }

    suf[n-1]=a[n-1];
    
    for(int i=n-2; i>=0; i--){
        suf[i] = max(a[i], a[i]+suf[i+1]);
    }


    for(int i=0; i<n; i++){
        long long current = pre[i]+suf[i]-a[i]+b[i];
        ans = max(ans, current);
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}