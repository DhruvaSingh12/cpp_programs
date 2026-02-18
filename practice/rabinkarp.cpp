#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    string pattern, test;
    cin>>pattern>>test;
    int p = (int)pattern.size(), t = (int)test.size();
    vector<int> result;
    int hash_pattern = 0, hash_test = 0;

    for(int i=0; i<p; i++){
        hash_pattern = hash_pattern*10 + (pattern[i] - 'a'-96);
        hash_test = hash_test*10 + test[i] - 'a'-96;
    }

    for(int i=0; i<t-p+1; i++){
        if(hash_pattern == hash_test){
            result.push_back(i);
        }
        hash_test = hash_test*10 - (test[i]-'a'-96)*pow(10, p) + (test[i+p]-'a'-96);
    }
    
    for(int idx:result){
        cout << "Pattern found at index: " << idx << endl;
    }
    return 0;
}


