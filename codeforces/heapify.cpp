#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--){
        int n;
        cin >> n;

        const size_t n_size = static_cast<size_t>(n);

        vector<int> a(n_size + 1);
        for(size_t i = 1; i <= n_size; i++){
            cin >> a[i];
        }

        vector<bool> seen(n_size + 1, false);
        bool ans = true;

        for(size_t i = 1; i <= n_size; i++){
            if(seen[i]) continue;

            vector<size_t> idx;
            size_t x=i;

            while(x<=n_size && !seen[x]){
                seen[x] = true;
                idx.push_back(x);
                x *= 2;
            }

            vector<int> values;
            values.reserve(idx.size());
            for(size_t pos : idx){
                values.push_back(a[pos]);
            }

            sort(idx.begin(), idx.end());
            sort(values.begin(), values.end());

            for(size_t j = 0; j < idx.size(); j++){
                if (values[j] != static_cast<int>(idx[j])) {
                    ans = false;
                    break;
                }
            }
            if (!ans) break;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}