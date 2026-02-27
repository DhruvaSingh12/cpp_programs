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
    int hp = 0, ht = 0;

    for(int i=0; i<p; i++){
        hp = hp*10 + pattern[i] - 'a'+1;
        ht = ht*10 + test[i] - 'a'+1;
    }

    for(int i=0; i<t-p+1; i++){
        if(hp == ht){
            result.push_back(i);
        }
        if(i<t-p){
            ht = ht*10 - (test[i]-'a'+1)*pow(10, p-1) + (test[i+p]-'a'+1);
        }
    }
    
    for(int idx:result){
        cout << "Pattern found at index: " << idx << endl;
    }
    return 0;
}


