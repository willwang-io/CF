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
template<class T> bool umin(T& a, const T& b) {return b<a?a=b, 1:0;}
template<class T> bool umax(T& a, const T& b) {return a<b?a=b, 1:0;}
void yes() {cout << "YES\n";}
void no() {cout << "NO\n";}

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vt<vt<int>> adj;
vt<int> seen;

void solve() {
    int n, k;
    cin >> n >> k;
    vt<int> A(k);
    for (auto &a: A) {
        cin >> a;
    }
    sort(rall(A));
    int ans = 0, need = 0;
    for (int i = 0; i < k; ++i) {
        if (need < A[i]) {
            need += n - A[i];
            ++ans;
        }
    }
    cout << ans << nl;
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