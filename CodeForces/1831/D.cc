#include <bits/stdc++.h>
using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    } 
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    std::vector<std::vector<int>> f(n + 1);
    for (int i = 0; i < n; ++i) {
        f[a[i]].push_back(b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        std::sort(f[i].begin(), f[i].end());
    }

    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            i64 k = 1LL * i * j;
            if (k > 2 * n) {
                break;
            }
            if (f[i].size() == 0 || f[j].size() == 0) {
                continue;
            }
            for (auto x : f[i]) {
                int y = k - x;
                auto p = std::upper_bound(f[j].begin(), f[j].end(), y);
                auto q = std::lower_bound(f[j].begin(), f[j].end(), y);
                ans += p - q;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        i64 k = 1LL * i * i;
        if (k > 2 * n) {
            break;
        }
        int m = f[i].size();
        if (m < 2) {
            continue;
        }
        for (int j = 0; j < m; ++j) {
            int x = f[i][j];
            int y = k - x;
            auto p = std::upper_bound(f[i].begin() + j + 1, f[i].end(), y);
            auto q = std::lower_bound(f[i].begin() + j + 1, f[i].end(), y);
            ans += p - q; 
        }
    }

    std::cout << ans << '\n';
}

int main() {
#ifndef LOCAL
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
