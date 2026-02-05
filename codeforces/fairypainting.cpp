#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> colors(n);
        for(int i=0; i<n; i++) cin>>colors[i];

        map<int, int> freq;
        for(int c:colors) freq[c]++;

        while (true){
            int d=freq.size();
            if(freq.count(d)){
                cout<<d<<"\n";
                break;
            } 
            else {
                freq[d]++;
            }
        }
    }
}