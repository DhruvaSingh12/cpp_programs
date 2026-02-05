#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    if (cin >> t) {
        while(t--){
            int n_in;
            cin >> n_in;
            if (n_in < 0) n_in = 0;
            size_t n = static_cast<size_t>(n_in);
            vector<int> a(n);
            for(int &x : a) cin >> x;

            if(n<=2){
                cout << 0 << "\n";
                continue;
            }

            long long full = 0;
            for(size_t i=0; i+1<n; i++) {
                full += abs(a[i+1] - a[i]);
            }

            long long bestDelta = 0;         

            for(size_t k=1; k+1<n; k++){
                long long old_val = (long long)abs(a[k] - a[k-1]) + abs(a[k+1] - a[k]);
                long long neo_val = (long long)abs(a[k+1] - a[k-1]);
                bestDelta = min(bestDelta, neo_val - old_val);
            }
            bestDelta = min(bestDelta, (long long)-abs(a[1] - a[0]));
            bestDelta = min(bestDelta, (long long)-abs(a[n-1] - a[n-2]));

            cout << full + bestDelta << '\n';
        }
    }
    return 0;
}