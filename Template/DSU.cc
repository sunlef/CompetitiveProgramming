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