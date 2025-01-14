#include <bits/stdc++.h>
using namespace std;

template<class T>
struct BIT {
    int n;
    vector<vector<T>> bit;

    BIT(void): n(0) {}

    void resize(const int & n) {
        bit.clear();
        bit.resize(n);
        this->n = n;
    }

    void insert(const int& x, const T& d) {
        for (int i = x + 1; i <= n; i += i & -i) bit[i - 1].push_back(d);
    }

    void update(void) {
        for (int i = 0; i < n; i++) sort(bit[i].begin(), bit[i].end());
    }

    int count(const int& x, const T& l, const T& r) {
        int ans = 0;
        for (int i = x; i > 0; i -= i & -i) ans += lower_bound(bit[i - 1].begin(), bit[i - 1].end(), r) - lower_bound(bit[i - 1].begin(), bit[i - 1].end(), l);
        return ans;
    }

    int search(const T& l, const T& r, int s) {
        int ans = 0, k = 0, b = 0;
        for (; (1 << k) <= n; k++);
        for (k--; k >= 0; k--) {
            b = 1 << k;
            int i = ans + b, c;
            if (i <= n && (c = lower_bound(bit[i - 1].begin(), bit[i - 1].end(), r) - lower_bound(bit[i - 1].begin(), bit[i - 1].end(), l)) <= s) {
                ans ^= b;
                s -= c;
            }
        }
        return ans;
    }
};

BIT<int> bit;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tcase; cin >> tcase;
    while (tcase--) {
        int a, b, n, m; cin >> a >> b >> n >> m;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            x[i]--;
            y[i]--;
        }
        vector<int> xv = x;
        sort(xv.begin(), xv.end());
        xv.resize(unique(xv.begin(), xv.end()) - xv.begin());

        bit.resize(xv.size());
        for (int i = 0; i < n; i++) bit.insert(lower_bound(xv.begin(), xv.end(), x[i]) - xv.begin(), y[i]);
        bit.update();
        vector<int> ans(2, 0);
        int lx = 0, rx = a, ly = 0, ry = b;
        for (int i = 0; i < m; i++) {
            char c; int k; cin >> c >> k;

            int xlx = lx, xrx = rx, xly = ly, xry = ry;
            if (c == 'U') lx = xrx = lx + k;
            else if (c == 'D') rx = xlx = rx - k;
            else if (c == 'L') ly = xry = ly + k;
            else if (c == 'R') ry = xly = ry - k;

            int lft = lower_bound(xv.begin(), xv.end(), xlx) - xv.begin();
            int rht = lower_bound(xv.begin(), xv.end(), xrx) - xv.begin();
            ans[i % 2] += bit.count(rht, xly, xry) - bit.count(lft, xly, xry);
        }
        cout << ans[0] << " " << ans[1] << "\n";
    }

    return 0;
}
