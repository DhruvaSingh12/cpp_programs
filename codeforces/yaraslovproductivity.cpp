#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    long long NEG=-4e18;
    cin>>T;
    while(T--){
        int n, m;
        cin>>n>>m;

        vector<long long> a(n+1);
        vector<int> impact(n + 1, 0);
        for(int i=1; i<=n; i++) cin>>a[i];

        for(int i=0; i<m; i++){
            int x;
            cin>>x;
            impact[x]=1;
        }

        long long next[2]={0, NEG};

        for(int i=n; i>=1; i--){
            long long curr[2];
            for(int p=0; p<2; p++){
                long long c=(p==0 ? a[i]:-a[i]);
                if(impact[i]) curr[p] = c+max(next[p], next[p^1]);
                else curr[p] = c+next[p];
            }
            next[0]=curr[0];
            next[1]=curr[1];
        }
        cout<<max(next[0], next[1])<<endl;
    }
    return 0;
}