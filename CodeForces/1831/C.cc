#include <bits/stdc++.h>
using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    int ans = 0;
    for (auto [v, idx] : adj[0]) {
        auto dp = [&] (auto dp, int u, int f) -> int {
            int res = 0;
            for (auto [v, p] : adj[u]) {
                if (p == f) {
                    continue;
                }
                if (p <= f) {
                    res = std::max(res, 1 + dp(dp, v, p));
                } else {
                    res = std::max(res, dp(dp, v, p));
                }
            }
            return res;
        };

        ans = std::max(ans, dp(dp, v, idx));
    }

    std::cout << ans + 1 << '\n';
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
