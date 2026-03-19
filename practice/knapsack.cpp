#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> sacks = {{10, 2}, {5, 3}, {15, 5}, {7, 7}, {6, 1}, {18, 4}, {3, 1}};
    double n=sacks.size();
    double cap = 15;
    vector<pair<double,int>> ratio;
    for(int i=0; i<sacks.size(); i++){
        ratio.push_back({(double)sacks[i][0]/sacks[i][1], i});
    }
    sort(ratio.begin(), ratio.end(), [](const auto& a, const auto& b){
        return a.first > b.first;
    });
    double ans=0;    
    for(int i=0; i<n; i++){
        if(cap>=sacks[ratio[i].second][1]){
            ans+=sacks[ratio[i].second][0];
            cap-=sacks[ratio[i].second][1];
        }
        else{
            ans += ratio[i].first * cap;
            break;
        }
    }
    cout<<ans;
    return 0;
}

// meeting room 1
// ativity selection problem
// container with most water
// top k frequent elements