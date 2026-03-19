#include <bits/stdc++.h>
using namespace std;
int c=0;
int solve(int n){
    c++;
    if(n<=1) return n;
    return solve(n-1)+solve(n-2);
}
int main(){ // O(2^n)
    int n;
    vector<int> a;
    cin>>n;
    cout<<solve(n)<<endl;
    cout<<c;

    return 0;
}

// minimum sum path value
// dp time complexity = total no. of states * time complexity of work done in each state