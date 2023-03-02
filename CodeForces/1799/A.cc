#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> ans(n, -1);
    std::set<int> s;

    int f = 0, g = n - 1;
    for (int i = 0; i < m; ++i) {
        int p;
        std::cin >> p;
        s.insert(p);
        if ((int)s.size() > f && g >= 0) {
            ans[g--] = i + 1;
        }
        f = s.size();
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
