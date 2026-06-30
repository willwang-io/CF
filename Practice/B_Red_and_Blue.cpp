#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define EACH(x, a) for (auto& x: a)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define nl '\n'
#define vt vector
typedef long long int ll;

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

const int d4i[4]={-1,0,1,0}, d4j[4]={0,1,0,-1};
const int d8i[8]={-1,-1,0,1,1,1,0,-1}, d8j[8]={0,1,1,1,0,-1,-1,-1};

template <class T> void printv (const vector<T> &V) {EACH(v, V) cout << v << " ";cout << nl;}
template<class T> bool umin(T& a, const T& b) {return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) {return a<b?a=b, 1:0;}
void yes() {cout << "YES\n";}
void no() {cout << "NO\n";}

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vt<vt<int>> adj;
vt<int> seen;

void solve() {
    int n, m;
    cin >> n;
    vt<int> R(n);
    EACH(r, R) cin >> r;
    cin >> m;
    vt<int> B(m);
    EACH(b, B) cin >> b;
    vt<ll> pR(n + 1), pB(m + 1);
    for (int i = 1; i <= n; ++i) {
        pR[i] += pR[i-1] + R[i-1];
    }
    for (int i = 1; i <= m; ++i) {
        pB[i] += pB[i-1] + B[i-1];
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            umax(ans, pR[i] + pB[j]);
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    REP(i, t) {
        solve();
    }
}