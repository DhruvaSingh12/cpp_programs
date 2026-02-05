#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<sqrt(n); i++){
        if(n%(i+1)==0){
            v.push_back(i+1);
            if((i+1)!=(n/(i+1))){
                v.push_back(n/(i+1));
            }
        }
    }
    for(auto a:v){
        cout<<a<<endl;
    }
    return 0;
}