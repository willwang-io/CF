#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <ranges>
#include <vector>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

static const int MAXV = 1000000;
int spf[MAXV + 1];

void sieve() {
    for (int i = 2; i <= MAXV; i++) {
        if (!spf[i]) {
            for (int j = i; j <= MAXV; j += i) {
                if (!spf[j]) spf[j] = i;
            }
        }
    }
}

struct F {
    int t;
    int p;
    int q;
    bool operator<(const F& o) const {
        if (t != o.t) return t < o.t;
        if (p != o.p) return p < o.p;
        return q < o.q;
    }
};

F getF(int x) {
    if (x == 1) {
        F r;
        r.t = 0;
        r.p = 0;
        r.q = 0;
        return r;
    }
    
    vector<int> primes;
    vector<int> exps;
    
    while (x > 1) {
        int f = spf[x], c = 0;
        while (spf[x] == f) {
            x /= f;
            c++;
        }
        primes.push_back(f);
        exps.push_back(c);
        if (primes.size() > 2) break;
    }
    
    if (primes.size() > 2) {
        F r;
        r.t = -1;
        return r;
    }
    
    int s = 0;
    for (int e : exps) s += e;
    if (s > 2) {
        F r;
        r.t = -1;
        return r;
    }
    
    if (primes.size() == 1) {
        if (exps[0] == 1) {
            F r;
            r.t = 1;
            r.p = primes[0];
            r.q = 0;
            return r;
        } else {
            F r;
            r.t = 2;
            r.p = primes[0];
            r.q = 0;
            return r;
        }
    } else {
        if (exps[0] == 1 && exps[1] == 1) {
            int a = primes[0], b = primes[1];
            if (a > b) swap(a, b);
            F r;
            r.t = 3;
            r.p = a;
            r.q = b;
            return r;
        } else {
            F r;
            r.t = -1;
            return r;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    
    int n;
    cin >> n;
    map<F, long long> freq;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        F f = getF(x);
        if (f.t != -1) freq[f]++;
    }
    
    long long cnt0 = 0;
    unordered_map<int, long long> c1;
    unordered_map<int, long long> c2;
    map<pair<int, int>, long long> c3;
    
    for (auto& kv : freq) {
        auto f = kv.first;
        long long c = kv.second;
        if (f.t == 0) cnt0 += c;
        else if (f.t == 1) c1[f.p] += c;
        else if (f.t == 2) c2[f.p] += c;
        else if (f.t == 3) c3[{f.p, f.q}] += c;
    }
    
    long long ans = 0;
    
    long long sum2 = 0;
    for (auto& kv : c2) sum2 += kv.second;
    ans += cnt0 * sum2;
    
    long long sum3 = 0;
    for (auto& kv : c3) sum3 += kv.second;
    ans += cnt0 * sum3;
    
    vector<int> ps;
    ps.reserve(c1.size());
    for (auto& kv : c1) ps.push_back(kv.first);
    sort(ps.begin(), ps.end());
    for (int i = 0; i < (int)ps.size(); i++) {
        for (int j = i + 1; j < (int)ps.size(); j++) {
            ans += c1[ps[i]] * c1[ps[j]];
        }
    }
    
    for (auto& kv : c1) {
        int p = kv.first;
        long long fc1 = kv.second;
        if (c2.find(p) != c2.end()) {
            ans += fc1 * c2[p];
        }
    }
    
    unordered_map<int, vector<pair<int, long long>>> adj;
    adj.reserve(c3.size() * 2);
    for (auto& kv : c3) {
        int p = kv.first.first, q = kv.first.second;
        long long f = kv.second;
        adj[p].push_back({q, f});
        adj[q].push_back({p, f});
    }
    for (auto& kv : c1) {
        int p = kv.first;
        long long fc1 = kv.second;
        if (adj.find(p) == adj.end()) continue;
        for (auto& ent : adj[p]) {
            ans += fc1 * ent.second;
        }
    }
    
    for (auto& kv : c2) {
        long long c = kv.second;
        ans += c * (c + 1) / 2;
    }
    
    for (auto& kv : c3) {
        long long c = kv.second;
        ans += c * (c + 1) / 2;
    }
    
    cout << ans << "\n";
    return 0;
}