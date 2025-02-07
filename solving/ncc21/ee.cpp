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
	int n;
	cin >> n;
	int D;
	cin >> D;
	vector<int> a(n);
	F0R(i, n) cin >> a[i];
	int ans = inf;
	FOR(d, 1, n - 1) {
		int best = inf;
		for (int i = 0; i + d < n; i++) {
			cmin(best, a[i] + a[i + d]);
		}
		ans += d * D + best;
	}
	cout << ans;
}
