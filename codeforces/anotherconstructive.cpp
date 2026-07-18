#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        long long n, k, m;
        cin>>n>>k>>m;
        if(k>m){
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
        for(long long i=1; i<=n; i++){
            if(i%k==0) cout<<m-k+1;
            else cout<<1;
            cout<<(i==n ? '\n' : ' ');
        }
    }
    return 0;
}