class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            long long x=target-nums[i];
            if(mp.find(x)==mp.end()){
                mp[nums[i]]=i;
            }
            else{
                return {i,mp[x]};
            }
        }
        return {-1,-1};
    }
};