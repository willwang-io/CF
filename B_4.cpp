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


void f() {
    int d = 4, sum_time = 13;
    for (int i = 2; i < 9; ++i) {
        for (int j = 1; j < 7; ++j) {
            for (int k = 5; k < 9; ++k) {
                for (int l = 6; l < 9; ++l) {
                    if (i + j + k + l == sum_time) {
                        VI A = {i, j, k, l};
                        print_v(A);
                    }
                }
            }
        }
    }
}

void solve() {
    int d, sum_time;
    cin >> d >> sum_time;
    int mn = 0, mx = 0;
    VII A(d);
    EACH(a, A) {
        cin >> a.first >> a.second;
        mn += a.first;
        mx += a.second;
    }
    if (mx < sum_time || mn > sum_time) {
        no();
    } else {
        yes();
        sum_time -= mn;
        REP(i, d) {
            int x = min(sum_time, A[i].second - A[i].first);
            sum_time -= x;
            A[i].first += x;
            cout << A[i].first << ' ';
        }
        cout << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    REP(i, t) {
        solve();
    }
}
