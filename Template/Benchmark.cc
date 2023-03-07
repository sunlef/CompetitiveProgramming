#include <bits/stdc++.h>

using i64 = int64_t;

int main() {
    int cnt = 0;

    while (true) {
        cnt += 1;
        system("./gen > in");

        system("./std < in > ans");
        system("./z < in > out");

        if (system("diff ans out")) {
            std::cout << "WA test #" << cnt << '\n';
            break;
        }

        std::cout << "OK test #" << cnt << '\n';
    }

    std::vector<std::pair<int, int>> a;
}
