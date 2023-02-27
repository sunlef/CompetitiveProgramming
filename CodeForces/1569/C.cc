#include <bits/stdc++.h>

using i64 = int64_t;
template <class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

template <int P>
struct MInt {
    int x;
    MInt() : x{} {}
    MInt(i64 x) : x{norm(x % P)} {}

    int norm(int x) {
        if (x < 0) x += P;
        if (x >= P) x -= P;
        return x;
    }
    int val() const {
        return x;
    }
    MInt operator-() const {
        MInt res;
        res.x = norm(P - x);
        return res;
    }
    MInt inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    MInt &operator*=(const MInt &rhs) {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    MInt &operator+=(const MInt &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    MInt &operator-=(const MInt &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    MInt &operator/=(const MInt &rhs) {
        return *this *= rhs.inv();
    }
    friend MInt operator*(const MInt &lhs, const MInt &rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend MInt operator+(const MInt &lhs, const MInt &rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend MInt operator-(const MInt &lhs, const MInt &rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend MInt operator/(const MInt &lhs, const MInt &rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
};

constexpr int P = 998'244'353;
using Z = MInt<P>;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int mx = *std::max_element(a.begin(), a.end());
    if (std::count(a.begin(), a.end(), mx) != 1) {
        Z ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans *= i;
        }
        std::cout << ans << '\n';
        return;
    }

    int cnt = std::count(a.begin(), a.end(), mx - 1);

    Z ans = 1;
    for (int i = 1; i <= cnt; ++i) {
        ans *= i;
    }
    ans *= cnt;
    for (int i = cnt + 2; i <= n; ++i) {
        ans *= i;
    }

    std::cout << ans << '\n';
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