#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int inf = 1e18;
const int N = 5e5 + 5;

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;
		map<int, int> f;
		vector<int> ans;
		FOR(i, 1, k) {
			int u;
			cin >> u;
			if (u >= 1 && u <= n) {
				f[u]++;
				if (f[u] == 2) {
					ans.push_back(u);
				}
			}
		}
		sort(ALL(ans));
		cout << sz(ans) << ' ';
		for (int x : ans)
			cout << x << ' ';
		cout << '\n';
	}
}
