/*
Author: Nachiket Kanore
Created: Monday 21 December 2020 06:37:16 PM IST
(ツ) We must embrace pain and burn it as fuel for our journey.
*/
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T> ostream& operator<<(ostream& os, const set<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T, size_t size> ostream& operator<<(ostream& os, const array<T, size>& arr) {
	os << '{';
	string sep;
	for (const auto& x : arr)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}
template <typename A, typename B> ostream& operator<<(ostream& os, const map<A, B>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) {
	return uniform_int_distribution<int>(a, b)(mt_rng);
}

template <int D, typename T> struct vec : public vector<vec<D - 1, T>> {
	static_assert(D >= 1, "Dimensions invalid");
	template <typename... Args> vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {
	}
};
template <typename T> struct vec<1, T> : public vector<T> {
	vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
	}
};

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 2e5 + 5, inf = 1e18;

int cnt[N + 1];

void solve() {

	auto add = [&](int L, int R, int val) {
		assert(L <= R && R <= N);
		cnt[L] += val;
		cnt[R + 1] -= val;
	};

	int n;
	cin >> n;
	FOR(i, 1, n) {
		int l, r, z;
		cin >> l >> r >> z;
		// add(r, r, z);
		// int len = r - l + 1;
		// int each = z/len;
		// int last = each + (z % len);
		// if (len == 1) add(l, r, last);
		// else add(l, r-1, each), add(r, r, last);
	}

	FOR(i, 1, N) cnt[i] += cnt[i - 1];

	auto ok = [&](int rate) {
		int have = 0;
		FOR(i, 1, N) {
			if (!cnt[i])
				continue;
			have += rate;
			if (cnt[i] > have)
				return false;
			have -= cnt[i];
		}
		return true;
	};

	int lo = 0, hi = 1e12;
	int ans = inf;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (ok(mid))
			ans = mid, hi = mid - 1;
		else
			lo = mid + 1;
	}

	assert(ans ^ inf);
	cout << ans << "\n";

	memset(cnt, 0, sizeof(cnt));
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
