class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x1 = 0, x2 = 0;
        for(auto it: arr1) x1 ^= it;
        for(auto it: arr2) x2 ^= it;

        return x1&x2;
    }
};