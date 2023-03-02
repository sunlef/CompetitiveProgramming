#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    auto ok = [&]() { return (int)std::set<int>(a.begin(), a.end()).size() == 1; };
    std::vector<std::pair<int, int>> ans;

    while (!ok() && (int)ans.size() < 30 * n) {
        auto [f, g] = std::minmax_element(a.begin(), a.end());
        *g = (*g + *f - 1) / *f;
        ans.emplace_back(g - a.begin(), f - a.begin());
    }

    if (ok()) {
        std::cout << ans.size() << '\n';
        for (auto &[p, q] : ans) {
            std::cout << p + 1 << ' ' << q + 1 << '\n';
        }
    } else {
        std::cout << "-1\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
