#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        bool flag=true;

        if(n>1){
            a[1]+=a[0]-1;
            a[0]=1;
        }
        for(int i=1; i<n; i++){
            if(a[i]<=a[i-1]){
                cout<<"NO"<<endl;
                flag=false;
                break;
            }
            
            if(i!=n-1){
                a[i+1]+=a[i];
                a[i]=a[i-1]+1;
                a[i+1]-=a[i];
            }
        }
        if(flag) cout<<"YES"<<endl;
    }
    return 0;
}