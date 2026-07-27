#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <cmath>
#include <cstring>

using ll = long long;

void solve() {
    int n;
    std::cin >> n;
    int a[n][5], cnt[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cin >> a[i][j];
            cnt[j] += a[i][j];
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i == j) {
                continue;
            }
            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
            for (int k = 0; k < n; ++k) {
                if (a[k][i] == 1) {
                    ++cnt1;
                }
                if (a[k][j] == 1) {
                    ++cnt2;
                }
                if (a[k][i] == 0 && a[k][j] == 0) {
                    ++cnt3;
                }
            }
            if (cnt1 >= n / 2 && cnt2 >= n / 2 && cnt3 == 0) {
                std::cout << "YES\n";
                return;
            }
        }
    }
    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }
}