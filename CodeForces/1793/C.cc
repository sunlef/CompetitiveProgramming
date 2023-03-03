#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int min = 1, max = n;

    int l = 0, r = n - 1;
    while (l <= r && (a[l] == min || a[l] == max || a[r] == min || a[r] == max)) {
        if (a[l] == min) ++l, ++min;
        if (a[l] == max) ++l, --max;
        if (a[r] == min) --r, ++min;
        if (a[r] == max) --r, --max;
    }

    if (l <= r) {
        std::cout << l + 1 << ' ' << r + 1 << '\n';
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
