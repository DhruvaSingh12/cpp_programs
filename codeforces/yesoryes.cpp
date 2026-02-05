#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int y_count = 0;
    for (char c : s) {
        if (c == 'Y') y_count++;
    }

    if (y_count <= 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}