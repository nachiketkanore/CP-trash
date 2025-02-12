/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 12:50:15 PM IST
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
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	F0R(i, N) cin >> A[i];
	int ans = 0;
	F0R(i, N) {
		int get = 0;
		for (int j = i; j < N; j += K) {
			get += A[j];
		}
		cmax(ans, get);
	}
	cout << ans << '\n';
}
