#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, num;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        minHeap.push(num);
    }
    vector<int> sortedNums;
    while(!minHeap.empty()){
        sortedNums.push_back(minHeap.top());
        minHeap.pop();
    }
    for(int i = 0; i < sortedNums.size(); i++){
        cout << sortedNums[i] << " ";
    }
    return 0;
}