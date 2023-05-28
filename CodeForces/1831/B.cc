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

    std::vector<int> a_max(2 * n + 1), b_max(2 * n + 1);
    std::vector<int> cnt(2 * n + 1);

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (i == 0 || a[i - 1] != x) {
            cnt[x] = 0;
        }
        cnt[x] += 1;
        a_max[x] = std::max(a_max[x], cnt[x]);
    }

    for (int i = 0; i < n; ++i) {
        int x = b[i];
        if (i == 0 || b[i - 1] != x) {
            cnt[x] = 0;
        }
        cnt[x] += 1;
        b_max[x] = std::max(b_max[x], cnt[x]);
    }

    int ans = 1;
    for (int i = 1; i <= 2 * n; ++i) {
        ans = std::max(ans, a_max[i] + b_max[i]);
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
