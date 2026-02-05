#include <iostream>
#include <vector>
using namespace std;

int bob(const vector<int>& marbles, int n, int a) {
    int l=0;
    int g=0;
    for(int i=0; i<n; i++){
        if (marbles[i]<a){
            l++;
        } 
        else if(marbles[i]>a) {
            g++;
        }
    }
    if(g>=l) return a+1;
    else return a-1;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n, a;
        cin>>n>>a;
        vector<int> marbles(n);
        for(int i=0; i<n; i++){
            cin>>marbles[i];
        }
        int b=bob(marbles, n, a);
        cout<<b<<endl;
    }
    return 0;
}