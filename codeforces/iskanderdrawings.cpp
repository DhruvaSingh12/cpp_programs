#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a(n, ' ');
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int idx=-1, c=0, maxc=0;
        for(int i=0; i<n; i++){
            if(a[i]=='#'){
                if(i==0){
                    c++;
                    maxc=c;
                }
                else if(a[i-1]=='#'){
                    c++;
                    maxc=max(maxc, c);
                }
                else{
                    c=1;
                    maxc=max(maxc, c);
                }
            }
        }
        if(maxc==1){
            cout<<1<<endl;
        }
        else if(maxc==0){
            cout<<0<<endl;
        }
        else if(maxc%2==0){
            cout<<maxc/2<<endl;
        }
        else if(maxc%2==1){
            cout<<maxc/2+1<<endl;
        }
    }
    return 0;

}