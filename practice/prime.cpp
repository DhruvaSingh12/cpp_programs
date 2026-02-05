#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> primes;
    for(int i=2; i<=n; i++){
        bool is_prime=true;
        for(int j=2; j<=sqrt(i); j++){
            if(i%j==0){
                is_prime=false;
                break;
            }
        }
        if(is_prime){
            primes.push_back(i);
        }
    }
    for(auto p:primes){
        cout<<p<<endl;
    }
    return 0;
}