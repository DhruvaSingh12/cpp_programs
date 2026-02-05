#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, l, r;
        cin>>n>>l>>r;
        vector<long long> px(n+1, -1);

        px[0]=0;
        px[l-1]=1;
        px[r]=1;
        long long val=2;

        for(int i=1; i<=n; i++){
            if(px[i]!=-1) continue; 
            if(val==px[i-1]) val++;
            if(val==0 || val==1) val++;
            px[i]=val;
            val++;
        }

        vector<long long> a(n+1);
        for(int i=1; i<=n; i++){
            a[i]=px[i]^px[i-1]; 
        }

        for(int i=1; i<=n; i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}