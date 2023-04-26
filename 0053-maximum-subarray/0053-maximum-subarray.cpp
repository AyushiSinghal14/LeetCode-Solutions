class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //KADANE'S ALGO
        int sum = 0;
        int maxi = INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i]; //updating current sum by adding current element
            maxi = max(maxi, sum); //checking whether the sum obtained is greater than the sum or not
            if(sum<0)   //if the sum is negative then it is not required to be counted, thus making sum value to 0
            {
                sum=0;
            }
        }
        return maxi;
    }
};