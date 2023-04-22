class Solution {
public:

    int minInsertions(string s) {
        int n = s.size();
        int dp[n], prev, ans;
        for(int l = n - 1; l >= 0; l--) {
            dp[l] = 0;
            if(l + 1 < n)prev = dp[l + 1], dp[l + 1] = (s[l] != s[l + 1]);
            for(int r = l + 2; r < n; r++) {
                ans = min(dp[r - 1], dp[r]) + 1;
                if(s[l] == s[r]) ans = min(ans, prev);
                prev = dp[r];
                dp[r] = ans;
            }
        }
        return dp[n - 1];
    }
};