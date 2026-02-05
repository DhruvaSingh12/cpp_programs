#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>> t;
    while(t--){
        int n, y, r;
        cin>>n;
        cin>>y>>r;
        int suspended = min(n, r+y/2);
        cout<<suspended<<'\n';
    }
    return 0;
}
