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

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define EACH(x, a) for (auto& x: a)
#define all(x) (x).begin(), (x).end()

const int INF = 1e9;
const ll LINF = 1e18;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

#ifdef DEBUG
#define dbg(...) std::cerr << __LINE__ << ": [" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
template<class T> void dbg_out(T &&x) { std::cerr << x << "]\n"; }
template<class T, class...Args> void dbg_out(T &&x, Args&&...args) { std::cerr << x << ", "; dbg_out(args...); }
#else
#define dbg(...) 0
#endif

/*
 * @author: will_wang
 * @created: 2025-01-04 09:58:38
 */
void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::vector<PII>> adj(n + 1);
    VI wts(m);
    REP(i, m) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        wts[i] = w;
    }
    std::sort(all(wts));
    wts.erase(std::unique(all(wts)), wts.end());

    static int cost[405][405]; 
    static int dist[405];
    static int answer[300001];

    std::vector<std::vector<PII>> graph(n+1);
    std::vector<std::vector<int>> cost_per_idx(wts.size(), VI((n+1)*(n+1), INF));

    REP(idx, (int) wts.size()) {
        FOR(i, 1, n + 1, 1) {
            graph[i].clear();
            EACH(e, adj[i]) {
                int c = e.second > wts[idx] ? 1 : 0;
                graph[i].push_back({e.first, c});
            }
        }
        FOR(s, 1, n + 1, 1) {
            FOR(i, 1, n + 1, 1) {
                dist[i] = INF;
            }
            std::deque<int> dq;
            dist[s] = 0;
            dq.push_back(s);
            while (!dq.empty()) {
                int u = dq.front();
                dq.pop_front();
                int cd = dist[u];
                EACH(p, graph[u]) {
                    int v = p.first, c = p.second;
                    int nd = cd + c;
                    if (nd < dist[v]) {
                        dist[v] = nd;
                        if (c) {
                            dq.push_back(v);
                        } else {
                            dq.push_front(v);
                        }
                    }
                }
                FOR(v, 1, n + 1, 1) {
                    cost_per_idx[idx][s * (n + 1) + v] = dist[v];
                }
            }
        }
    }

    while (q--) {
        int a, b, k;
        std::cin >> a >> b >> k;
        int left = 0, right = (int) wts.size() - 1, ans = -1;
        while (left <= right) {
            int m = (left + right) / 2;
            int c = cost_per_idx[m][(a * (n + 1)) + b];
            if (c <= k - 1) {
                ans = m;
                right = m - 1;
            } else {
                left = m + 1;
            }
        }
        std::cout << (ans < 0 ? -1 : wts[ans]) << ' ';
    }
    std::cout << '\n';
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