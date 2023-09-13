class Solution {
public:
    int hammingWeight(uint32_t n) {
        // int num = n;
        int count = 0;
        
        while(n != 0)
        {
            // int a = num%10;
            if(n&1)
            {
                count++;
            }
            n = n>>1;
        }
        return count;
    }
};