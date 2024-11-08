const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
const int mod = 1000000007;

int binpow(int a, int b) {
	a %= mod;
	int res = 1;
	while (b) {
		if (b & 1)
			res = (res * 1ll * a) % mod;
		a = (a * 1ll * a) % mod;
		b >>= 1;
	}
	return res;
}
int fact[3001];
int invfact[3001];
void prefact() {
	for (int i = 0; i <= 3000; i++)fact[i] = 1, invfact[i] = 1;
	for (int i = 2; i <= 3000; i++) {
		fact[i] = (i * 1ll * fact[i - 1]) % mod;
		invfact[i] = fact[i];
	}
	for (int i = 2; i <= 3000; ++i)
	{
		invfact[i] = binpow(invfact[i], mod - 2);
	}
}
bool precompute = 0;
class Solution {
public:
	int makeStringSorted(string s) {
		if (!precompute) {
			prefact();
			precompute = true;
		}
		int n = s.length();
		vector<int>pre_sum(26);
		for (int i = 0; i < n; i++) {
			pre_sum[s[i] - 'a']++;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			long long cur = fact[n - i - 1];
			int cnt_smaller = 0;
			for (int j = 0; j < 26; j++) {
				if (j < (s[i] - 'a')) {
					cnt_smaller += pre_sum[j];
				}
				cur *= invfact[pre_sum[j]];
                cur %= mod;
			}
			cur *= cnt_smaller;
			cur %= mod;
			ans += cur;
			ans %= mod;
			pre_sum[s[i] - 'a']--;
		}
		return ans;
	}
};
