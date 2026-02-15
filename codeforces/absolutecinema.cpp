#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> f(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
        }

        vector<long long> a(n + 1, 0);

        if (n == 1) {
            a[1] = 0;
        } 
        else {
            for (int i = 2; i + 1 <= n; i++) {
                a[i] = (f[i + 1] - 2 * f[i] + f[i - 1]) / 2;
            }

            long long mid_sum = 0;
            long long weighted_mid = 0;
            for (int i = 2; i + 1 <= n; i++) {
                mid_sum += a[i];
                weighted_mid += static_cast<long long>(i - 1) * a[i];
            }

            a[n] = (f[1] - weighted_mid) / static_cast<long long>(n - 1);

            long long total = (f[n] - f[n - 1]) + 2 * a[n];
            a[1] = total - mid_sum - a[n];
        }

        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}