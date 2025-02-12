/*
Author: Nachiket Kanore
Created: Tuesday 15 December 2020 07:00:46 PM IST
(ツ) Wrinkles should merely indicate where smiles have been.
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

const int N = 5000, inf = 1e18;

int n;
int cnt[N + 1];
int tcnt[N + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	FOR(i, 1, n) {
		int u;
		cin >> u;
		cnt[u]++;
		tcnt[u]++;
	}

	int best_mid = -1;
	int best_len = 0;

	FOR(mid, 1, N) if (cnt[mid] > 0) {
		int get_left = 0;
		int get_right = 0;

		for (int left = mid - 1; left >= 1; left--) {
			if (tcnt[left] > 0) {
				tcnt[left]--;
				get_left++;
			}
		}

		for (int right = mid - 1; right >= 1; right--) {
			if (tcnt[right] > 0) {
				tcnt[right]--;
				get_right++;
			}
		}

		int get_len = 1 + get_left + get_right;

		if (cmax(best_len, get_len)) {
			best_mid = mid;
		}

		FOR(i, 1, N) tcnt[i] = cnt[i];
	}

	assert(~best_mid);

	vector<int> ans;
	ans.pb(best_mid);

	for (int left = best_mid - 1; left >= 1; left--) {
		if (tcnt[left] > 0) {
			tcnt[left]--;
			ans.pb(left);
		}
	}

	reverse(ALL(ans));

	for (int right = best_mid - 1; right >= 1; right--) {
		if (tcnt[right] > 0) {
			tcnt[right]--;
			ans.pb(right);
		}
	}

	assert(sz(ans) == best_len);

	cout << best_len << "\n";
	for (int x : ans)
		cout << x << " ";
	cout << "\n";
}
