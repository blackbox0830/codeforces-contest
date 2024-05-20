#include <bits/stdc++.h>
using namespace std;

long long a[1 << 20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tcase; cin >> tcase;
	while (tcase--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		long long ans = 0;
		map<long long, int> M;
		for (int i = 1; i <= n - 2; i++) {
			M[a[i] << 20 | a[i + 1]]++;
		}
		for (auto it : M) ans = ans + (long long)it.second * (it.second - 1) / 2;
		M.clear();
		for (int i = 1; i <= n - 2; i++) {
			M[a[i] << 20 | a[i + 2]]++;
		}
		for (auto it : M) ans = ans + (long long)it.second * (it.second - 1) / 2;
		M.clear();
		for (int i = 1; i <= n - 2; i++) {
			M[a[i + 1] << 20 | a[i + 2]]++;
		}
		for (auto it : M) ans = ans + (long long)it.second * (it.second - 1) / 2;
		M.clear();
		for (int i = 1; i <= n - 2; i++) {
			M[a[i] << 40 | a[i +  1] << 20 | a[i + 2]]++;
		}
		for (auto it : M) ans = ans - (long long)it.second * (it.second - 1) / 2 * 3;
		cout << ans << "\n";
	}
	return 0;
}

