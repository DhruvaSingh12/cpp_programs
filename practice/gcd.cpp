#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    if(abs(n-m)==1) {
        cout<<"1"<<endl;
        return 0;
    }
    if(n==m){
        cout<<n<<endl;
        return 0;
    }
    if(n==0 && m!=0){
        cout<<m<<endl;
        return 0;
    }
    if(m==0 && n!=0){
        cout<<n<<endl;
        return 0;
    }
    int temp=1;
    for(int i=1; i<=min(n, m); i++){ //(min(a,b))
        if(n%i==0 && m%i==0){
           if(i>temp) temp = i;
        }
    }
    cout<<temp<<endl;
    return 0;
}