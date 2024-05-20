#include <bits/stdc++.h>
using namespace std;

int a[1 << 17];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tcase; cin >> tcase;
	while (tcase--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];	
		}
		int ans = 1;
		for (int b = 0; b < 20; b++) {
			int prev = -1, mx = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] & 1 << b) {
					prev = i;
				}
				mx = max(mx, i - prev + 1);
			}
			if (prev >= 0) {
				ans = max(ans, mx);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
