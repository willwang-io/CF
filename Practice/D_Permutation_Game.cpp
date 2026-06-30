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

typedef long long ll;
typedef std::vector<int> VI;
typedef std::pair<int, int> PII;
typedef std::vector<std::string> VS;

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class...Args> void dbg_out(T &&x, Args&&...args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define EACH(x, a) for (auto& x: a)
#define all(c) (c).begin(), (c).end()

/*
 * @author: will_wang
 * @created: 2024-12-30 13:28:04
 */
VI p, a;

ll dfs(int k, int i) {
    if (k == 0) {
        return 0LL;
    }
    ll ans = a[i - 1];
    return ans + std::max(dfs(k - 1, i), dfs(k - 1, p[i] - 1));
}

void solve() {
    int n, k, pb, ps;
    std::cin >> n >> k >> pb >> ps;
    p.resize(n);
    a.resize(n);
    EACH(i, p) {
        std::cin >> i;
    }
    EACH(i, a) {
        std::cin >> i;
    }
    dbg(dfs(k, pb), dfs(k, ps));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    REP(i, t) {
        solve();
    }
}