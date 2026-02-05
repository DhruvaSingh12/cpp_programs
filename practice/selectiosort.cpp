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
    for(int i=0; i<n; i++){ // n
        int smallest = i;
        int flag=0;
        for(int j=i+1; j<n; j++){ // j comparisons
            if(nums[j]<nums[smallest]){
                smallest=j;
                flag=1;
            }
            if(flag==0){
                break;
            }
        }
        swap(nums[i], nums[smallest]);
    }

    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}

//stable sorting algorithm
//time complexity: O(n^2) in average/worst case and O(n) in best case


//merge sort and recurrecence relation