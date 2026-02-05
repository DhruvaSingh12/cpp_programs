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

    function<void(int, int)> mergeSort = [&](int left, int right){ 
        if(left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        vector<int> merged;
        int i = left, j = mid + 1;
        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                merged.push_back(nums[i++]);
            } else {
                merged.push_back(nums[j++]);
            }
        }
        while(i <= mid) merged.push_back(nums[i++]);
        while(j <= right) merged.push_back(nums[j++]);

        for(int k = left; k <= right; k++){
            nums[k] = merged[k - left];
        }
    };

    mergeSort(0, nums.size() - 1);

    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}

// recurrance relation: T(n) = 2T(n/2) + O(n)
// time complexity: O(n log n)
// space complexity: O(n)
// stable sort and cannot be optimized