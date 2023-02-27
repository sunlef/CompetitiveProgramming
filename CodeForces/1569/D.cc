#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> x(n), y(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> y[i];
    }

    std::vector<std::map<int, i64>> cntx(n), cnty(m);
    for (int i = 0; i < k; ++i) {
        int X, Y;
        std::cin >> X >> Y;

        auto p = std::lower_bound(x.begin(), x.end(), X);
        auto q = std::lower_bound(y.begin(), y.end(), Y);

        int f = p - x.begin();
        int g = q - y.begin();

        if (*p == X && *q == Y) continue;
        if (*p == X) ++cnty[g][X];
        if (*q == Y) ++cntx[f][Y];
    }

    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        i64 p = 0, q = 0;
        for (auto [_, cnt] : cntx[i]) {
            p += cnt;
            q += cnt * cnt;
        }
        ans += (p * p - q) / 2;
    }
    for (int i = 0; i < m; ++i) {
        i64 p = 0, q = 0;
        for (auto [_, cnt] : cnty[i]) {
            p += cnt;
            q += cnt * cnt;
        }
        ans += (p * p - q) / 2;
    }

    std::cout << ans << '\n';
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