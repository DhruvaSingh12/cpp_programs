#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        vector<int> left(n+1, 0), mid(n+1, 0), best(n+1, INT_MIN);
        for(int i=0; i<n; i++){
            left[i+1] = left[i] + (a[i]==1 ? 1:-1);
            mid[i+1] = mid[i] + (a[i]==3 ? -1:1);
        }
        best[n-1] = mid[n-1];
        for(int i=n-2; i>=0; i--){
            best[i] = max(best[i+1], mid[i]);
        }

        bool flag = false;
        for(int i=0; i<=n-3; i++){
            if(left[i+1]<0) continue;
            if(best[i+2]-mid[i+1]>=0){
                flag = true;
                break;
            }
        }

        if(flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}