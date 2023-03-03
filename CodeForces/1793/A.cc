#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    i64 a, b, n, m;
    std::cin >> a >> b >> n >> m;

    i64 A = b * n;
    i64 B = a * m * (n / (m + 1)) + std::min(a, b) * (n % (m + 1));
    std::cout << std::min(A, B) << '\n';
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
