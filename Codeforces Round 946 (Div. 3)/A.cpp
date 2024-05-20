#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tcase; cin >> tcase;
	while (tcase--) {
		int x, y; cin >> x >> y;
		int ans = (y + 1) / 2;
		ans = max(ans, (x - (15 * ans - 4 * y) + 14) / 15 + ans);
		cout << ans << "\n";
	}
	return 0;
}

