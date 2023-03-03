#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int x, y;
    std::cin >> x >> y;

    std::cout << 2 * (x - y) << '\n';
    for (int i = y; i < x; ++i) {
        std::cout << i << ' ';
    }
    for (int i = x; i > y; --i) {
        std::cout << i << " \n"[i == y + 1];
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
