#include <bits/stdc++.h>
using i64 = int64_t;

using i64 = long long;
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n) : n(n), a(n, T()) {}

    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }

    T sum(int x) {
        T ans;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};

struct Max {
    int v;
    Max(int x = -1E9) : v{x} {}

    Max &operator+=(Max a) {
        v = std::max(v, a.v);
        return *this;
    }
};