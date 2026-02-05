#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;

        vector<int> awake(n, 0); 
        for(int i=0; i<n; i++) {
            if(s[i]=='1'){
                int end=min(n-1, i+k);
                for(int j=i; j<=end; j++) {
                    awake[j]=1;
                }
            }
        }
        int c=0;
        for(int i=0; i<n; i++) {
            if(awake[i]) c++;
        }
        int sleep=n-c;
        cout<<sleep<<"\n";
    }
    return 0;
}
