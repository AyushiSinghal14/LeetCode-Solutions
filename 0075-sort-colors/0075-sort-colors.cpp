class Solution {
public:
    void sortColors(vector<int>& nums) {
    int index=0;
    int zero=0,one=0,two=0;
    for(int i=0;i<size(nums);i++)
    { if(nums[i]==0)zero++;
      if(nums[i]==1)one++;
      if(nums[i]==2)two++;
        }
        while(zero!=0)
        {
          nums[index++]=0;
          zero--;
        }
        while(one!=0)
        {
          nums[index++]=1;
          one--;
        }
        while(two!=0)
        {
          nums[index++]=2;
          two--;
        }

    }
};