#include <bits/stdc++.h>
using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    auto f = [&] (const std::vector<int> &t, int l, int r) {
        std::vector<int> res;
        res.insert(res.end(), t.begin() + r, t.end());
        res.insert(res.end(), t.begin() + l, t.begin() + r);
        res.insert(res.end(), t.begin(), t.begin() + l);
        std::reverse(res.begin() + n - r, res.begin() + n - l);
        return res;
    };

    std::vector<int> ans(p.rbegin(), p.rend());
    auto list = {
        n,
        int(std::find(p.begin(), p.end(), n) - p.begin()),
        int(std::find(p.begin(), p.end(), n - 1) - p.begin())
    };

    for (int r : list) {
        for (int l = 0; l < r; ++l) {
            ans = std::max(ans, f(p, l, r));
        }
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
