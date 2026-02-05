#include <bits/stdc++.h>
using namespace std;
int main(){
    string pattern, text;
    cin>>pattern>>text;
    int p = (int)pattern.size(), t = (int)text.size();
    vector<int> result;

    for(int i=0; i<=t-p; i++){ // O((t-p+1)*p)
        int j;
        for(j=0; j<p; j++){
            if(text[(size_t)(i+j)] != pattern[(size_t)j]){
                break;
            }
        }
        if(j==p){
            result.push_back(i);
        }
    }

    for(int index : result){
        cout << "Pattern found at index: " << index << endl;
    }
    return 0;
}