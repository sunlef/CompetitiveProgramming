#include <bits/stdc++.h>
using i64 = int64_t;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    std::vector<int> p(n), ans(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&] (int i, int j) -> bool {
        return a[i] < a[j];
    });

    std::sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        ans[p[i]] = b[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
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
