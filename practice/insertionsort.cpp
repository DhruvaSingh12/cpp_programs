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
    for(int i=1; i<n; i++){  // n
        int key = nums[i];
        int j=i-1; 
        while (j>=0 && nums[j] > key) { // j comparisons
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1]=key;
    }
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}

// stable and adaptive sorting algorithm
// time complexity: O(n^2) in worst/average case, O(n) in best case
// best for linked lists