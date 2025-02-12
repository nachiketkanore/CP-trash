/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 10 October 2021 04:40:44 PM IST
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
		int N;
		cin >> N;
		int A[N], G = 0;
		F0R(i, N) {
			cin >> A[i];
			G = __gcd(G, A[i]);
		}
		if (G % 2 == 1) {
			cout << 0 << '\n';
		} else {
			int ans = N * N;
			F0R(i, N) {
				int req = 0;
				while (A[i] % 2 == 0) {
					req++;
					A[i] /= 2;
				}
				cmin(ans, req);
			}
			assert(ans != N * N);
			cout << ans << '\n';
		}
	}
}
