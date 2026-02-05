#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        string r;
        cin >> r;

        for (char c : r) {
            assert(c == 's' || c == 'u');
        }

        size_t n = r.size();
        vector<size_t> pos;

        for (size_t i = 0; i < n; i++) {
            if (r[i] == 's') {
                pos.push_back(i);
            }
        }

        if (pos.empty()) {
            size_t m = (n - 1) / 2;
            cout << n - m << "\n";
            continue;
        }

        size_t ans = 0;

        size_t pu = pos.front();
        ans += (pu + 1) / 2;

        size_t su = (n - 1) - pos.back();
        ans += (su + 1) / 2;

        for (size_t i = 0; i + 1 < pos.size(); i++) {
            size_t gap = pos[i + 1] - pos[i] - 1;
            if (gap > 0) {
                ans += gap / 2;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}