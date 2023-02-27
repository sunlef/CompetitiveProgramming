#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::vector<std::string> grid(n, std::string(n, '='));
    for (int i = 0; i < n; ++i) {
        grid[i][i] = 'X';
        if (s[i] == '1') continue;
        for (int j = 0; j < n; ++j) {
            if (j != i && grid[i][j] != '-' && s[j] == '2') {
                grid[i][j] = '+';
                grid[j][i] = '-';
                break;
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1' && std::count(grid[i].begin(), grid[i].end(), '-') != 0) {
            ok = false;
        }
        if (s[i] == '2' && std::count(grid[i].begin(), grid[i].end(), '+') == 0) {
            ok = false;
        }
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '+' && grid[j][i] != '-') {
                ok = false;
            } else if (grid[i][j] == '-' && grid[j][i] != '+') {
                ok = false;
            }
        }
    }

    if (ok) {
        std::cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << grid[i][j];
            }
            std::cout << '\n';
        }
    } else {
        std::cout << "NO\n";
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