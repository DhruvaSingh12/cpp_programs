#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        vector<long long> c(k);
        for(int i=0; i<k; i++){
            cin>>c[i];
        }
        int d=0, e=0;
        for(int i=0; i<k; i++){
            if(c[i]>=3){
                e=1;
            }
            else if(c[i]>=2){
                d++;
            }
        }
        if(d>=2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}