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

template <class T> void printv (const vector<T> &V) {for(auto& v:  V) cout << v << " ";cout << nl;}

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vt<vt<int>> adj;
vt<int> seen;

void solve() {
    int n;
    cin >> n;
    vt<int> A(n);
    EACH(a, A) {
        cin >> a;
    }
    sort(rall(A));
    ll pt = 0LL;
    REP(i, n) {
        if (i % 2 == 0) {
            if (A[i] % 2 == 0) {
                pt += A[i];
            }
        } else {
            if (A[i] % 2 == 1) {
                pt -= A[i];
            }
        }
    }
    if (!pt) {
        cout << "Tie\n";
    } else if (pt > 0) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }
}