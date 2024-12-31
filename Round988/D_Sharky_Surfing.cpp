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
 * @created: 2024-12-30 20:45:28
 */

struct Tmp {
    int x, y, type;
    Tmp(int x, int y, int type): x(x), y(y), type(type) {}
};

void solve() {
    int n, m, l;
    std::cin >> n >> m >> l;
    std::vector<Tmp> a;
    REP(i, n) {
        int x, y;
        std::cin >> x >> y;
        a.emplace_back(x, y, 1);
    }
    REP(i, m) {
        int x, y;
        std::cin >> x >> y;
        a.emplace_back(x, y, 0);
    }
    std::sort(all(a), [](const auto &i, const auto &j) {return i.x < j.x; });
    ll k = 1LL;
    std::priority_queue<int> pq;
    EACH(i, a) {
        if (i.type == 0) {
            pq.push(i.y);
        } else {
            while (!pq.empty() && k < i.y - i.x + 2) {
                k += pq.top();
                pq.pop();
            }
            if (k < i.y - i.x + 2) {
                std::cout << -1 << '\n';
                return;
            }
        }
    }
    std::cout << m - pq.size() << '\n';
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