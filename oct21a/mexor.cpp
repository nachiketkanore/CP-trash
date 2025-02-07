/**
 *    Author: Nachiket Kanore
 *    Created: Monday 04 October 2021 12:42:32 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
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

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int X;
		cin >> X;
		int lo = 0, hi = 2e9;
		int ans = -1;
		auto get_or = [](int upto) {
			if (upto <= 0)
				return int(0);
			int ret = 0;
			F0R(bit, 32) if ((1LL << bit) <= upto) ret |= 1LL << bit;
			return ret;
		};
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (get_or(mid - 1) <= X) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		assert(~ans);
		cout << ans << '\n';
	}
}
