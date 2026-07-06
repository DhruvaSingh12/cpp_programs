#include<bits/stdc++.h>
using namespace std;

void solve(){
    string a, b;
    cin>>a>>b;

    int n=a.size(), m=b.size(), sum=0;
    vector<int> pa(n), pb(m);
    for(int i=0; i<n; i++){
        sum = (sum+(a[i]-'0'))%10;
        pa[i] = sum;
    }
    sum=0;
    for(int i=0; i<m; i++){
        sum = (sum+(b[i]-'0'))%10;
        pb[i] = sum;
    }

    if(pa[n-1]!=pb[m-1]){
        cout<<-1<<endl;
        return;
    }

    vector<int> lcs(m+1, 0);
    for(int i=0; i<n; i++){
        int prev=0;
        for(int j=0; j<m; j++){
            int temp = lcs[j+1];
            if(pa[i]==pb[j]){
                lcs[j+1] = prev+1;
            }
            else{
                lcs[j+1] = max(lcs[j], lcs[j+1]);
            }
            prev = temp;
        }
    }
    cout<<lcs[m]<<endl;
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