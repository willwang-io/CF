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

#define EACH(x, a) for (auto& x: a)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class...Args> void dbg_out(T &&x, Args&&...args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

void solve() {
    
}

const int d8i[8] = {0, 0, -1, 1, -1, 1, -1, 1}, d8j[8] = {-1, 1, 0, 0, -1, -1, 1, 1};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a[3][3];
    REP(i, 3) {
        REP(j, 3) {
            std::cin >> a[i][j];
        }
    }
    int ans[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    REP(i, 3) {
        REP(j, 3) {
            if (!a[i][j]) { continue; }
            ans[i][j] += a[i][j];
            REP(k, 4) {
                int ii = i + d8i[k], jj = j + d8j[k];
                if (ii >= 0 && ii < 3 && jj >= 0 && jj < 3) {
                    ans[ii][jj] += a[i][j];
                }
            }
        }
    }
    REP(i, 3) {
        REP(j, 3) {
            std::cout << (1 - ans[i][j] % 2);
        }
        std::cout << '\n';
    }
}

