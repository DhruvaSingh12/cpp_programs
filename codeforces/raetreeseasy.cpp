#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        vector<int> p(n+1), pos(n+1);
        for(int i = 1; i <= n; ++i) {
            cin >> p[i];
            pos[p[i]] = i;
        }

        vector<int> prefMin(n+1, INT_MAX);
        prefMin[1] = pos[1];
        for (int i = 2; i <= n; ++i) prefMin[i] = min(prefMin[i-1], pos[i]);

        vector<int> sufMax(n+2, INT_MIN);
        sufMax[n] = pos[n];
        for (int i = n-1; i >= 1; --i) sufMax[i] = max(sufMax[i+1], pos[i+1]);

        bool ok = true;
        for (int k = 1; k < n; ++k) {
            if (prefMin[k] > sufMax[k]) {
                ok = false;
                break;
            }
        }

        std::cout<<(ok ? "Yes" : "No") << '\n';
    }

    return 0;
}
