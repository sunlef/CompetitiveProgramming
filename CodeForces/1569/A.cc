#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            std::cout << i << ' ' << i + 1 << '\n';
            return;
        }
    }
    std::cout << "-1 -1\n";
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