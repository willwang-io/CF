#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::string s;
        std::cin >> n >> k >> s;
        std::vector<int> pre(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                pre[i] = i;
            } else {
                pre[i] = (i ? pre[i - 1] : -1);
            }
        }
        std::vector<int> pick(n);
        int last = -1;
        bool ok = true;
        for (int l = 0; l <= n - k; ++l) {
            int r = l + k - 1;
            if (last >= l && last <= r) {
                continue;
            }
            int x = pre[r];
            if (x < l) {
                ok = false;
                break;
            }
            pick[x] = 1;
            last = x;
        }
        if (!ok) {
            std::cout << "NO\n";
            continue;
        }
        int mx = n, mn = 1;
        std::vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (pick[i]) {
                ans[i] = mx--;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!pick[i]) {
                ans[i] = mn++;
            }
        }
        std::cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
    }
}