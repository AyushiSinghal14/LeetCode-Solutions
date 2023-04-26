/*

    Time Complexity : O(N^2), where N is the size of the array(nums). As we check for possible pair, and the
    total number of pairs are : N*(N–1)/2.

    Space complexity : O(1), Constant space.

    Using Array(Two Nested Loop). Brute Force Approach.

    Note : this will give TLE.

*/


/***************************************** Approach 1 *****************************************/
/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] == nums[j]){
                    return ture;
                }
            }
        }
        return false;
    }
};

*/




/*

    Time Complexity : O(NlogN), Sorting creates the time complexity. Where N is the size of the array(nums).

    Space complexity : O(1), Constant space.

    Using Array + Sorting. Brute Better Approach.

*/


/***************************************** Approach 2 *****************************************/
/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }
};
*/





/*

    Time Complexity : O(N), Here loop creates the time complexity. Where N is the size of the array(nums).

    Space complexity : O(N), Hash Table(unordered map) space.

    Using Array + Hash Table. Optimized Approach.

*/


/***************************************** Approach 3 *****************************************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<long,long> map;   
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]] > 1){
                return true;
            }
        }
        return false;
    }
};