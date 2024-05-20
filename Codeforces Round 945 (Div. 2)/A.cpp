#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tcase; cin >> tcase;
	while (tcase--) {
		int a, b, c; cin >> a >> b >> c;
		cout << ((a + b + c) % 2 ? -1 : (a + b + min(a + b, c)) / 2) << "\n";
	}
	return 0;
}
