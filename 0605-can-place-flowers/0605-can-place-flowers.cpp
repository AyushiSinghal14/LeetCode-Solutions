class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        //Put 0 at the beginning and at the end of the array
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        int cnt=0;

        //For each plot we check adjacent plots are empty
        //and if condition satisfied we plot the flower and increase the count
        for(int i=1; i<flowerbed.size()-1; i++)
        {
            if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]==0)
            {
                cnt++;
                flowerbed[i]=1;
            }
        }
        if(cnt>=n) return true;
        return false;        
    }
};