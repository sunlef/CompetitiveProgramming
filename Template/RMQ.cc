struct RMQ {
    int n;
    std::vector<std::vector<int>> dp;

    int better(const std::initializer_list<int> &list) {
        return std::max(list);
    }

    RMQ(const std::vector<int> &init)
        : n(init.size()), dp(n, std::vector<int>(std::__lg(n) + 1)) {
        for (int i = 0; i < n; ++i) {
            dp[i][0] = init[i];
        }
        for (int k = 1; k <= std::__lg(n); ++k) {
            for (int i = 0; i < n; ++i) {
                if (i + (1 << k) - 1 >= n) continue;
                int j = i + (1 << (k - 1));
                dp[i][k] = better({dp[i][k - 1], dp[j][k - 1]});
            }
        }
    };

    int query(int l, int r) {  // [l, r)
        int len = r - l;
        int k = std::__lg(len);
        return better({dp[l][k], dp[r - (1 << k)][k]});
    }
};
