#include <bits/stdc++.h>
using i64 = int64_t;

struct DSU {  // [0, n)
    int n;
    std::vector<int> fa, size;

    DSU(int n) : n(n) {
        fa.resize(n);
        std::iota(fa.begin(), fa.end(), 0);
        size.assign(n, 1);
    }

    void Union(const int lp, const int rp) {  // put v under u
        fa[rp] = lp;
        size[lp] += size[rp];
    }
    bool Compare(const int lp, const int rp) {
        return size[lp] > size[rp];
    }
    int find(int p) {
        while (fa[p] != p) {
            p = fa[p] = fa[fa[p]];
        }
        return p;
    }
    bool same(int p, int q) {
        return find(p) == find(q);
    }
    bool merge(int p, int q) {
        int u = find(p), v = find(q);
        if (u == v) return false;
        if (!Compare(u, v)) std::swap(u, v);
        Union(u, v);
        return true;
    }
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    std::vector<int> vis(n), s(n), ans(n - 1);
    auto dfs = [&] (auto dfs, int u) -> void {
        vis[u] = 1;
        int cnt = 0;
        for (auto [v, e] : adj[u]) {
            if (!vis[v]) {
                dfs(dfs, v);
                if (s[v] == 2) {
                    ans[e] = 1;
                } else {
                    cnt += s[v] + 1;
                }
                if (cnt > 2) {
                    return;
                }
            }
        }
        s[u] = cnt;
    };

    dfs(dfs, 0);

    DSU set(n);
    for (int i = 0; i < n; ++i) {
        for (auto [v, e] : adj[i]) {
            if (ans[e] == 0) {
                set.merge(i, v);
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        ok &= set.size[set.find(i)] == 3;
    }

    if (ok) {
        std::cout << std::count(ans.begin(), ans.end(), 1) << '\n';
        for (int i = 0; i < n - 1; ++i) {
            if (ans[i]) {
                std::cout << i + 1 << ' ';
            }
        }
        std::cout << '\n';
    } else {
        std::cout << "-1\n";
    }
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
