#include <bits/stdc++.h>
using namespace std;
int main(){
    string pattern;
    cin>>pattern;
    int p = (int)pattern.size();
    vector<int> lps(p, 0);
    int len = 0, i = 1;
    while(i < p){
        if(pattern[i] == pattern[len]){   // KMP String matching O(n+m)
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[(len - 1)];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    for(int j = 0; j < p; j++){
        cout << lps[j] << " ";
    }
    cout << endl;
    return 0;
}
