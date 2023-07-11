class Solution {
public:
    bool isPowerOfTwo(int n) {
        
    //30 is because the range of integer values is uptil 2^31 - 1 and 31 will not be considered because 1 is subtracted from it
        
        //BRUTE FORCE
        
//         for(int i = 0; i <= 30; i++)
//         {
//             int ans = pow(2,i);
            
//             if(ans == n)
//             {
//                 return true;
//             }
//         }
        
//         return false;
        
        
        //OPTIMIZED APPROACH
        
        // int temp = 1;
        // while(n != temp && temp < INT_MAX/2)
        // {
        //     temp*=2;
        // }
        // return n == temp;
        
        
        //MOST EFFICIENT APPROACH
        
        if(n<=0)
        {
            return false;
        }
        return (n & (n-1)) == 0;
    }
};
