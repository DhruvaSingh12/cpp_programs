#include<iostream>
using namespace std;
int legs(int n){
    if(n%2!=0) return 0;
    else return n/4+1;
}
int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans;
        ans=legs(n);
        cout<<ans<<endl;
    }
    return 0;
}