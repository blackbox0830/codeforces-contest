#include <bits/stdc++.h>
using namespace std;

bool vis[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tcase; cin >> tcase;
	while (tcase--) {
		int n; cin >> n;
		string s; cin >> s;
		memset(vis, 0, sizeof vis);
		for (auto c : s) {
			vis[c - 'a'] = 1;
		}
		vector<int> v;
		for (int i = 0; i < 26; i++) if (vis[i]) {
			v.push_back(i);
		}
		vector<int> vv(26, -1);
		for (int i = 0; i < v.size(); i++) {
			vv[v[i]] = v[v.size() - i - 1];
		}
		string ans;
		for (auto c : s) {
			ans.push_back(vv[c - 'a'] + 'a');
		}
		cout << ans << "\n";
	}
	return 0;
}

