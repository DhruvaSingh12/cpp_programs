#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<array<int,3>> v(m);
    vector<int> t(n+1, 0), s(n+1, 0), P, N;
    
    for(int k=0; k<m; k++){
        cin>>v[k][0]>>v[k][1]>>v[k][2];
        if(v[k][1]==v[k][2]) t[v[k][1]]=v[k][0];
    }
    
    for(auto c:v){
        int o=c[0], i=c[1], j=c[2];
        if(i==j) continue;
        if(t[i]==1 && t[j]==2){
            o==1 ? s[i]++ : s[j]++;
        }
        if(t[i]==2 && t[j]==1){
            o==1 ? s[j]++ : s[i]++;
        }
    }
    
    for(int i=1;i<=n;i++){
        t[i]==1 ? P.push_back(i) : N.push_back(i);
    }
    
    auto vec=[&](int a, int b){
        return s[a]<s[b];
    };
    sort(P.begin(), P.end(), vec);
    sort(N.begin(), N.end(), vec);
    
    vector<long long> ans(n+1);
    for(int i=0; i<P.size(); i++){
        ans[P[i]]=i+1+s[P[i]];
    }
    for(int i=0; i<N.size(); i++){
        ans[N[i]]=-(i+1+s[N[i]]);
    }
    for(auto c:v){
        long long sum = ans[c[1]]+ans[c[2]];
        if((c[0]==1 && sum<0) || (c[0]==2 && sum>=0)){
            cout<<"NO"<<endl;
            return;
        }
    }
    
    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    if(cin>>t){
        while(t--){
            solve();
        }
    }
    return 0;
}