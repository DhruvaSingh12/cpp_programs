#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while(t--){
        int n, A=0, B=0; 
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];

        for(int i=0; i<n; i++){
            A^= a[i];
            B^= b[i];
        }

        int odd=0, even=0; 
        for(int i=0; i<n; i++){
            if(a[i]!=b[i]){
                if((i+1)%2==1){
                    odd++;
                } 
                else{
                    even++;
                }
            }
        }

        string ans;
        if(A==B){
            ans="Tie";
        } 
        else{
            if(odd>0 && even>0){
                ans="Tie";
            } 
            else if(odd>0){
                ans="Ajisai";
            } 
            else if(even>0){
                ans="Mai";
            } 
            else{
                ans=(A==1 ? "Ajisai" : "Mai");
            }
        }
        cout<<ans;
    }
    return 0;
}