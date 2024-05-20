#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tcase; cin >> tcase;
	while (tcase--) {
		int n; string s; cin >> n >> s;

		int x = 0, y = 0;
		int n_ = -1, s_ = -1, e_ = -1, w_ = -1;
		for (int i = 0; i < s.length(); i++) {
			switch(s[i]) {
				case 'N':
					y++;
					n_ = i;
					break;
				case 'S':
					y--;
					s_ = i;	
					break;
				case 'E':
					x++;
					e_ = i;	
					break;
				case 'W':
					x--;
					w_ = i;
					break;
			}
		}

		if (x % 2 || y % 2) {
			cout << "NO\n";
			continue;
		}
		int rx = 0, ry = 0;
		x /= 2, y /= 2;
		string p;
		for (auto c : s) {
			bool r = 0;
			if (c == 'N' || c == 'S') {
				r = c == 'N' && ry < y || c == 'S' && ry > y;
				if (r) ry += c == 'N' ? 1 : -1;
			} else if (c == 'E' || c == 'W') {
				r = c == 'E' && rx < x || c == 'W' && rx > x;
				if (r) rx += c == 'E' ? 1 : -1;
			}
			p.push_back(r ? 'R' : 'H');
		}
		
		int r = count(p.begin(), p.end(), 'R');
		if (r == 0 || r == p.length()) {
			if (n_ >= 0 && s_ >= 0) p[n_] = p[s_] = r ? 'H' : 'R';
			else if (e_ >= 0 && w_ >= 0) p[e_] = p[w_] = r ? 'H' : 'R';
		}
		r = count(p.begin(), p.end(), 'R');
		if (r == 0 || r == p.length()) cout << "NO\n";
		else cout << p << "\n";
	}
	return 0;
}

