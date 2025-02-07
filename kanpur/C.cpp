/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 19 August 2021 08:57:17 PM IST
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

const double PI = acos(-1);

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int H, T, theta;
		cin >> H >> T >> theta;
		theta = PI * theta / 180.;
		double v0 = (double)sqrt(20. * H);
		double y = 1. * v0 * T * cos(theta) - 10. * T * T * cos(theta) / 2.;
		double x = 1. * v0 * T * sin(theta) + 10. * T * T * sin(theta) / 2.;
		cout << x << ' ' << y << endl;
		double ans = sqrt(x * x + y * y);
		cout << ans << '\n';
	}
}
