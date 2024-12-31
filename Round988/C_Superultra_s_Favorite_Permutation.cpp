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
#include <set>
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
 * @created: 2024-12-30 20:19:47
 */
bool is_prime(ll x){
    if (x <= 1) {
        return false;
    }
    if (x == 2 || x == 3) {
        return true;
    }
    if (x % 2 == 0 || x % 3 == 0) {
        return false;
    }
    if ((x - 1) % 6 != 0 && (x + 1) % 6 != 0) {
        return false;
    }
    for (ll i = 5; i * i <= x; i += 6) {
        if(x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    std::cin >> n;
    if (n <= 4) {
        std::cout << -1 << '\n';
        return;
    }
    FOR(i, 1, n + 1, 2) {
        std::cout << i << ' ';
    }
    int x = n % 2 == 0 ? n - 1 : n, seen = -1;
    FOR(i, 2, n + 1, 2) {
        if (!is_prime(x + i)) {
            seen = i;
            break;
        }
    }
    std::cout << seen << ' ';
    FOR(i, 2, n + 1, 2) {
        if (i == seen) {
            continue;
        }
        std::cout << i << ' ';
    }
    std::cout << '\n';
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