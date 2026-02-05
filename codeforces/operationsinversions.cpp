#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int ans=0, curMax = a[0];                 
        for(int i=1; i<n; i++){
            if(a[i]<curMax) ans++;     
            curMax = max(curMax, a[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}