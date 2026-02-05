#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        vector<int> pos;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                pos.push_back(i);
            }
        }
        
        if(pos.size()==n){
            cout<<0<<'\n';
            continue;
        }

        int ans=0;
        int k=pos.size();
        
        for(int i=0; i<k-1; i++){
            ans = max(ans, pos[i+1]-pos[i]-1);
        }
        
        ans = max(ans, n-pos.back() + pos.front()-1);
        
        cout<<ans<<'\n';
    }
    return 0;
}