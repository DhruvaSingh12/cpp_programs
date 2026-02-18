#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string test;
    cin>>test;
    int t = (int)test.size();
    vector<int> z(t, 0);
    int l=0, r=0;
    for(int i=1; i<t; i++){
        if(i>r){
            l=i; r=i;
            while(r<t && test[r-l]==test[r]){
                r++;
            }
            r--;
            z[i]=r-l+1;
        }
        else if(i<=r){
            int k=i-l;
            if(z[k]<=r-i+1){
                z[i]=z[k];
            }
            else {
                l=i;
                while(r<t && test[r-l]==test[r]){
                    r++;
                }
                r--;
                z[i]=r-l+1;
            }
        }
    }
    for(auto a:z){
            cout<<a<<" ";
        }
    return 0;  
}

// 3031, longest happy prefix, gfg-> search pattern
// cp algorithm
// z array: longest substring at any index k which is also a prefix
// O(n) time complexity