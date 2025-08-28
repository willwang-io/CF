#include <bits/stdc++.h>

struct S { int e, s, w; };

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            int x;
            std::cin >> x;
            pos[x].push_back(i);
        }
        std::vector<S> seg;
        for (int v = 1; v <= n; ++v) {
            auto &p = pos[v];
            if (p.size() >= v) {
                for (int k = v; k <= p.size(); ++k) {
                    seg.push_back({p[k - 1], p[k - v], v});
                }
            }
        }
        std::sort(seg.begin(), seg.end(), [](const S &a, const S &b) {
            if (a.e != b.e) { return a.e < b.e; }
            return a.s < b.s;
        });
        int m = seg.size();
        std::vector<int> ends(m), pre(m + 1);
        for (int i = 0; i < m; ++i) {
            ends[i] = seg[i].e;
        }
        for (int i = 1; i <= m; ++i) {
            int s = seg[i - 1].s;
            pre[i] = std::upper_bound(ends.begin(), ends.begin() + i - 1, s - 1) - ends.begin();
        }
        std::vector<int> dp(m + 1, -1);
        std::function<int(int)> solve = [&](int i) {
            if (i == 0) {
                return 0;
            }
            if (dp[i] != -1) {
                return dp[i];
            }
            return dp[i] = std::max(solve(i - 1), solve(pre[i]) + seg[i - 1].w);
        };
        std::cout << solve(m) << '\n';
    }
}