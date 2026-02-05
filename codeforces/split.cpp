#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, odd=0, even=0, ans;
        cin>>n;
        int len=2*n;

        vector<int> a(len);
        for(int i=0; i<len; i++){
            cin>>a[i];
        } 

        vector<int> freq(2*n+1, 0);
        for(int x:a){
            freq[x]++;
        } 

        for (int f:freq){
            if(f==0) continue;
            if(f%2==0) even++;
            else odd++;
        }

        if(odd>0){
            int cap = n-(odd+1)/2;  
            if(cap<0) cap=0;
            int useEven = min(even, cap);
            ans = odd+2*useEven;
        } 
        else{
            if(even>=n){
                ans=2*n;
            } 
            else{
                if((even%2)==(n%2)){
                    ans=2*even;
                } 
                else{
                    ans=2*(even-1);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
