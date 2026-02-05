#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<int> v;
    for(int i=2; i<n; i++){ //n
        while(n%i==0){ //log(n)
            n=n/i;
            v.insert(i);
        }
    }
    for(auto a:v) cout<<a<<endl;
    return 0;
}