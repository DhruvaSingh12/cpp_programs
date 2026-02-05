#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;
 int main(){
    int t, n, sum=0;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }

        vector<int> diff(n-1);
        for(int i=0; i<n-1; i++){
            if(v[i]!=-1 && v[i+1]!=-1){
                diff[i]=v[i+1]-v[i];
            }
            else {
                diff[i]=INT_MAX;
            }
        }

        long minAbs;
        if(v[0]!=-1 && v[n-1]!=-1) {
            minAbs = abs((long)v[n - 1] - (long)v[0]);
        } 
        else {
            minAbs = 0;
        }

        vector<int> res=v;

        if(res[0]==-1 && res[n-1]==-1){
            res[0]=0;
            res[n-1]=0;
        }
        else if(res[0]==-1 && res[n-1]!=-1) {
            res[0]=res[n-1];
        }
        else if(res[0]!=-1 && res[n-1]==-1) {
            res[n-1]=res[0];
        }

        for(int i=1; i<n-1; i++){
            if(res[i]==-1){
                res[i]=0;
            }
        }

        cout<<minAbs<<endl;;
        for(int i=0; i<n; i++) {
            cout<<res[i]<<" ";
        }
        cout <<endl;
    }
    return 0;
}