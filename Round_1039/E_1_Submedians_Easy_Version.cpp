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

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> s(n + 1);
    int low = 1, high = n + 1;
    while (low + 1 < high) {
        int mid = (low + high) / 2;
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] >= mid) {
                s[i] = s[i-1] + 1;
            } else {
                s[i] = s[i-1] - 1;
            }
        }
        int min_pref = 0;
        bool ok = false;
        for (int i = k; i <= n; ++i) {
            min_pref = std::min(min_pref, s[i - k]);
            if (s[i] - min_pref >= 0) {
                ok = true;
                break;
            }
        }
        if (ok) {
            low = mid;
        } else {
            high = mid;
        }
    }
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= low) {
            s[i] = s[i - 1] + 1;
        } else {
            s[i] = s[i - 1] - 1;
        }
    }
    int min_pref = 0;
    int min_pos = 0;
    int l = 1;
    int r = k;
    for (int i = k; i <= n; ++i) {
        if (s[i-k] < min_pref) {
            min_pref = s[i - k];
            min_pos = i - k;
        }
        if (s[i] - min_pref >= 0) {
            l = min_pos + 1;
            r = i;
            break;
        }
    }
    std::cout << low << ' ' << l << ' ' << r << '\n';
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
