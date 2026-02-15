#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        const size_t n_size = static_cast<size_t>(n);

        vector<int> a(n_size);
        for(size_t i = 0; i < n_size; i++){
            cin >> a[i];
        }

        vector<vector<int>> dp(n_size, vector<int>(7, INT_MAX));

        for (size_t x = 1; x <= 6; x++) {
            dp[0][x] = (a[0] == static_cast<int>(x) ? 0 : 1);
        }

        for (size_t i = 1; i < n_size; i++) {
            for (size_t x = 1; x <= 6; x++) {
                int cost = (a[i] == static_cast<int>(x) ? 0 : 1);

                for (size_t y = 1; y <= 6; y++) {
                    if (x == y) continue;
                    if (x == 7 - y) continue;

                    dp[i][x] = min(dp[i][x], dp[i-1][y] + cost);
                }
            }
        }

        int answer = INT_MAX;
        for (size_t x = 1; x <= 6; x++) {
            answer = min(answer, dp[n_size-1][x]);
        }

        cout << answer << "\n";
    }

    return 0;
}