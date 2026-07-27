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

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vt<vt<int>> adj;
vt<int> seen;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, A, B;
    cin >> n >> A >> B;
    int arr[n];
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        total += arr[i];
    }
    sort(arr + 1, arr + n);
    ll x = arr[0] * A, ans = 0;

    if (x / static_cast<double>(total) >= B) {
        cout << 0 << nl;
        return 0;
    }
    for (int i = n - 1; i >= 1; --i) {
        total -= arr[i];
        double cur = x / static_cast<double>(total);
        if (cur >= B) {
            break;
        }
        ++ans;
    }
    cout << ans + 1 << nl;
}