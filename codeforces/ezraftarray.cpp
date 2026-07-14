#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        if(n==2){
            cout<<-1<<endl;
            continue;
        }

        if(n==1){
            cout<<1<<endl;
            continue;
        }

        vector<long long> a={1, 2, 3};
        long long sum=6;

        for(int i=4; i<=n; i++){
            a.push_back(sum);
            sum*=2;
        }

        for(int i=0; i<n; i++){
            cout<<a[i]<<(i==n-1 ? "" : " ");
        }
        cout<<endl;
    }
    return 0;
}