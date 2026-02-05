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
    function<void(int, int)> quickSort = [&](int left, int right){ 
        if(left >= right) return;
        int pivot = nums[right];
        int i = left - 1;
        for(int j = left; j < right; j++){
            if(nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[right]);
        int partitionIndex = i + 1;

        quickSort(left, partitionIndex - 1);
        quickSort(partitionIndex + 1, right);
    };
    quickSort(0, nums.size() - 1);

    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}

// recurrance relation: T(n) = T(k) + T(n-k-1) + O(n)
// time complexity: O(n log n) on average, O(n^2) in worst case
// space complexity: O(log n) due to recursion stack
// in-place sort but not stable
// lamuto partition