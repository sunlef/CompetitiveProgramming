#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<int> cnt(26);
    for (char ch : s) {
        cnt[ch - 'a'] += 1;
    }

    std::string f, g;

    for (int i = 0; i < 26; ++i) {
        while (cnt[i] >= 2) {
            f += i + 'a';
            g += i + 'a';

            cnt[i] -= 2;
        }

        if (cnt[i] == 0) {
            continue;
        }

        int k = -1;
        for (int j = i + 1; j < 26; ++j) {
            if (cnt[j] + 1 == int(s.size() - f.size() - g.size())) {
                k = j;
            }
        }

        if (k == -1) {
            for (int j = i + 1; j < 26; ++j) {
                while (cnt[j]) {
                    f += j + 'a';
                    cnt[j] -= 1;
                }
            }
        } else {
            while (cnt[k] >= 2) {
                f += k + 'a';
                g += k + 'a';
                cnt[k] -= 2;
            }

            if (cnt[k]) {
                f += k + 'a';
                cnt[k] -= 1;
            }
        }

        f += i + 'a';
    }

    std::cout << f + std::string(g.rbegin(), g.rend()) << '\n';
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
