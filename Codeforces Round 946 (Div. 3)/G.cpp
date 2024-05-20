#include <bits/stdc++.h>
using namespace std;

int c[220000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tcase; cin >> tcase;
	while (tcase--) {
		int m, x; cin >> m >> x;
		for (int i = 1; i <= m; i++) cin >> c[i];
		priority_queue<int> Q;
		int tot = 0;
		for (int i = 1; i <= m; i++) {
			if (c[i] <= tot) {
				tot -= c[i];
				Q.push(c[i]);
			} else if (Q.size() > 0) {
				int t = Q.top();
				if (t > c[i]) {
					Q.pop();
					Q.push(c[i]);
					tot += t - c[i];
				}
			}
			tot += x;
		}
		cout << Q.size() << "\n";
	}
	return 0;
}

