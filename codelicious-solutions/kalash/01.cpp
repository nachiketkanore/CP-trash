/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

/*/---------------------------IO(Debugging)----------------------/*/

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
istream& operator>>(istream& is, T_container& v) {
	for (T& x : v)
		is >> x;
	return is;
}
#ifdef __SIZEOF_INT128__
ostream& operator<<(ostream& os, __int128 const& value) {
	static char buffer[64];
	int index = 0;
	__uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
	if (value < 0)
		os << '-';
	else if (T == 0)
		return os << '0';
	for (; T > 0; ++index) {
		buffer[index] = static_cast<char>('0' + (T % 10));
		T /= 10;
	}
	while (index > 0)
		os << buffer[--index];
	return os;
}
istream& operator>>(istream& is, __int128& T) {
	static char buffer[64];
	is >> buffer;
	size_t len = strlen(buffer), index = 0;
	T = 0;
	int mul = 1;
	if (buffer[index] == '-')
		++index, mul *= -1;
	for (; index < len; ++index)
		T = T * 10 + static_cast<int>(buffer[index] - '0');
	T *= mul;
	return is;
}
#endif

template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream& os, const T_container& v) {
	os << '{';
	string sep;
	for (const T& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <class P, class Q = vector<P>, class R = less<P>> ostream& operator<<(ostream& out, priority_queue<P, Q, R> const& M) {
	static priority_queue<P, Q, R> U;
	U = M;
	out << "{ ";
	while (!U.empty())
		out << U.top() << " ", U.pop();
	return (out << "}");
}
template <class P> ostream& operator<<(ostream& out, queue<P> const& M) {
	static queue<P> U;
	U = M;
	out << "{";
	string sep;
	while (!U.empty()) {
		out << sep << U.front();
		sep = ", ";
		U.pop();
	}
	return (out << "}");
}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args) {
	int count_open = 0, len = 1;
	for (int k = 1;; ++k) {
		char cur = *(names + k);
		count_open += (cur == '(' ? 1 : (cur == ')' ? -1 : 0));
		if (cur == ',' && count_open == 0) {
			const char* comma = names + k;
			cerr.write(names, len) << " : " << arg1 << " | ";
			__f(comma + 1, args...);
			return;
		}
		len = (cur == ' ' ? len : k + 1);
	}
}
#else
#define trace(...) 1
#endif

/*/---------------------------RNG----------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN, long long r = LLONG_MAX) {
	uniform_int_distribution<int64_t> generator(l, r);
	return generator(rng);
}
struct custom_hash {						 // Credits: https://codeforces.com/blog/entry/62393
	static uint64_t splitmix64(uint64_t x) { // http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
	template <typename L, typename R> size_t operator()(pair<L, R> const& Y) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
	}
};

/*/---------------------------Defines----------------------/*/
#define endl "\n"
#define all(v) (v).begin(), (v).end()

template <const int MOD> struct modular_int {
	int x;
	static vector<int> inverse_list;
	const static int inverse_limit;
	const static bool is_prime;
	modular_int() {
		x = 0;
	}
	template <typename T> modular_int(const T z) {
		x = (z % MOD);
		if (x < 0)
			x += MOD;
	}
	modular_int(const modular_int<MOD>* z) {
		x = z->x;
	}
	modular_int(const modular_int<MOD>& z) {
		x = z.x;
	}
	modular_int operator-(const modular_int<MOD>& m) const {
		modular_int<MOD> U;
		U.x = x - m.x;
		if (U.x < 0)
			U.x += MOD;
		return U;
	}
	modular_int operator+(const modular_int<MOD>& m) const {
		modular_int<MOD> U;
		U.x = x + m.x;
		if (U.x >= MOD)
			U.x -= MOD;
		return U;
	}
	modular_int& operator-=(const modular_int<MOD>& m) {
		x -= m.x;
		if (x < 0)
			x += MOD;
		return *this;
	}
	modular_int& operator+=(const modular_int<MOD>& m) {
		x += m.x;
		if (x >= MOD)
			x -= MOD;
		return *this;
	}
	modular_int operator*(const modular_int<MOD>& m) const {
		modular_int<MOD> U;
		U.x = (x * 1ull * m.x) % MOD;
		return U;
	}
	modular_int& operator*=(const modular_int<MOD>& m) {
		x = (x * 1ull * m.x) % MOD;
		return *this;
	}
	template <typename T> friend modular_int operator+(const T& l, const modular_int<MOD>& p) {
		return (modular_int<MOD>(l) + p);
	}
	template <typename T> friend modular_int operator-(const T& l, const modular_int<MOD>& p) {
		return (modular_int<MOD>(l) - p);
	}
	template <typename T> friend modular_int operator*(const T& l, const modular_int<MOD>& p) {
		return (modular_int<MOD>(l) * p);
	}
	template <typename T> friend modular_int operator/(const T& l, const modular_int<MOD>& p) {
		return (modular_int<MOD>(l) / p);
	}

	int value() const {
		return x;
	}

	modular_int operator^(const modular_int<MOD>& cpower) const {
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);
		int power = cpower.x;

		if (curr.x <= 1) {
			if (power == 0)
				curr.x = 1;
			return curr;
		}
		while (power > 0) {
			if (power & 1) {
				ans *= curr;
			}
			power >>= 1;
			if (power)
				curr *= curr;
		}
		return ans;
	}

	modular_int operator^(long long power) const {
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);
		if (curr.x <= 1) {
			if (power == 0)
				curr.x = 1;
			return curr;
		}
		// Prime Mods
		if (power >= MOD && is_prime) {
			power %= (MOD - 1);
		}

		while (power > 0) {
			if (power & 1) {
				ans *= curr;
			}
			power >>= 1;
			if (power)
				curr *= curr;
		}
		return ans;
	}

	modular_int operator^(int power) const {
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);

		if (curr.x <= 1) {
			if (power == 0)
				curr.x = 1;
			return curr;
		}
		while (power > 0) {
			if (power & 1) {
				ans *= curr;
			}
			power >>= 1;
			if (power)
				curr *= curr;
		}
		return ans;
	}

	template <typename T> modular_int& operator^=(T power) {
		modular_int<MOD> res = (*this) ^ power;
		x = res.x;
		return *this;
	}

	template <typename T> modular_int pow(T x) {
		return (*this) ^ x;
	}

	pair<long long, long long> gcd(const int a, const int b) const {
		if (b == 0)
			return { 1, 0 };
		pair<long long, long long> c = gcd(b, a % b);
		return { c.second, c.first - (a / b) * c.second };
	}

	inline void init_inverse_list() const {

		vector<int>& dp = modular_int<MOD>::inverse_list;
		dp.resize(modular_int<MOD>::inverse_limit + 1);
		int n = modular_int<MOD>::inverse_limit;
		dp[0] = 1;
		if (n > 1)
			dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			dp[i] = (dp[MOD % i] * 1ull * (MOD - MOD / i)) % MOD;
		}
	}
	modular_int<MOD> get_inv() const {
		if (modular_int<MOD>::inverse_list.size() < modular_int<MOD>::inverse_limit + 1)
			init_inverse_list();

		if (this->x <= modular_int<MOD>::inverse_limit) {
			return modular_int<MOD>::inverse_list[this->x];
		}
		pair<long long, long long> G = gcd(this->x, MOD);
		return modular_int<MOD>(G.first);
	}
	modular_int<MOD> operator-() const {
		modular_int<MOD> v(0);
		v -= (*this);
		return v;
	}
	modular_int operator/(const modular_int<MOD>& m) const {
		modular_int<MOD> U(this);
		U *= m.get_inv();
		return U;
	}
	modular_int& operator/=(const modular_int<MOD>& m) {
		(*this) *= m.get_inv();
		return *this;
	}
	bool operator==(const modular_int<MOD>& m) const {
		return x == m.x;
	}

	bool operator<(const modular_int<MOD>& m) const {
		return x < m.x;
	}

	template <typename T> bool operator==(const T& m) const {
		return (*this) == (modular_int<MOD>(m));
	}

	template <typename T> bool operator<(const T& m) const {
		return x < (modular_int<MOD>(m)).x;
	}
	template <typename T> bool operator>(const T& m) const {
		return x > (modular_int<MOD>(m)).x;
	}
	template <typename T> friend bool operator==(const T& x, const modular_int<MOD>& m) {
		return (modular_int<MOD>(x)).x == m.x;
	}
	template <typename T> friend bool operator<(const T& x, const modular_int<MOD>& m) {
		return (modular_int<MOD>(x)).x < m.x;
	}
	template <typename T> friend bool operator>(const T& x, const modular_int<MOD>& m) {
		return (modular_int<MOD>(x)).x > m.x;
	}

	friend istream& operator>>(istream& is, modular_int<MOD>& p) {
		int64_t val;
		is >> val;
		p.x = (val % MOD);
		if (p.x < 0)
			p.x += MOD;
		return is;
	}
	friend ostream& operator<<(ostream& os, const modular_int<MOD>& p) {
		return os << p.x;
	}
};

const int mod = 1000000007;

using mint = modular_int<mod>;
template <const int MOD> vector<int> modular_int<MOD>::inverse_list;
template <const int MOD> const int modular_int<MOD>::inverse_limit = -1;
template <const int MOD> const bool modular_int<MOD>::is_prime = true;
template <> //-> useful if computing inverse fact = i_f[i-1] / i;
const int modular_int<mod>::inverse_limit = 100500;

/*/-----------------------------Code begins----------------------------------/*/

const int N = 100500;

mint fact[N], inv_fact[N];

void preprocess() {
	fact[0] = 1;
	inv_fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = fact[i - 1] * i;
		inv_fact[i] = inv_fact[i - 1] / i;
		assert((fact[i] * inv_fact[i]) == 1);
	}
}

mint ncr(int n, int r) {
	if (n < 0 || n < r || r < 0)
		return 0;
	return fact[n] * inv_fact[r] * inv_fact[n - r];
}
void solve() {
	int k, m;
	cin >> k >> m;
	assert(k < N && m < N);
	mint ans = ncr(m, k) * ncr(k - 1, (k >> 1));
	cout << ans << endl;
}

int main() {
	// Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with
	// unordered set Or use gp_hash_table<X,null_type>
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed << setprecision(25);
	cerr << fixed << setprecision(10);
	auto start = std::chrono::high_resolution_clock::now();
	preprocess();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	// cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
}
