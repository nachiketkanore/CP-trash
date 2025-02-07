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
	set<char> one, two;
	for (char ch = 'a'; ch <= 'm'; ch++)
		one.insert(ch);
	for (char ch = 'N'; ch <= 'Z'; ch++)
		two.insert(ch);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		bool ok = true;
		while (n--) {
			string s;
			cin >> s;
			bool fi = true, se = true;
			for (char ch : s) {
				fi &= one.count(ch);
				se &= two.count(ch);
			}
			ok &= fi ^ se;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}
