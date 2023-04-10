#include <bits/stdc++.h>

using i64 = int64_t;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::map<char, std::vector<int>> map;
    for (int i = 0; i < 8; ++i) {
        map[s[i]].push_back(i);
    }

    bool ok = true;
    ok &= map['B'][0] ^ map['B'][1];
    ok &= (map['R'][0] < map['K'][0]) && (map['K'][0] < map['R'][1]);

    std::cout << (ok ? "Yes\n" : "No\n");
}
