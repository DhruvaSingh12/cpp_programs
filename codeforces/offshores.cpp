#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        
        vector<ll> a(n);
        ll total = 0;
        ll total_floor = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
            total_floor += a[i] / x;
        }
        
        if (x == y) {
            cout << total << '\n';
            continue;
        }
        
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll transfers_by_money = (total - a[i]) / x;
            ll transfers_by_capacity = total_floor - (a[i] / x);
            
            ll max_transfers = min(transfers_by_money, transfers_by_capacity);
            
            ll candidate = a[i] + y * max_transfers;
            ans = max(ans, candidate);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}