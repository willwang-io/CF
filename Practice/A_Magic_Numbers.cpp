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

void solve() {
    
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string n;
    std::cin >> n;
    for (char c: n) {
        if (!(c == '1' || c == '4')) {
            std::cout << "NO\n";
            return 0;
        }
    }
    int i = 0, m = (int) n.size();
    while (i < m) {
        if (n[i] == '4') {
            std::cout << "NO\n";
            return 0;
        }
        ++i;
        if (i < m && n[i] == '4') {
            ++i;
        } 
        if (i < m && n[i] == '4') {
            ++i;
        }
    }
    std::cout << (i >= m ? "YES\n" : "NO\n");
}
