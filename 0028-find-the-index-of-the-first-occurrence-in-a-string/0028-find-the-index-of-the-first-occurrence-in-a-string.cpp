class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans=-1;
        int k=0;  
        int niddilesize=needle.size();
        while(k<haystack.size()){
        auto itr=find(haystack.begin()+k,haystack.end(),needle[0]);
        int n=itr-haystack.begin();
        string str=haystack.substr(n,niddilesize);
        if(str==needle){
           ans=n; 
            break;
        }
       else 
           k=k+1;
           continue;
         }
        if(ans==-1)
            return -1;
        else
            return ans;
    }
};