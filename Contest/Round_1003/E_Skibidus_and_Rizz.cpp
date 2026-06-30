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
 * Created: Feb 09, 2025 @ 09:37:04
 * Author: will_wang
 */

std::string helper(int n0, int n1, int k, int d) {
    if(k > n0) {
        return "";
    }
    std::string ans;
    for(int i = 0; i < k; ++i) {
        ans += '0';
    } 
    int used0 = k, used1 = 0;
    if(n1 < k - d) {
        return "";
    }
    int p = std::min(n0 - used0, n1 - (k - d));
    for(int i = 0; i < p; ++i){
        ans += '1';
        ans += '0';
    }
    used0 += p; used1 += p;
    int descent = k - d;
    for(int i = 0; i < descent; ++i) { 
        ans += '1';
    } 
    used1 += descent;
    int left0 = n0 - used0, left1 = n1 - used1;
    if(left0 < 0 || left1 < 0 || left0 != left1) {
        return "";
    };
    for(int i = 0; i < left0; ++i) {
        ans += '1';
        ans += '0';
    }
    return ans;
}

void solve() {
    int n, m, k; 
    std::cin >> n >> m >> k;
    if(k < std::abs(n-m) || k > std::max(n,m)) {
        std::cout << "-1\n";
        return;
    }
    int d = n - m;
    if(d >= 0){
        auto ans = helper(n, m, k, d);
        if (ans.size() != size_t(n+m)) {
            std::cout << "-1\n";
        } else {
            std::cout << ans << "\n";
        }
    } else {
        auto ans = helper(m, n, k, -d);
        if(ans.size() != size_t(n+m)) { 
            std::cout << -1 << "\n"; 
        } else {
            for(char &c : ans) {
                c = (c == '0' ? '1' : '0');
            }
            std::cout << ans << "\n";
        }
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
