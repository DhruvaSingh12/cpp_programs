#include <bits/stdc++.h>
using namespace std;
int main(){
    string pattern;
    cin>>pattern;
    int p = (int)pattern.size();
    vector<int> lps((size_t)p, 0);
    int len = 0, i = 1;
    while(i < p){
        if(pattern[(size_t)i] == pattern[(size_t)len]){   // KMP String matching O(n+m)
            len++;
            lps[(size_t)i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[(size_t)(len - 1)];
            }
            else{
                lps[(size_t)i] = 0;
                i++;
            }
        }
    }
    for(int j = 0; j < p; j++){
        cout << lps[(size_t)j] << " ";
    }
    cout << endl;
    return 0;
}
