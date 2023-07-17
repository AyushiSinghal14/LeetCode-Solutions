//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans = "";
        int n = A.length();
        
        vector<vector<int>> f(26, vector<int>(2));
        
        for (int i = 0; i < n; i++)
        {
            char ch = A[i];
            f[ch - 'a'][0]++;
            f[ch - 'a'][1] = i;
            
            int res_ch = -1;
            int min_idx = INT_MAX;
            
            for (int j = 0; j < 26; j++) {
                if (f[j][0] == 1 && f[j][1] < min_idx) {
                    min_idx = f[j][1];
                    res_ch = j;
                }
            }
            
            if (res_ch == -1) {
                ans += '#';
            } else {
                ans += (char)(res_ch + 'a');
            }
        }
        
        return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends