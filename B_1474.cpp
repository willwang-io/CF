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
#define rall(c) (c).rbegin(), (c).rend();
#define EACH(x, a) for (auto& x: a)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)

#define pb push_back
#define sz size
#define nl '\n'

typedef long long int ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const float PI = 3.1415926535897932384626433832795;

const int d4i[4]={-1,0,1,0}, d4j[4]={0,1,0,-1};
const int d8i[8]={-1,-1,0,1,1,1,0,-1}, d8j[8]={0,1,1,1,0,-1,-1,-1};

template<class T> void print_v(vector<T> &V) {EACH(v, V) cout << v << " "; cout << endl;}
template<class T> bool umin(T& a, const T& b) {return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) {return a<b?a=b, 1:0;}
void yes() {cout << "YES\n";}
void no() {cout << "NO\n";}

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
template<int N> struct sieve {
    int minDiv[N];
    vector<int> p;

    sieve() {
        for (int i = 2; i < N; ++i)
            minDiv[i] = i;
        for (int i = 2; i < N; ++i) {
            if (minDiv[i] != i) continue;
            for (int j = i; j < N; j += i) {
                minDiv[j] = min(minDiv[j], i);
            }
        }
    }
};

sieve<MAX_N> s;

void solve() {
    int d;
    cin >> d;
    VI A;
    for (int i = d + 1; ; ++i) {
        int t = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                t = 0;
                break;
            }
        }
        if (t) {
            A.push_back(i);
            break;
        }
    }
    for (int i = A.back() + d; ; ++i) {
        int t = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                t = 0;
                break;
            }
        }
        if (t) {
            A.push_back(i);
            break;
        }
    }
    cout << min(1LL * A[0] * A[1], 1LL * A[0] * A[0] * A[0]) << nl;
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
