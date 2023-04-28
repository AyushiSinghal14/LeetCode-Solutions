class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i, temp;
        int low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(mid==0 || mid==n-1){
                low=mid;
                break;
            }
            if(nums[mid-1]>nums[mid] && nums[mid+1]>nums[mid]){
                low=mid;
                break;
            }
            else if(nums[mid]>nums[low] && nums[mid]>nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        temp=low;
        low=0, high=n-1;
        if(target==nums[temp]){
            return temp;
        }
        else if(target>nums[high]){
            high=temp-1;
        }
        else if(target<nums[low]){
            low=temp+1;
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(target>nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};