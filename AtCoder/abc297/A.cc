#include <bits/stdc++.h>

using i64 = int64_t;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d;
    std::cin >> n >> d;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] <= d) {
            std::cout << a[i] << '\n';
            return 0;
        }
    }

    std::cout << "-1\n";
}
