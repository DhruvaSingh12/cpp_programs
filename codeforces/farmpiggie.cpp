#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==2){
            cout<<"2 1"<<endl;
            continue;
        }
        for(int i=2; i<=n; i++){
            cout<<i<<" ";
        }
        cout<<1<<endl;
    }
    return 0;
}