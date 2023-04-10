#include <bits/stdc++.h>

using i64 = int64_t;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
        for (int j = 1; j < m; ++j) {
            if (grid[i][j] == 'T' && grid[i][j - 1] == 'T') {
                grid[i][j] = 'C';
                grid[i][j - 1] = 'P';
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << grid[i] << '\n';
    }
}
