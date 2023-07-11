class Solution {
public:
    bool isPowerOfTwo(int n) {
        
    //30 is because the range of integer values is uptil 2^31 - 1 and 31 will not be considered because 1 is subtracted from it
        
        for(int i = 0; i <= 30; i++)
        {
            int ans = pow(2,i);
            
            if(ans == n)
            {
                return true;
            }
        }
        
        return false;
    }
};
