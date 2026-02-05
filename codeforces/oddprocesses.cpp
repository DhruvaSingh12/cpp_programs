#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0; i<n; i++) cin>>a[i];

        vector<long long> odd, even;
        for(long long x:a){
            if(x & 1LL) odd.push_back(x);
            else even.push_back(x);
        }

        if(odd.empty()){
            for(int i=0; i<n; i++) cout<<0<<' ';
            cout<<'\n';
            continue;
        }

        sort(even.rbegin(), even.rend());          
        int p = (int)even.size();
        vector<long long> pref(p+1, 0);             
        for(int i=1; i<=p; i++){
            pref[i] = pref[i-1] + even[i-1];
        }
            
        long long maxOdd = *max_element(odd.begin(), odd.end());
        int m = (int)odd.size();

        for(int k=1; k<=n; k++){
            int need=k-p-1;                  
            int cmin = (need>0) ? (need+1)/2 : 0;
            int cmax = min((k-1)/2, (m-1)/2);

            long long ans=0;
            if(cmin<=cmax){
                int r= k - 2*cmin - 1;        
                ans = maxOdd + pref[r];
            }
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
    return 0;
}