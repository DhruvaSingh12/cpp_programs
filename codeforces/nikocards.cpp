#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n), b(n);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];

        long long d1=0, d2=0; 

        for(int i=0; i<n; i++){
            long long ai=a[i], bi=b[i];
            long long e1=max(d1-ai, bi+d2);
            long long e2=max(ai+d2, -bi+d1);

            d1=e1;
            d2=e2;
        }
        cout<<d1<<"\n";
    }
    return 0;
}