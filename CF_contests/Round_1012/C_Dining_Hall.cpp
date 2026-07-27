#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <ranges>
#include <vector>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class...Args> void dbg_out(T &&x, Args&&...args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

/*
 * Created: Mar 23, 2025 @ 00:30:47
 * Author: will_wang
 */
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::map<std::pair<int, int>, int> tables;
    for (int i = 0; i < n; ++i) {
        std::queue<std::pair<int, int>> q;
        std::set<std::pair<int, int>> seen;
        q.push({0, 0});
        seen.insert({0, 0});

        std::pair<int, int> coord;
        bool ok = false;

        while (!q.empty() && !ok) {
            int size = q.size();
            std::vector<std::pair<int, int>> cand;

            for (int j = 0; j < size; ++j) {
                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    int nx = x + dx[d], ny = y + dy[d];

                    if (nx < 0 || ny < 0) continue;

                    if ((nx % 3 == 1 || nx % 3 == 2) && (ny % 3 == 1 || ny % 3 == 2)) {
                        int tx = (nx / 3) * 3 + 1, ty = (ny / 3) * 3 + 1;

                        int occupied = tables[{tx, ty}];
                        int cnt = __builtin_popcount(occupied);

                        if ((a[i] == 0 && cnt == 0) ||
                            (a[i] == 1 && cnt < 4)) {
                            cand.push_back({tx, ty});
                        }
                    } else if (seen.find({nx, ny}) == seen.end()) {
                        q.push({nx, ny});
                        seen.insert({nx, ny});
                    }
                }
            }

            if (!cand.empty()) {
                std::sort(cand.begin(), cand.end());
                coord = cand[0];
                ok = true;
            }
        }

        int& occupied = tables[coord];
        int idx = 0;
        while (idx < 4 && (occupied & (1 << idx))) {
            idx++;
        }
        occupied |= (1 << idx);
        std::cout << coord.first + (idx) / 2 << " " << coord.second + (idx % 2) << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        // std::cout << "Case #" << (i + 1) << ": ";
        solve();
    }
}
