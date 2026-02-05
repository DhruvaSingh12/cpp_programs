#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, num;
    vector<int> nums;
    while(n){
        cin>>num;
        nums.push_back(num);
        n--;
    }
    int m=nums[0];
    for(int i=0; i<nums.size()-1; i++){
        int n=nums[i+1];
        while(m!=0){  
            int temp = m;
            m = n % m;
            n = temp;
        }
    }
    return 0;
}

// MOD = 10e9+7
// (a+b)%m = ((a%m) + (b%m))%m
// (a*b)%m = ((a%m) * (b%m))%m
// (a-b)%m = ((a%m) - (b%m) + m)%m
// (a/b)%m = ((a%m) * modInverse(b, m))%m

//josephus problem + sorting
