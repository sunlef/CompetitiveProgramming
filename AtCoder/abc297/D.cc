#include <bits/stdc++.h>

using i64 = int64_t;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 A, B;
    std::cin >> A >> B;

    i64 ans = 0;
    while (A != B) {
        if (A < B) {
            std::swap(A, B);
        }

        i64 k = std::max(i64(1), A / B - 1);
        ans += k;
        A -= k * B;
    }

    std::cout << ans << '\n';
}
