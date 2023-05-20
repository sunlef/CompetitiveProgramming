#include <bits/stdc++.h>
using i64 = int64_t;

void solve() {
    int n;
    std::cin >> n;
    std::set<std::string> set;
    std::string s;
    std::cin >> s;
    for (int i = 1; i < n; ++i) {
        set.insert(s.substr(i - 1, 2));
    }
    std::cout << set.size() << '\n';
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
