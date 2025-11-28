#include <iostream>
#include <vector>

const int MOD = 998244353;

struct SegTree {
    int n;
    std::vector<long long> sum, setv;

    void init(int len) {
        n = 1;
        while (n < len) {
            n <<= 1;
        }
        sum.assign(2 * n, 0);
        setv.assign(2 * n, -1);
    }

    void apply_set(int x, int l, int r, int v) {
        int mv = v % MOD;
        long long len = r - l + 1;
        sum[x] = len * mv % MOD;
        setv[x] = mv;
    }

    void push(int x, int l, int r) {
        if (setv[x] == -1 || l == r) {
            return;
        }
        int m = (l + r) >> 1;
        apply_set(x << 1, l, m, setv[x]);
        apply_set(x << 1 | 1, m + 1, r, setv[x]);
        setv[x] = -1;
    }

    void range_set(int x, int l, int r, int ql, int qr, int v) {
        if (ql > r || qr < l) {
            return;
        }
        if (ql <= l && r <= qr) {
            apply_set(x, l, r, v);
            return;
        }
        push(x, l, r);
        int m = (l + r) >> 1;
        range_set(x << 1, l, m, ql, qr, v);
        range_set(x << 1 | 1, m + 1, r, ql, qr, v);
        int s = (sum[x << 1] + sum[x << 1 | 1]) % MOD;
        sum[x] = s;
    }

    int range_sum(int x, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return sum[x];
        }
        push(x, l, r);
        int m = (l + r) >> 1;
        return (range_sum(x << 1, l, m, ql, qr) + range_sum(x << 1 | 1, m + 1, r, ql, qr)) % MOD;
    }

    void range_set(int l, int r, int v) {
        range_set(1, 0, n - 1, l, r, v);
    }

    int range_sum(int l, int r) {
        return range_sum(1, 0, n - 1, l, r);
    }
};

SegTree st;
std::vector<long long> lo_dp, dp;
int N;

long long calc(int i) {
    if (dp[i] != -1) {
        return dp[i];
    }
    if (i == 0) {
        dp[0] = 1;
        st.range_set(0, 0, 1);
        return 1;
    }
    long long a = calc(i - 1), pre = 0;
    if (lo_dp[i] > 0) {
        pre = st.range_sum(0, lo_dp[i] - 1);
    }
    long long val = (2 * a - pre + MOD) % MOD;
    dp[i] = val;
    if (lo_dp[i] > 0) {
        st.range_set(0, lo_dp[i] - 1, 0);
    }
    st.range_set(i, i, a);
    return val;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    N = n - 1;
    lo_dp.assign(N + 1, 0);
    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        int R = r - 1;
        if (R >= 1 && R <= N && lo_dp[R] < l) {
            lo_dp[R] = l;
        }
    }
    st.init(N + 1);
    dp.assign(N + 1, -1);
    std::cout << (2 * calc(N) % MOD) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}
