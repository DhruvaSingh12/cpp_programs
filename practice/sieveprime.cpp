#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<=sqrt(n); i++){  
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){  //log(log(n))
                is_prime[j] = false;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(is_prime[i]){
            cout<<i<<endl;
        }
    }
    return 0;
}