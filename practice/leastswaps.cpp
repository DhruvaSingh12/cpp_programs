#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> swap;
    int n, c=0;
    while(cin>>n){
        swap.push_back(n);
    }
    if(swap.size()==0) return 0;
    for(int i=1; i<swap.size(); i++){
        int j=i;
        int temp = swap[i];
        while(j>0 && swap[j]>swap[j-1]){
            swap[j-1] = swap[j];
            j--;
            c++;
        }
        swap[j] = temp;
    }
    cout<<"Least swaps = "<<c<<endl;
    for(auto i:swap){
        cout<<i<<" ";
    }
    return 0;
}

