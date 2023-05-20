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
    
    std::vector<int> a(n);
    DSU s(n);
    std::vector<std::set<int>> set(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i] -= 1;
        s.merge(i, a[i]);
        set[i].insert(a[i]);
        set[a[i]].insert(i);
    }

    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (s.find(i) == i) {
            max += 1;
        }
    }

    std::vector<int> p;
    for (int i = 0; i < n; ++i) {
        if (set[i].size() == 1) {
            p.push_back(i);
        }
    }

    for (int i = 1; i < int(p.size()); ++i) {
        s.merge(p[i - 1], p[i]);
    }

    int min = 0;
    for (int i = 0; i < n; ++i) {
        if (s.find(i) == i) {
            min += 1;
        }
    }

    std::cout << min << ' ' << max << '\n';
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
