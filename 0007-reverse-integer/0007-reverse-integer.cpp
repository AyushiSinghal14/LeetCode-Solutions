class Solution {
public:
    int reverse(int x) {
        // int ans = 0;
        // while (x != 0)
        // {
        //     int digit = x%10;
        //     ans = (ans*10)+digit;
        //     x = x/10;
        // }
        // return ans;
        
        // (in the above code, there is some value which becomes bigger than the range of integer after multiplying it with 10. this is why we need to specify the range on the basis of condition)
    
        int ans = 0;
        while(x != 0)
        {
            int digit = x%10;
            if((ans > INT_MAX/10) || (ans < INT_MIN/10))
            {
                return 0;
            }
            ans = (ans*10)+digit;
            x = x/10;
            
        }
        return ans;
    }
};