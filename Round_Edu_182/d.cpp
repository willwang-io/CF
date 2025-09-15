#include <bits/stdc++.h>

void solve() {
    int n;
    long long y;
    std::cin >> n >> y;
    std::vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] > m) {
            m = a[i];
        }
    }
    std::vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i]];
    }
    std::vector<int> pre(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        pre[i] = pre[i - 1] + cnt[i];
    }
    long long best = n + y * cnt[1];
    for (int x = 2; x <= m; ++x) {
        int last = (m + x - 1) / x;
        long long s = 0, match = 0;
        for (int k = 1; k <= last; ++k) {
            int r = k * x;
            if (r > m) {
                r = m;
            }
            int l = (k - 1) * x;
            int c = pre[r] - pre[l];
            if (c == 0 && cnt[k] == 0) {
                continue;
            }
            s += 1LL * k * c;
            if (cnt[k] > 0) {
                match += std::min(cnt[k], c);
            }
        }
        long long val = s + y * match;
        if (val > best) {
            best = val;
        }
    }
    long long ans = best - y * n;
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
