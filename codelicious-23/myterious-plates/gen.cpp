#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int inf = 1e18;

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline int rand(int l, int r) {
	std::uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void ARRAY(int n, int L, int R) {
	cout << n << '\n';
	FOR(i, 1, n) {
		cout << rand(L, R) << " \n"[i == n];
	}
}

void STRING(int n, char from, char to) {
	assert(from <= to);
	int L = from - 'a';
	int R = to - 'a';
	assert(L <= R);

	cout << n << '\n';
	FOR(i, 1, n) {
		char ch = (char)('a' + rand(L, R));
		cout << ch;
	}
	cout << '\n';
}

void TREE(int n) {
	cout << n << '\n';

	vector<pair<int, int>> edges;
	for (int i = 2; i <= n; ++i) {
		edges.emplace_back(rand(1, i - 1), i);
	}

	vector<int> perm(n + 1); // re-naming vertices
	for (int i = 1; i <= n; ++i) {
		perm[i] = i;
	}
	shuffle(perm.begin() + 1, perm.end(), rng);

	shuffle(edges.begin(), edges.end(), rng); // random order of edges

	for (pair<int, int> edge : edges) {
		int a = edge.first, b = edge.second;
		if (rand() % 2) {
			swap(a, b); // random order of two vertices
		}
		cout << perm[a] << ' ' << perm[b] << '\n';
	}
}

void QUERIES(int Q, int L, int R) {
	cout << Q << "\n";
	while (Q--) {
		int QL = rand(L, R);
		int QR = rand(L, R);
		if (QL > QR)
			swap(QL, QR);
		cout << QL << " " << QR << "\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T = 20;
	cout << T << '\n';
	FOR(TC, 1, T) {
		int N = rand(1, 1000), K = rand(1, 500);
		cout << N << ' ' << K << '\n';
		FOR(i, 1, N) cout << rand(1, 500) << " \n"[i == N];
	}
}
