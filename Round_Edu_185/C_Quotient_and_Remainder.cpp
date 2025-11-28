#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    long long n, k;
    std::cin >> n >> k;
    std::vector<long long> a;
    for (int i = 0; i < n; ++i) {
        long long q;
        std::cin >> q;
        long long tmp = (k - q) / (q + 1);
        if (tmp >= 1) {
            a.push_back(tmp);
        }
    }
    std::vector<long long> b;
    for (int i = 0; i < n; ++i) {
        long long r;
        std::cin >> r;
        if (r >= 1) {
            b.push_back(r);
        }
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    long long ans = 0;
    int i = 0;
    for (auto &x: a) {
        if (i < b.size() && b[i] <= x) {
            ++ans;
            ++i;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}