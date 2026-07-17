#include <iostream>
using namespace std;

void solve(){
    int n;
    long long k;
    cin>>n>>k;

    if(n==1){
        if(k==1) cout<<"YES"<<endl<<0<<endl;
        else cout<<"NO"<<endl;
        return;
    }
   
    int L= 32-__builtin_clz(n-1);
        long long X=k^n;

    if(X > (1LL<<L)-1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;

    if(X==0){
        for(int i=1; i<=n-1; i++){
            cout<<i<<" ";
        }
        cout<<0<<endl;
    } 
    else if(X<=n-1){
        for(int i=1; i<=n-1; i++){
            if(i!=X) cout<<i<<" ";
        }
        cout<<0<<" "<<X<<endl; 
    }
    else{
        long long Y=X^(n-1);
        for(int i=1; i<=n-2; i++){
            if(i!=Y) cout<<i<<" ";
        }
        cout<<0<<" "<<Y<<" "<<(n-1)<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}