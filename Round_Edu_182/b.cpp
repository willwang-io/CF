#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), pos(n + 1, -1), zeros;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        if (a[i] == 0) {
            zeros.push_back(i);
        } else {
            pos[a[i]] = i;
        }
    }
    std::vector<int> mis;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != 0 && a[i] != i) {
            mis.push_back(i);
        }
    }
    if (mis.empty()) {
        if ((int)zeros.size() <= 1) {
            std::cout << 0 << '\n';
        } else {
            int l = *std::min_element(zeros.begin(), zeros.end());
            int r = *std::max_element(zeros.begin(), zeros.end());
            std::cout << (r - l + 1) << '\n';
        }
        continue;
    }
    std::vector<char> vis(n + 1, 0);
    std::deque<int> q;
    for (int x: mis) {
        if (!vis[x]) {
            vis[x] = 1;
            q.push_back(x);
        }
    }
    int l = n + 1, r = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop_front();
        if (x < l) {
            l = x;
        }
        if (x > r) {
            r = x;
        }
        if (a[x] != 0) {
            int v = a[x];
            if (!vis[v]) {
                vis[v] = 1;
                q.push_back(v);
            }
            if (pos[v] != -1 && !vis[pos[v]]) {
                vis[pos[v]] = 1;
                q.push_back(pos[v]);
            }
        }
    }
    if ((int)zeros.size() >= 2) {
        int mz = *std::min_element(zeros.begin(), zeros.end());
        int Mz = *std::max_element(zeros.begin(), zeros.end());
        int mval = n + 1, Mval = 0;
        for (int v = 1; v <= n; ++v) {
            if (pos[v] == -1) {
                if (v < mval) {
                    mval = v;
                }
                if (v > Mval) {
                    Mval = v;
                }
            }
        }
        if (mz < l) {
            l = mz;
        }
        if (Mz > r) {
            r = Mz;
        }
        if (mval < l) {
            l = mval;
        }
        if (Mval > r) {
            r = Mval;
        }
    }
    std::cout << (r - l + 1) << '\n';
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