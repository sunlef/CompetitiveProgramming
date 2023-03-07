struct Hash {
    int n, base;
    std::string s;
    std::vector<uint64_t> info, pow;

    Hash(const std::string &s, int base = 13331)
        : n(s.size()), base(base), s(s), info(n + 1, 0), pow(n + 1, 1) {
        for (int i = 1; i <= n; ++i) {
            pow[i] = pow[i - 1] * base;
        }
        for (int i = 1; i <= n; ++i) {
            info[i] = info[i - 1] * base + s[i - 1] + base;
        }
    }

    uint64_t subhash(int pos, int len = 2E9) {
        assert(pos >= 0 && pos < n && len > 0);
        len = std::min(len, n - pos);
        int l = pos + 1, r = pos + len;
        auto res = info[r] - info[l - 1] * pow[r - l + 1];
        return res;
    }
};
