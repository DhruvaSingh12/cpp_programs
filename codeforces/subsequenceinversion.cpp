#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;

    while(T--){
        int n;
        cin>>n;
        vector<int> a(n), b(n);
        int ones=0, parityA=0;

        for(int i=0; i<n; i++){
            cin>>a[i];
            ones+=a[i];
            parityA^=a[i];
        }

        int c=0;
        bool flag=true;
        vector<int> diff(n);

        for(int i=0; i<n; i++){
            cin>>b[i];
            diff[i] = a[i]^b[i];
            if(diff[i]) flag = false;
            if(a[i]==1 && b[i]==0) c++;
        }

        if(flag) cout<<0<<endl;
        else if(ones == 0) cout<<-1<<endl;
        else if(c % 2 == 1) cout<<1<<endl;
        else{
            bool zero=true, equalA=true;
            for(int i=0; i<n; i++){
                int x = diff[i] ^ 1;
                if(x) zero=false;
                if(x != a[i]) equalA=false;
            }
            if(zero){
                if(parityA==0) cout<<2<<endl;
                else cout<<-1<<endl;
            }
            else if(equalA) cout<<-1<<endl;
            else cout<<2<<endl;
        }
    }
    return 0;
}