#include <bits/stdc++.h>
using namespace std;

long long dp[55][110000];
int c[55], h[55];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tcase; cin >> tcase;
	while (tcase--) {
		int m, x; cin >> m >> x;
		for (int i = 1; i <= m; i++) cin >> c[i] >> h[i];
		int tot = 0;
		for (int i = 1; i <= m; i++) tot += h[i];
		for (int i = 0; i < 55; i++) for (int j = 0; j <= tot; j++) dp[i][j] = -1;
		dp[0][0] = 0;
		for (int i = 0; i < m; i++) for (int j = 0; j <= tot; j++) if (dp[i][j] != -1) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + x);
			if (dp[i][j] >= c[i + 1]) dp[i + 1][j + h[i + 1]] = max(dp[i + 1][j + h[i + 1]], dp[i][j] - c[i + 1] + x);
		}
		for (int j = tot; j >= 0; j--) if (dp[m][j] != -1) {
			cout << j << "\n";
			break;
		}
	}
	return 0;
}

