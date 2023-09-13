class Solution {
public:
    int subtractProductAndSum(int n) {
        int num = n;
        int sum = 0;
        int prod = 1;
        while(num != 0)
        {
            int a = num%10;
            sum += a;
            prod *= a;
            num = num/10;
        }
        return prod-sum;
    }
};