#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;

    if(2*k>n){
        cout<<-1<<endl;
        return;
    }

    int flips=0;

    for(int i=0; i<k; i++){
        if(s[i]=='L'){
            flips++;
        }
    }

    for(int i=n-k; i<n; i++){
        if(s[i]=='R'){
            flips++;
        }
    }
    cout<<flips<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}