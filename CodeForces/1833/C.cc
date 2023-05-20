#include <bits/stdc++.h>
using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        a[i] %= 2;
    }

    bool odd = a[0] == 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[0] && !odd) {
            std::cout << "NO\n";
            return;
        }
        odd |= a[i] == 1;
    }

    std::cout << "YES\n";
}

int main() {
#ifdef ONLINE_JUDGE
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
